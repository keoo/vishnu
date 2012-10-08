/**
 * \file SOCITemporaryTypes.cpp
 * \brief This file implements temporary types used by SOCI session.
 * \author Jean-Baptiste Ghoul (jean-baptiste.ghoul@sysfera.com)
 * \date 05/07/12
 */

#include "SOCITemporaryType.hpp"
#include "SystemException.hpp"

using namespace std;
using namespace soci;

#ifndef TRYCATCH
#define TRYCATCH(a,b) \
	try { (a); } \
	catch (std::exception const & e) { \
	throw SystemException(ERRCODE_DBERR,std::string(b)+e.what());}
#endif

/*
 * Class temporary_type
 */
/**
 * \brief constructor from an existing session
 */
SOCITemporaryType::SOCITemporaryType(SOCISession & session)
	:nbUses(0),nbIntos(0),msession(session)
{
	once = new soci::details::once_temp_type(session.getAdvanced());
}
/**
 * \brief copy constructor
 */
SOCITemporaryType::SOCITemporaryType(const SOCITemporaryType & other)
		:once(other.once),nbUses(other.nbUses),nbIntos(other.nbIntos),msession(other.msession)
{}
/**
 * the request was executed on the destructor of the last reference to the temporary type
 * \return raises an VishnuException in case of error
 */
SOCITemporaryType::~SOCITemporaryType()
{
	string tmp;
	if(nbIntos==0) {
		(*once),soci::into(tmp);
	}
	try {
		delete once;
	}
	catch (std::exception const & e) {
		if( msession.isAutoCommit() ) {
			msession.rollback();
		}
		if( msession.isSingleExecution() ) {
			msession.release();
		}
		throw SystemException(ERRCODE_DBERR,std::string("Failed to execute query \n")+e.what());
	}

	if( msession.isAutoCommit() ) {
		msession.commit();
	}
	if( msession.isSingleExecution() ) {
		msession.release();
	}
}

SOCITemporaryType &
SOCITemporaryType::exchange(details::use_type_ptr const & in)
{
	TRYCATCH(((*once),in), "")
	nbUses++;
	return *this;
}

SOCITemporaryType &
SOCITemporaryType::exchange(details::into_type_ptr const & out)
{
	TRYCATCH(((*once),out), "")
	nbIntos++;
	return *this;
}

SOCITemporaryType &
SOCITemporaryType::operator ,(details::use_type_ptr const & in)
{
	return exchange(in);
}

SOCITemporaryType &
SOCITemporaryType::operator ,(details::into_type_ptr const & out)
{
	return exchange(out);
}
