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
 * \file LocalAccountProxy.cpp
 * \brief This file contains the VISHNU LocalAccountProxy class.
 * \author Daouda Traore (daouda.traore@sysfera.com)
 * \date February 2011
 */
#include "UMSVishnuException.hpp"
#include "utilsClient.hpp"
#include "LocalAccountProxy.hpp"

/**
 * \fn LocalAccountProxy(const UMS_Data::LocalAccount& localAccount,
 *                       const SessionProxy& session)
 * \param localAccount The object which encapsulates the user Acccount information
 * \param session The object which encapsulates the session information (ex: identifier of the session)
 * \brief Constructor, raises an exception on error
 */
LocalAccountProxy::LocalAccountProxy(const UMS_Data::LocalAccount& localAccount, const SessionProxy& session):
  mlocalAccount(localAccount), msessionProxy(session)
{
  msshPublicKey = "";
}

/**
 * \brief Function to combine add() and update() into one function
 * \fn  int _addLocalAccountInformation(bool isNewMachine=true);
 * \param isNewLocalAccount to select the call of add or update function
 * \return raises an exception on error
 */
int LocalAccountProxy::_addLocalAccountInformation(bool isNewLocalAccount) {

  diet_profile_t* profile = NULL;
  std::string sessionKey;
  std::string localAccountToString;
  char* sshPublicKey;
  char* errorInfo;
  std::string msg = "call of function diet_string_set is rejected ";

  if(isNewLocalAccount) {
    profile = diet_profile_alloc("localAccountCreate", 1, 1, 3);
  }
  else {
    profile = diet_profile_alloc("localAccountUpdate", 1, 1, 2);
  }

  sessionKey = msessionProxy.getSessionKey();

  ::ecorecpp::serializer::serializer _ser;
  //To serialize the mlocalAccount object in to localAccountToString
  localAccountToString =  _ser.serialize_str(const_cast<UMS_Data::LocalAccount_ptr>(&mlocalAccount));

  //IN Parameters
  if(diet_string_set(diet_parameter(profile,0), strdup(sessionKey.c_str()), DIET_VOLATILE)) {
    msg += "with sessionKey parameter "+sessionKey;
    raiseDietMsgException(msg);
  }
  if(diet_string_set(diet_parameter(profile,1), strdup(localAccountToString.c_str()), DIET_VOLATILE)) {
    msg += "with localAccountToString parameter "+localAccountToString;
    raiseDietMsgException(msg);
  }

  //OUT Parameters
  diet_string_set(diet_parameter(profile,2), NULL, DIET_VOLATILE);
  if(isNewLocalAccount) {
    diet_string_set(diet_parameter(profile,3), NULL, DIET_VOLATILE);
  }

  if(!diet_call(profile)) {
    if(isNewLocalAccount) {
      if(diet_string_get(diet_parameter(profile,2), &sshPublicKey, NULL)){
        msg += "by receiving sshPluciKey content";
        raiseDietMsgException(msg);
      }
      if(diet_string_get(diet_parameter(profile,3), &errorInfo, NULL)){
        msg += "by receiving errorInfo message";
        raiseDietMsgException(msg);
      }
      msshPublicKey = sshPublicKey;
    }
    else {
      if(diet_string_get(diet_parameter(profile,2), &errorInfo, NULL)){
        msg += "by receiving errorInfo message";
        raiseDietMsgException(msg);
      }
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
 * \brief Function to add a new local user configuration
 * \fn  int add()
 * \return raises an exception on error
 */
int LocalAccountProxy::add()
{
  return _addLocalAccountInformation();
}

/**
 * \brief Function to update a new local user configuration
 * \fn  int update()
 * \return raises an exception on error
 */
int LocalAccountProxy::update()
{
  return _addLocalAccountInformation(false);
}

/**
 * \brief Function to removes a local user configuration (for a given user on a given machine) from VISHNU
 * \fn  int deleteLocalAccount()
 * \return raises an exception on error
 */
int LocalAccountProxy::deleteLocalAccount()
{
  diet_profile_t* profile = NULL;
  std::string sessionKey;
  std::string userId;
  std::string machineId;
  char* errorInfo;
  std::string msg = "call of function diet_string_set is rejected ";

  profile = diet_profile_alloc("localAccountDelete", 2, 2, 3);
  sessionKey = msessionProxy.getSessionKey();
  userId = mlocalAccount.getUserId();
  machineId = mlocalAccount.getMachineId();

  //IN Parameters
  if(diet_string_set(diet_parameter(profile,0), strdup(sessionKey.c_str()), DIET_VOLATILE)) {
    msg += "with sessionKey parameter "+sessionKey;
    raiseDietMsgException(msg);
  }
  if(diet_string_set(diet_parameter(profile,1), strdup(userId.c_str()), DIET_VOLATILE)) {
    msg += "with userId parameter "+userId;
    raiseDietMsgException(msg);
  }
  if(diet_string_set(diet_parameter(profile,2), strdup(machineId.c_str()), DIET_VOLATILE)) {
    msg += "with machineId parameter "+machineId;
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
 * \brief Function get SessionProxy object which contains the VISHNU session identifier
 * \fn SessionProxy getSessionProxy()
 * \return a SessionProy object which contains the VISHNU session information
 * \return raises an exception on error
 */
SessionProxy LocalAccountProxy::getSessionProxy() const
{
  return msessionProxy;
}

/**
 * \brief Function get the VISHNU ssh public key
 * \fn std::string getSshPublicKey() const
 * \return the VISHNU ssh public Key
 * \return raises an exception on error
 */
std::string LocalAccountProxy::getSshPublicKey() const {
  return msshPublicKey;
}

/**
 * \fn ~LocalAccountProxy()
 * \brief Destructor, raises an exception on error
 */
LocalAccountProxy::~LocalAccountProxy()
{
}
