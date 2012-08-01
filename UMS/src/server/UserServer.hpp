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
* \file UserServer.hpp
* \brief This file presents the Class which manipulates VISHNU user data on server side.
* \author Eugène PAMBA CAPO-CHICHI (eugene.capochichi@sysfera.com)
* \date 31/01/2011
*/

#ifndef USER_SERVER_H
#define USER_SERVER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <exception>
#include "UMSVishnuException.hpp"
#include "Database.hpp"
#include "UMS_Data.hpp"
#include "UMS_Data_forward.hpp"
#include "SessionServer.hpp"

#include "user.pb.h"

class SessionServer;

/**
* \class UserServer
* \brief UserServer class implementation
*/
class UserServer {
public:
  /**
  * \brief Constructor
  * \fn UserServer(std::string userId, std::string password)
  * \param userId The userId of the user
  * \param password The password of the user
  */
  UserServer(std::string userId, std::string password);
  /**
  * \brief Constructor
  * \fn UserServer(const UMS_Data::User& user)
  * \param user The user data structure
  */
  UserServer(const UMS_Data::User& user);
  /**
  * \brief Constructor
  * \fn UserServer(SessionServer sessionServer)
  * \param sessionServer The object to manipulate session
  */
  UserServer(SessionServer sessionServer);
  /**
  * \brief Function to add a new VISHNU user
  * \fn int add(UMS_Data::User*& user, int vishnuId, std::string sendmailScriptPath)
  * \param user The user data structure
  * \param vishnuId The identifier of the vishnu instance
  * \param sendmailScriptPath The path to the script for sending emails
  * \return raises an exception on error
  */
  int
  add(UMS_Data::User*& user, int vishnuId, std::string sendmailScriptPath);

  int
  add(UMS_Data_Proto::User& user, int vishnuId, std::string sendmailScriptPath);
  //int
  //add(UMS_Data::Proto::User& user, int vishnuId, std::string sendmailScriptPath);
  /**
  * \brief Function to update user information
  * \fn int update(UMS_Data::User* user)
  * \param user The user data structure
  * \return raises an exception on error
  */
  int
  update(UMS_Data::User* user);
  /**
   * \brief Function to update user information
   * \fn int update(UMS_Data::User*& user)
   * \param user The user data structure
   * \return raises an exception on error
   */
  int
  update(const UMS_Data_Proto::User& user);
  /**
  * \brief Function to delete VISHNU user
  * \fn int deleteUser(UMS_Data::User user)
  * \param user The user data structure
  * \return raises an exception on error
  */
  int
  deleteUser(const UMS_Data_Proto::User& user);
  /**
  * \brief Function to change VISHNU user password
  * \fn int changePassword(std::string newPassword)
  * \param newPassword The new password of the user
  * \return raises an exception on error
  */
  int
  changePassword(std::string newPassword);
  /**
  * \brief Function to change VISHNU user password
  * \fn int resetPassword(UMS_Data::User& user, std::string sendmailScriptPath)
  * \param user The user data structure
  * \param sendmailScriptPath The path to the script for sending emails
  * \return raises an exception on error
  */
  int
  resetPassword(UMS_Data::User& user, std::string sendmailScriptPath);
  /**
  * \fn ~UserServer()
  * \brief Destructor
  */
  ~UserServer();
  /**
  * \brief Function to get user information
  * \fn UMS_Data::User getData()
  * \return  The user data structure
  */
  UMS_Data::User
  getData();
  /**
  * \brief Function to initialize user data for constructor with sessionServer
  * \fn init()
  */
  void
  init();
  /**
  * \brief Function to check user on database
  * \fn bool exist(bool flagForChangePwd)
  * \param flagForChangePwd A flag to check the password state
  * \return true if the password state has not to be checked else false
  */
  bool
  exist(bool flagForChangePwd = false);
  /**
  * \brief Function to check the VISHNU user privilege
  * \fn bool isAdmin()
  * \return true if the user is an admin else false
  */
  bool
  isAdmin();
  /**
  * \brief Function to check the user attribut value
  * \fn bool isAttributOk(std::string attributName, int valueOk)
  * \param attributName The name of the attribut to check
  * \param valueOk the value which will be compare to attribut name value
  * \return true if the attributName value is valueOk
  */
  bool
  isAttributOk(std::string attributName, int valueOk);//return if the password state ok
  /**
  * \brief Function to get user information from the database vishnu
  * \fn getAttribut(std::string condition, std::string attrname);
  * \param condition The condition of the select request
  * \param attrname the name of the attribut to get
  * \return the value of the attribut or empty string if no results
  */
  std::string
  getAttribut(std::string condition, std::string attrname = "numuserid");
  /**
  * \brief Function to check a userId
  * \fn bool existuserId(std::string userId)
  * \param userId The userId to check
  * \return true if the userId exists
  */
  bool
  existuserId(std::string userId);

   /**
   * \brief Function to get the user account login 
   * \param machineId The machine identifier of machine on which the user have a account
   * \return the user account login 
   */
  std::string
  getUserAccountLogin(const std::string& machineId);


private:

  /////////////////////////////////
  // Attributes
  /////////////////////////////////
  /**
  * \brief The user data structure
  */
  UMS_Data::User muser;
  //UMS_Data_Proto::User guser;
  /**
  * \brief An instance of vishnu database
  */
  Database *mdatabaseVishnu;
  /**
  * \brief An object which encapsulates session data
  */
  SessionServer *msessionServer;

  /////////////////////////////////
  // Functions
  /////////////////////////////////
  /**
  * \brief Function to generate a password
  * \fn generatePassword(std::string value1, std::string value2)
  * \param value1 a string used to generate the password
  * \param value2 a string used to generate the password
  * \return an encrypted message
  */
  std::string
  generatePassword(std::string value1, std::string value2);

  /**
   * \brief Function to send an email to the user
   * \param user     the user to whom send the email
   * \param content the body of the email
   * \param subject the subject of the email
   * \param sendmailScriptPath The path to the script for sending emails
   * \return The error or success code
   */
  int
  sendMailToUser(const UMS_Data::User& user,
                 std::string content,
                 std::string subject,
                 std::string sendmailScriptPath);

  /**
   * \brief Function to get the email content
   * \param user     the user who will receives the email
   * \param flagAdduser a flag which means that it is uses on adduser function
   * \return the email content
   */
  std::string
  getMailContent(const UMS_Data::User& user, bool flagAdduser);

};
#endif
