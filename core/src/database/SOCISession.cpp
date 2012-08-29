/**
 * \file SOCISession.cpp
 * \brief This file implements the SOCI session.
 * \author Jean-Baptiste Ghoul (jean-baptiste.ghoul@sysfera.com)
 * \date 03/07/12
 */

#include "SOCISession.hpp"
#include "SOCITemporaryType.hpp"


using namespace std;
using namespace soci;



/*
 * class SOCISession
 */

/*
 * \brief default constructor
 */
SOCISession::SOCISession()
	: msession(NULL),autoCommit(true),singleExecution(false),mpool(NULL)
{}
/*
 * \brief copy constructor
 */
SOCISession::SOCISession(const SOCISession & s)
	: msession(s.msession),pool_position(s.pool_position),autoCommit(s.autoCommit),
	  singleExecution(s.singleExecution),mpool(s.mpool)
{

}
/*
 * \brief constructor with existing soci session
 */
SOCISession::SOCISession(soci::session* asession, const size_t pos,
		connection_pool * apool, bool isAutoCommit)
	: msession(asession),pool_position(pos),autoCommit(isAutoCommit),
	  singleExecution(false),mpool(apool)
{}

SOCISession::~SOCISession()
{

}



/*
 * public functions
 */

SOCITemporaryType
SOCISession::execute(std::string const & query)
{
	if(msession==NULL) {
		throw SystemException(ERRCODE_DBERR,"Cannot execute : session is null");
	}
	std::string request=query;
	// SOCI for ORACLE does not support semi-colom
	while (msession->get_backend_name()=="oracle" && query[query.length()-1] == ';') {
		request.erase(request.length()-1,1);
	}

	if( request.empty() ) {
		throw SystemException(ERRCODE_DBERR,"Empty SQL request");
	}

	if (autoCommit) {
		begin();
		/* The transaction just started above is only for this execution
		 * We have to stay in autoCommit mode, because the SOCITemporyType
		 * should know that he must commit the transaction.
		 */
		autoCommit = true;
	}
	SOCITemporaryType ret(*this);
	TRYCATCH( ret.once<<request, "")
	return ret;
}

SOCITemporaryType
SOCISession::operator<<(std::string const & query)
{
	return execute(query);
}

SOCITemporaryType
SOCISession::executeOnce(std::string const & query) {
	singleExecution = true;
	return execute(query);
}


void
SOCISession::begin()
{
	if(msession==NULL) {
		throw SystemException(ERRCODE_DBERR,"Cannot begin : session is null");
	}
	TRYCATCH(msession->begin(),"Cannot begin transaction \n");
	autoCommit = false;
}
void
SOCISession::commit()
{
	if(msession==NULL) {
		throw SystemException(ERRCODE_DBERR,"Cannot commit : session is null");
	}
	try	{
		msession->commit();
	}
	catch (exception & e)	{
		throw SystemException(ERRCODE_DBERR,
				std::string("Cannot commit transaction : \n") + e.what());
	}
	autoCommit = true;
}
void
SOCISession::rollback()
{
	if(msession==NULL) {
		throw SystemException(ERRCODE_DBERR,"Cannot rollback : session is null");
	}
	try
	{
		msession->rollback();
	}
	catch (exception & e)
	{
		throw SystemException(ERRCODE_DBERR,
				std::string("Cannot commit transaction : \n") + e.what());
	}
	autoCommit = true;
}

SOCIStatement
SOCISession::getStatement()
{
	if(msession==NULL) {
		throw SystemException(ERRCODE_DBERR,"Cannot get statement : session is null");
	}
	return SOCIStatement(*this);
}

bool
SOCISession::gotData()
{
	if(msession==NULL) {
		throw SystemException(ERRCODE_DBERR,"session is null");
	}
	bool ret;
	TRYCATCH(ret=msession->got_data(),"")
	return ret;
}


soci::session &
SOCISession::getAdvanced()
{
	if(msession==NULL) {
		throw SystemException(ERRCODE_DBERR,"session is null");
	}
	return *msession;
}
/**
 * \brief get the pool position where the session is from
 */
size_t
SOCISession::getPoolPosition()
{
	if(msession==NULL) {
		throw SystemException(ERRCODE_DBERR,"session is null");
	}
	return pool_position;
}

bool
SOCISession::isAutoCommit() {
	return autoCommit;
}

bool
SOCISession::isSingleExecution() {
	return singleExecution;
}

void
SOCISession::release() {
	try {
		mpool->give_back(pool_position);
	}
	catch (exception const & e) {
		throw SystemException(ERRCODE_DBERR,string("Cannot release session : ")+e.what());
	}
	*this=SOCISession();
}
