#include "SociDatabase.hpp"
#include <boost/format.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <string>
#include <vector>
#include "SystemException.hpp"
#include "utilVishnu.hpp"

typedef std::vector<std::string> Row;
typedef std::vector<Row> Results;
typedef std::map<int, boost::shared_ptr<soci::transaction> > Transactions;

SociDatabase::SociDatabase(DbConfiguration dbConfig)
  : Database(), mconfig(dbConfig) {

  DbConfiguration::db_type_t dbType = mconfig.getDbType();
  const std::string& dbName = mconfig.getDbName();
  const std::string& dbUser = mconfig.getDbUserName();
  const std::string& dbPassword = mconfig.getDbUserPassword();
  int dbPort = mconfig.getDbPort();
  int poolSz = mconfig.getDbPoolSize();
  pool_.reset(new soci::connection_pool(poolSz));

  boost::format fmtr("%1%://db=%2% port=%3% user=%4% password=%5%");
  switch (dbType) {
  case DbConfiguration::POSTGRESQL:
    fmtr % "postgresql" % dbName % dbPort % dbUser % dbPassword;
    break;
  case DbConfiguration::MYSQL:
    fmtr % "mysql" % dbName % dbPort % dbUser % dbPassword;
    break;
  }

  uri_ = fmtr.str();
}


int
SociDatabase::process(std::string request, int transacId) {
  using boost::algorithm::ends_with;
  if (request.empty()) {
    throw SystemException(ERRCODE_DBERR, "Empty SQL query");
  }

  if (ends_with(request, ";")) {
    request.append(";");
  }

  boost::unique_lock<boost::mutex> lock(m_);
  int pos(0);
  if (-1 == transacId) {
    // get an available connection
    pos = pool_->lease();
  } else {
    pos = transacId;
  }

  soci::session& conn = pool_->at(pos);
  conn.open(uri_);
  conn.once << request;
}

DatabaseResult*
SociDatabase::getResult(std::string request, int transacId) {
  using boost::algorithm::ends_with;
  using boost::lexical_cast;

  if (request.empty()) {
    throw SystemException(ERRCODE_DBERR, "Empty SQL query");
  }

  if (ends_with(request, ";")) {
    request.append(";");
  }

  boost::unique_lock<boost::mutex> lock(m_);
  int pos(0);
  if (-1 == transacId) {
    // get an available connection
    pos = pool_->lease();
  } else {
    pos = transacId;
  }

  soci::session& conn = pool_->at(pos);
  conn.open(uri_);
  soci::rowset<soci::row> rs (conn.prepare << request);
  Results res;
  soci::rowset<soci::row>::const_iterator it = rs.begin();

  if (!conn.got_data()) {
    throw SystemException(ERRCODE_DBERR, "Cannot get query results");
  }

  // get columns names
  std::vector<std::string> attrNames;
  for (int i = 0; i != it->size(); ++i) {
    const soci::column_properties & props = it->get_properties(i);
    attrNames.push_back(props.get_name());
  }

  // get results
  for (; it != rs.end(); ++it) {
    Row r;
    for (int i = 0; i != it->size(); ++i) {
      const soci::column_properties & props = it->get_properties(i);
      switch (props.get_data_type()) {
      case soci::dt_date:
	// FIXME: receive a std::tm what should we do ?
	break;
      case soci::dt_integer:
	r.push_back(lexical_cast<std::string>(it->get<int>(i)));
	break;
      case soci::dt_unsigned_long:
	r.push_back(lexical_cast<std::string>(it->get<unsigned long>(i)));
	break;
      case soci::dt_long_long:
	r.push_back(lexical_cast<std::string>(it->get<long long>(i)));
	break;
      case soci::dt_string:
	r.push_back(it->get<std::string>(i));
      default:
	// FIXME
	break;
      }
    }
    res.push_back(r);
  }

  // this is ugly, we should return a smart pointer instead
  return new DatabaseResult(res, attrNames);
}

int
SociDatabase::startTransaction() {
  boost::unique_lock<boost::mutex> lock(m_);
  int id = pool_->lease();
  soci::session& conn = pool_->at(id);
  boost::shared_ptr<soci::transaction> tr(new soci::transaction(conn));
  trs_[id] = tr;
  return id;
}


void
SociDatabase::endTransaction(int transactionID) {
  Transactions::iterator it = trs_.find(transactionID);

  if (trs_.end() != it) {
    boost::shared_ptr<soci::transaction> tr = it->second;
    tr->commit();
    trs_.erase(it);
  }
}

void
SociDatabase::cancelTransaction(int transactionID) {
  Transactions::iterator it = trs_.find(transactionID);

  if (trs_.end() != it) {
    boost::shared_ptr<soci::transaction> tr = it->second;
    tr->rollback();
    trs_.erase(it);
  }
}

void
SociDatabase::flush(int transactionID) {
  endTransaction(transactionID);
}

DbConfiguration::db_type_t
SociDatabase::getDbType() {
  return mconfig.getDbType();
}


// does nothing since it's not used
int
SociDatabase::connect() { return 0; }

int
SociDatabase::disconnect() { return 0; }

int
SociDatabase::generateId(std::string table, std::string fields,
                         std::string val, int tid) {
  boost::format fmtr("INSERT INTO %1 %2 values %3%; %4%");
  fmtr % table % fields % val;
  switch (getDbType()) {
  case DbConfiguration::MYSQL:
    fmtr % "SELECT LAST_INSERT_ID() FROM vishnu";
    break;
  case DbConfiguration::POSTGRESQL:
    fmtr % "SELECT currval(pg_get_serial_sequence('vishnu', 'vishnuid'))";
    break;
  }

  std::vector<std::string> results;
  std::vector<std::string>::iterator iter;
  try {
    boost::scoped_ptr<DatabaseResult> res(getResult(fmtr.str(), tid));

    if (0 == res->getNbTuples()) {
      throw SystemException(ERRCODE_DBERR, "Failure generating the id");
    }
    results.clear();
    results = res->get(0);
    iter = results.begin();
  } catch (SystemException& e){
    throw (e);
  }

  return vishnu::convertToInt(*iter);
}

