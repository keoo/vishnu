#ifndef _SOCIDATABASE_HPP_
#define _SOCIDATABASE_HPP_

#include <map>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <soci/soci.h>
#include <soci/transaction.h>
#include <Database.hpp>
#include <DbConfiguration.hpp>

class SociDatabase : public Database {
public:
  SociDatabase(DbConfiguration dbConfig);

  int
  process(std::string request, int transacId = -1);

  int
  connect();

  int
  disconnect();

  DatabaseResult*
  getResult(std::string request, int transacId = -1);

  DbConfiguration::db_type_t
  getDbType();

  int
  startTransaction();

  void
  endTransaction(int transactionID);

  void
  cancelTransaction(int transactionID);

  void
  flush(int transactionID);

  int
  generateId(std::string table, std::string fields, std::string val, int tid);

private:
  std::map<int, boost::shared_ptr<soci::transaction> > trs_;
  boost::mutex m_;
  boost::scoped_ptr<soci::connection_pool> pool_;
  std::string uri_;
  DbConfiguration mconfig;
};

#endif /* _SOCIDATABASE_HPP_ */
