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
 * \file UserProxy.cpp
 * \brief This file contains the VISHNU UserProxy class.
 * \author Daouda Traore (daouda.traore@sysfera.com)
 * \date February 2011
 */
#include "UserProxy.hpp"
#include "UMSVishnuException.hpp"
#include "utilsClient.hpp"

/**
 * \fn  UserProxy(const std::string& userId, const std::string& password)
 * \param userId the user identifier
 * \password the user password
 * \brief Constructor, raises an exception on error
 */
UserProxy::UserProxy(const  std::string& userId, const std::string& password)
{
  muser.setUserId(userId);
  muser.setPassword(password);
  msessionProxy = NULL;
}

/**
 * \fn explicit UserProxy(SessionProxy session)
 * \param session The object which encapsulates the session information (ex: identifier of the session)
 * \brief Constructor, raises an exception on error
 */
UserProxy::UserProxy(SessionProxy session):
  msessionProxy(&session)
{
}

/**
 * \fn explicit UserProxy(const UMS_Data::User& user)
 * \param user The object which encapsulates the user information
 * \brief Constructor, raises an exception on error
 */
UserProxy::UserProxy(const UMS_Data::User& user):
  muser(user)
{
  msessionProxy = NULL;
}

int UserProxy::add(UMS_Data::User& user)
{
  diet_profile_t* profile = NULL;
  std::string sessionKey;
  char* userToString;
  char* errorInfo;
  char* userInString;
  std::string msg = "call of function diet_string_set is rejected ";

  profile = diet_profile_alloc("userCreate", 1, 1, 3);
  sessionKey = msessionProxy->getSessionKey();

  ::ecorecpp::serializer::serializer _ser;
  //To serialize the user object in to userToString
  userToString =  strdup(_ser.serialize_str(const_cast<UMS_Data::User_ptr>(&user)).c_str());
  //IN Parameters
  if(diet_string_set(diet_parameter(profile,0), strdup(sessionKey.c_str()), DIET_VOLATILE)) {
    msg += "with sessionKey parameter "+sessionKey;
    raiseDietMsgException(msg);
  }
  if(diet_string_set(diet_parameter(profile,1), userToString, DIET_VOLATILE)) {
    msg += "with userToString parameter "+std::string(userToString);
    raiseDietMsgException(msg);
  }

  //OUT Parameters
  diet_string_set(diet_parameter(profile,2), NULL, DIET_VOLATILE);
  diet_string_set(diet_parameter(profile,3), NULL, DIET_VOLATILE);

  if(!diet_call(profile)) {
    if(diet_string_get(diet_parameter(profile,2), &userInString, NULL)){
      msg += " by receiving User serialized  message";
      raiseDietMsgException(msg);
    }
    if(diet_string_get(diet_parameter(profile,3), &errorInfo, NULL)){
      msg += " by receiving errorInfo message";
      raiseDietMsgException(msg);
    }
  }
  else {
    raiseDietMsgException("DIET call failure");
  }

  /*To raise a vishnu exception if the receiving message is not empty*/
  raiseExceptionIfNotEmptyMsg(errorInfo);

  UMS_Data::User_ptr user_ptr;

  //To parse User object serialized
  parseEmfObject(std::string(userInString), user_ptr, "Error by receiving User object serialized");
  user = *user_ptr;
  muser = user;
  delete user_ptr;

  diet_profile_free(profile);

  return 0;
}
/**
 * \brief Function to add new user
 * \fn  int add(UMS_Data::User& user)
 * \param user The object which encapsulates the user information
 * \return raises an exception on error
 */
int UserProxy::add(UMS_Data_Proto::User& user)
{
  diet_profile_t* profile = NULL;
  std::string sessionKey;
  char* userToString;
  char* errorInfo;
  char* userInString;
  std::string msg = "call of function diet_string_set is rejected ";

  profile = diet_profile_alloc("userCreate", 1, 1, 3);
  sessionKey = msessionProxy->getSessionKey();

  //To serialize the user object in to userToString
  userToString =  strdup(user.SerializeAsString().c_str());
  //IN Parameters
  if(diet_string_set(diet_parameter(profile,0), strdup(sessionKey.c_str()), DIET_VOLATILE)) {
    msg += "with sessionKey parameter "+sessionKey;
    raiseDietMsgException(msg);
  }
  if(diet_string_set(diet_parameter(profile,1), userToString, DIET_VOLATILE)) {
    msg += "with userToString parameter "+std::string(userToString);
    raiseDietMsgException(msg);
  }

  //OUT Parameters
  diet_string_set(diet_parameter(profile,2), NULL, DIET_VOLATILE);
  diet_string_set(diet_parameter(profile,3), NULL, DIET_VOLATILE);

  if(!diet_call(profile)) {
    if(diet_string_get(diet_parameter(profile,2), &userInString, NULL)){
      msg += " by receiving User serialized  message";
      raiseDietMsgException(msg);
    }
    if(diet_string_get(diet_parameter(profile,3), &errorInfo, NULL)){
      msg += " by receiving errorInfo message";
      raiseDietMsgException(msg);
    }
  }
  else {
    raiseDietMsgException("DIET call failure");
  }

  /*To raise a vishnu exception if the receiving message is not empty*/
  raiseExceptionIfNotEmptyMsg(errorInfo);

  user.ParseFromString(std::string(userInString));

  diet_profile_free(profile);

  return 0;
}

/**
 * \brief Function to update user information
 * \fn  int update(const UMS_Data::User& user)
 * \param user The object which encapsulates the user information
 * \return raises an exception on error
 */
int UserProxy::update(const UMS_Data::User& user)
{
  diet_profile_t* profile = NULL;
  std::string sessionKey;
  std::string userToString;
  char* errorInfo;
  std::string msg = "call of function diet_string_set is rejected ";

  profile = diet_profile_alloc("userUpdate", 1, 1, 2);

  sessionKey = msessionProxy->getSessionKey();

  ::ecorecpp::serializer::serializer _ser;
  //To serialize the user object in to userToString
  userToString =  _ser.serialize_str(const_cast<UMS_Data::User_ptr>(&user));

  //IN Parameters
  if(diet_string_set(diet_parameter(profile,0), strdup(sessionKey.c_str()), DIET_VOLATILE)) {
    msg += "with sessionKey parameter "+sessionKey;
    raiseDietMsgException(msg);
  }
  if(diet_string_set(diet_parameter(profile,1), strdup(userToString.c_str()), DIET_VOLATILE)) {
    msg += "with userToString parameter "+userToString;
    raiseDietMsgException(msg);
  }

  //OUT Parameters
  diet_string_set(diet_parameter(profile,2), NULL, DIET_VOLATILE);

  if(!diet_call(profile)) {
    if(diet_string_get(diet_parameter(profile,2), &errorInfo, NULL)){
      msg += "by receiving errorInfo message";
      raiseDietMsgException(msg);
    }
  }
  else {
    raiseDietMsgException("DIET call failure");
  }

  /*To raise a vishnu exception if the receiving message is not empty*/
  raiseExceptionIfNotEmptyMsg(errorInfo);

  diet_profile_free(profile);

  return 0;
}


/**
 * \brief Function to update user information
 * \fn  int update(const UMS_Data::User& user)
 * \param user The object which encapsulates the user information
 * \return raises an exception on error
 */
int UserProxy::update(const UMS_Data_Proto::User& user)
{
  diet_profile_t* profile = NULL;
  std::string sessionKey;
  std::string userToString;
  char* errorInfo;
  std::string msg = "call of function diet_string_set is rejected ";

  profile = diet_profile_alloc("userUpdate", 1, 1, 2);

  sessionKey = msessionProxy->getSessionKey();

  //To serialize the user object in to userToString
  userToString = user.SerializeAsString();  

  //IN Parameters
  if(diet_string_set(diet_parameter(profile,0), strdup(sessionKey.c_str()), DIET_VOLATILE)) {
    msg += "with sessionKey parameter "+sessionKey;
    raiseDietMsgException(msg);
  }
  if(diet_string_set(diet_parameter(profile,1), strdup(userToString.c_str()), DIET_VOLATILE)) {
    msg += "with userToString parameter "+userToString;
    raiseDietMsgException(msg);
  }

  //OUT Parameters
  diet_string_set(diet_parameter(profile,2), NULL, DIET_VOLATILE);

  if(!diet_call(profile)) {
    if(diet_string_get(diet_parameter(profile,2), &errorInfo, NULL)){
      msg += "by receiving errorInfo message";
      raiseDietMsgException(msg);
    }
  }
  else {
    raiseDietMsgException("DIET call failure");
  }

  /*To raise a vishnu exception if the receiving message is not empty*/
  raiseExceptionIfNotEmptyMsg(errorInfo);

  diet_profile_free(profile);

  return 0;
}

/**
 * \brief Function to remove user information
 * \fn  int deleteUser(const UMS_Data::User& user)
 * \param user The object which encapsulates the user information
 * \return raises an exception on error
 */
int UserProxy::deleteUser(const UMS_Data_Proto::User& user)
{

  diet_profile_t* profile = NULL;
  std::string sessionKey;
  std::string userId;
  char* errorInfo;
  std::string msg = "call of function diet_string_set is rejected ";

  profile = diet_profile_alloc("userDelete", 1, 1, 2);
  sessionKey = msessionProxy->getSessionKey();
  userId = user.userid();

  //IN Parameters
  if(diet_string_set(diet_parameter(profile,0), strdup(sessionKey.c_str()), DIET_VOLATILE)) {
    msg += "with sessionKey parameter "+sessionKey;
    raiseDietMsgException(msg);
  }
  if(diet_string_set(diet_parameter(profile,1), strdup(userId.c_str()), DIET_VOLATILE)) {
    msg += "with userId parameter "+userId;
    raiseDietMsgException(msg);
  }

  //OUT Parameters
  diet_string_set(diet_parameter(profile,2), NULL, DIET_VOLATILE);

  if(!diet_call(profile)) {
    if(diet_string_get(diet_parameter(profile,2), &errorInfo, NULL)){
      msg += "by receiving errorInfo message";
      raiseDietMsgException(msg);
    }
  }
  else {
    raiseDietMsgException("DIET call failure");
  }
  /*To raise a vishnu exception if the receiving message is not empty*/
  raiseExceptionIfNotEmptyMsg(errorInfo);

  diet_profile_free(profile);

  return 0;
}

/**
 * \brief Function to change user password
 * \fn  int changePassword(const std::string& password, const std::string& newPassword)
 * \param oldPassword the old password of the user
 * \param newPassword the new password of the user
 * \return raises an exception on error
 */
int UserProxy::changePassword(const std::string& password, const std::string& newPassword)
{

  diet_profile_t* profile = NULL;
  char* errorInfo;
  std::string msg = "call of function diet_string_set is rejected ";

  profile = diet_profile_alloc("userPasswordChange", 2, 2, 3);

  //IN Parameters
  if(diet_string_set(diet_parameter(profile,0), strdup((muser.getUserId()).c_str()), DIET_VOLATILE)) {
    msg += "with sessionKey parameter "+msessionProxy->getSessionKey();
    raiseDietMsgException(msg);
  }

  if(diet_string_set(diet_parameter(profile,1), strdup(password.c_str()), DIET_VOLATILE)) {
    msg += "with password parameter "+password;
    raiseDietMsgException(msg);
  }

  if(diet_string_set(diet_parameter(profile,2), strdup(newPassword.c_str()), DIET_VOLATILE)) {
    msg += "with newPassword parameter "+newPassword;
    raiseDietMsgException(msg);
  }

  //OUT Parameters
  diet_string_set(diet_parameter(profile,3), NULL, DIET_VOLATILE);

  if(!diet_call(profile)) {
    if(diet_string_get(diet_parameter(profile,3), &errorInfo, NULL)){
      msg += "by receiving errorInfo message";
      raiseDietMsgException(msg);
    }
  }
  else {
    raiseDietMsgException("DIET call failure");
  }
  /*To raise a vishnu exception if the receiving message is not empty*/
  raiseExceptionIfNotEmptyMsg(errorInfo);

  diet_profile_free(profile);

  return 0;
}

/**
 * \brief Function to reset user password
 * \fn  int resetPassword(UMS_Data::User& user)
 * \param user The object which encapsulates the user information
 * \return raises an exception on error
 */
int UserProxy::resetPassword(UMS_Data::User& user)
{

  diet_profile_t* profile = NULL;
  char* tmpPassword;
  char* errorInfo;
  std::string msg = "call of function diet_string_set is rejected ";

  profile = diet_profile_alloc("userPasswordReset", 1, 1, 3);

  //IN Parameters
  if(diet_string_set(diet_parameter(profile,0), strdup((msessionProxy->getSessionKey()).c_str()), DIET_VOLATILE)) {
    msg += "with sessionKey parameter "+msessionProxy->getSessionKey();
    raiseDietMsgException(msg);
  }

  if(diet_string_set(diet_parameter(profile,1), strdup((user.getUserId()).c_str()), DIET_VOLATILE)) {
    msg += "with userId parameter "+user.getUserId();
    raiseDietMsgException(msg);
  }

  //OUT Parameters
  diet_string_set(diet_parameter(profile,2), NULL, DIET_VOLATILE);
  diet_string_set(diet_parameter(profile,3), NULL, DIET_VOLATILE);

  if(!diet_call(profile)) {
    if(diet_string_get(diet_parameter(profile,2), &tmpPassword, NULL)){
      msg += "by receiving tmpPassWord message";
      raiseDietMsgException(msg);
    }
    if(diet_string_get(diet_parameter(profile,3), &errorInfo, NULL)){
      msg += "by receiving errorInfo message";
      raiseDietMsgException(msg);
    }
  }
  else {
    raiseDietMsgException("DIET call failure");
  }
  /*To raise a vishnu exception if the receiving message is not empty*/
  raiseExceptionIfNotEmptyMsg(errorInfo);

  /*To set the temporary password*/
  muser.setUserId(user.getUserId());
  muser.setPassword(std::string(tmpPassword));

  diet_profile_free(profile);

  return 0;
}

/**
 * \brief Function get user information
 * \fn  UMS_Data::User getData()
 * \return User object encapsulates the information of the user
 * \return raises an exception on error
 */
UMS_Data::User UserProxy::getData() const
{
  return muser;
}

/**
 * \brief Function get SessionProxy object which contains the VISHNU session identifier
 * \fn SessionProxy getSessionProxy()
 * \return a SessionProy object which contains the VISHNU session information
 * \return raises an exception on error
 */
SessionProxy UserProxy::getSessionProxy() const
{
  return  *msessionProxy;
}

/**
 * \fn ~UserProxy()
 * \brief Destructor, raises an exception on error
 */
UserProxy::~UserProxy()
{
}
