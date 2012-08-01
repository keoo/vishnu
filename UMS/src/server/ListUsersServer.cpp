/* This file is a part of VISHNU.

* Copyright SysFera SAS (2011) 

* contact@sysfera.com

* This software is a computer program whose purpose is to provide 
* access to distributed computing resources.
*
* This software is governed by the CeCILL  license under French law and
* abiding by the rules of distribution of free software.  You can  use, 
* modify and/ or redistribute the software under the terms of the CeCILL
* license as circulated by CEA, CNRS and INRIA at the following URL
* "http://www.cecill.info". 

* As a counterpart to the access to the source code and  rights to copy,
* modify and redistribute granted by the license, users are provided only
* with a limited warranty  and the software's author,  the holder of the
* economic rights,  and the successive licensors  have only  limited
* liability. 
*
* In this respect, the user's attention is drawn to the risks associated
* with loading,  using,  modifying and/or developing or reproducing the
* software by the user in light of its specific status of free software,
* that may mean  that it is complicated to manipulate,  and  that  also
* therefore means  that it is reserved for developers  and  experienced
* professionals having in-depth computer knowledge. Users are therefore
* encouraged to load and test the software's suitability as regards their
* requirements in conditions enabling the security of their systems and/or 
* data to be ensured and,  more generally, to use and operate it in the 
* same conditions as regards security. 
*
* The fact that you are presently reading this means that you have had
* knowledge of the CeCILL license and that you accept its terms.
*/

/**
 * \file ListUsersServer.hpp
 * \brief This file contains the VISHNU QueryServer class.
 * \author Daouda Traore (daouda.traore@sysfera.com) and
 *   Eugène PAMBA CAPO-CHICHI (eugene.capochichi@sysfera.com)
 * \date February 2011
 */
#ifndef _QUERY_SERVER_H_
#define _QUERY_SERVER_H_

#include <string>
#include <vector>
#include <iostream>
#include "boost/date_time/posix_time/posix_time.hpp"

#include "ListUsersServer.hpp"
#include "DbFactory.hpp"
#include "utilVishnu.hpp"


/**
 * \fn ListUsersServer(const SessionServer session)
 * \param session The object which encapsulates the session information (ex: identifier of the session)
 * \brief Constructor, raises an exception on error
 */
ListUsersServer::ListUsersServer(const SessionServer& session):
msessionServer(session)
{
   //mlistUsers = NULL;
   DbFactory factory;
   mdatabaseVishnu = factory.getDatabaseInstance();
}

/**
 * \fn ListUsersServer(const std::string& option
 *                     const SessionServer& session)
 * \param option The ListUsersServer option
 * \param session The object which encapsulates the session information (ex: identifier of the session)
 * \brief Constructor, raises an exception on error
 */
ListUsersServer::ListUsersServer(const std::string& option, const SessionServer& session):
moption(option), msessionServer(session)
{
   //mlistUsers = NULL;
   DbFactory factory;
   mdatabaseVishnu = factory.getDatabaseInstance();
}

/**
 * \brief Function to treat the ListUsersServer options
 * \fn void processOptions(UserServer userServer,
 *                         const std::string& options
 *                         std::string& sqlRequest)
 * \param userServer the object which encapsulates user information
 * \param optionsListUsersServer option
 * \param sqlRequest the sql data base request
 * \return raises an exception on error
 */
void ListUsersServer::processOptions(UserServer userServer, const std::string& options, std::string& sqlRequest)
{
  if(!userServer.isAdmin()) {
    UMSVishnuException e (ERRCODE_NO_ADMIN);
    throw e;
  }

  if(options.size()!=0) {
    sqlRequest.append(" and userid=");
    sqlRequest.append("'"+moption+"'");
    boost::scoped_ptr<DatabaseResult> ListofUsers (mdatabaseVishnu->getResult(sqlRequest.c_str()));
    if(ListofUsers->getNbTuples()==0) {
      UMSVishnuException e(ERRCODE_UNKNOWN_USERID);
      throw e ;
    }
  }
}

#if 0


/**
 * \brief Function to list machines information
 * \fn UMS_Data::ListUsers* list()
 * \return The pointer to the UMS_Data::ListUsers containing users information
 * \return raises an exception on error
 */
ListUsers* ListUsersServer::list()
{
  std::string sqlListofUsers = "SELECT userid, pwd, firstname, lastname, privilege, email, status from users "
                              "where not userid='"+ ROOTUSERNAME +"'";

  std::vector<std::string>::iterator ii;
  std::vector<std::string> results;
  UMS_Data::UMS_DataFactory_ptr ecoreFactory = UMS_Data::UMS_DataFactory::_instance();
  mlistUsers = ecoreFactory->createListUsers();

  //Creation of the object user
  UserServer userServer = UserServer(msessionServer);
  userServer.init();
  //if the user exists
  if (userServer.exist()) {

    processOptions(userServer, moption, sqlListofUsers);
    sqlListofUsers.append(" order by userid");
    //To get the list of users from the database
    boost::scoped_ptr<DatabaseResult> ListofUsers (mdatabaseVishnu->getResult(sqlListofUsers.c_str()));
    if (ListofUsers->getNbTuples() != 0){
      for (size_t i = 0; i < ListofUsers->getNbTuples(); ++i) {
        results.clear();
        results = ListofUsers->get(i);
        ii = results.begin();
        UMS_Data::User_ptr user = ecoreFactory->createUser();
        user->setUserId(*ii);
        user->setPassword(*(++ii));
        user->setFirstname(*(++ii));
        user->setLastname(*(++ii));
        user->setPrivilege(convertToInt(*(++ii)));
        user->setEmail(*(++ii));
        user->setStatus(convertToInt(*(++ii)));

        mlistUsers->getUsers().push_back(user);
        }
    }
  }
  else {
    UMSVishnuException e (ERRCODE_UNKNOWN_USER);
    throw e;
  }
  return mlistUsers;
}

#endif


/**
 * \brief Function to list machines information
 * \fn UMS_Data::ListUsers* list()
 * \return The pointer to the UMS_Data::ListUsers containing users information
 * \return raises an exception on error
 */
UMS_Data_Proto::ListUsers ListUsersServer::list()
{
  std::string sqlListofUsers = "SELECT userid, pwd, firstname, lastname, privilege, email, status from users "
                              "where not userid='"+ ROOTUSERNAME +"'";

  std::vector<std::string>::iterator ii;
  std::vector<std::string> results;
  //UMS_Data::UMS_DataFactory_ptr ecoreFactory = UMS_Data::UMS_DataFactory::_instance();
  //mlistUsers = ecoreFactory->createListUsers();
    //mlistUsers=new UMS_Data_Proto::ListUsers;

  //Creation of the object user
  UserServer userServer = UserServer(msessionServer);
  
  userServer.init();
  //if the user exists
  
  if (userServer.exist()) {
 
  processOptions(userServer, moption, sqlListofUsers);
    sqlListofUsers.append(" order by userid");
    //To get the list of users from the database
    boost::scoped_ptr<DatabaseResult> ListofUsers (mdatabaseVishnu->getResult(sqlListofUsers.c_str()));
    if (ListofUsers->getNbTuples() != 0){

      mlistUsers.clear_users();
      for (size_t i = 0; i < ListofUsers->getNbTuples(); ++i) {
        results.clear();
        results = ListofUsers->get(i);
        ii = results.begin();
        UMS_Data_Proto::User* user = mlistUsers.add_users();
        user->set_userid(*ii);
        user->set_password(*(++ii));
        user->set_firstname(*(++ii));
        user->set_lastname(*(++ii));

        std::istringstream iss(*(++ii)) ;
        UMS_Data_Proto::User::PrivilegeType privilege;
        iss >> privilege;
        user->set_privilege(privilege);
        user->set_email(*(++ii));

        std::istringstream iss2(*(++ii)) ;
        UMS_Data_Proto::User::StatusType status;
        iss2 >> status;
        user->set_status(status);
        }
    }
  }
  else {
    UMSVishnuException e (ERRCODE_UNKNOWN_USER);
    throw e;
  }
  return mlistUsers;
}




/**
 * \fn ~ListUsersServer()
 * \brief Destructor, raises an exception on error
 */
ListUsersServer::~ListUsersServer()
{
}

#endif
