/**
 * \file SOCISession.cpp
 * \brief This file implements the SOCI session.
 * \author Jean-Baptiste Ghoul (jean-baptiste.ghoul@sysfera.com)
 * \date 03/07/12
 */

#include "SOCISession.hpp"

using namespace std;
using namespace soci;
/*
 * \brief default constructor
 */
SOCISession::SOCISession()
	: msession(NULL)
{}
/*
 * \brief copy constructor
 */
SOCISession::SOCISession(const SOCISession & s)
	: msession(s.msession),pool_position(s.pool_position)
{

}
/*
 * \brief constructor with existing soci session
 */
SOCISession::SOCISession(soci::session* asession, size_t pos)
	: msession(asession),pool_position(pos)
{}

SOCISession::~SOCISession()
{

}



/*
 * public functions
 */
void SOCISession::process(std::string request)
{
	std::vector<std::vector<std::string> > results;
	std::vector<std::string> attributeNames;

	try
	{
		(msession->once) << request;
	} catch (std::exception const & e)
	{
		throw SystemException(ERRCODE_DBERR,
				std::string("Cannot get query result : \n") + e.what());
	}
	return;
}



void SOCISession::begin()
{
	TRYCATCH(msession->begin(),"Cannot begin transaction");
}
void SOCISession::commit()
{
	try
	{
		msession->commit();
	}
	catch (exception & e)
	{
		throw SystemException(ERRCODE_DBERR,
				std::string("Cannot commit transaction : \n") + e.what());
	}
}
void SOCISession::rollback()
{
	try
	{
		msession->rollback();
	}
	catch (exception & e)
	{
		throw SystemException(ERRCODE_DBERR,
				std::string("Cannot commit transaction : \n") + e.what());
	}
}

SOCIStatement SOCISession::getStatement()
{
	return SOCIStatement(*this);
}
