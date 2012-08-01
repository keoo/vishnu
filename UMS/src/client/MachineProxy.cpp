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
 * \file MachineProxy.cpp
 * \brief This file contains the VISHNU MachineProxy class.
 * \author Daouda Traore (daouda.traore@sysfera.com)
 * \date February 2011
 */
#include "UMSVishnuException.hpp"
#include "MachineProxy.hpp"
#include "utilsClient.hpp"

/**
 * \fn MachineProxy(const UMS_Data::Machine& machine,
 *                       const SessionProxy& session)
 * \param machine The object which encapsulates the information of the machine
 * \param session The object which encapsulates the session information (ex: identifier of the session)
 * \brief Constructor, raises an exception on error
 */
MachineProxy::MachineProxy(const UMS_Data::Machine& machine, const SessionProxy& session):
  mmachine(machine), msessionProxy(session)
{
}

/**
 * \brief Function to add a new machine
 * \fn  int add()
 * \return raises an exception on error
 */
int MachineProxy::add()
{

  diet_profile_t* addProfile = NULL;
  std::string sessionKey;
  std::string machineToString;
  char* machineInString;
  char* errorInfo;
  std::string msg = "call of function diet_string_set is rejected ";

  addProfile = diet_profile_alloc("machineCreate", 1, 1, 3);
  sessionKey = msessionProxy.getSessionKey();

  ::ecorecpp::serializer::serializer _ser;
  //To serialize the mmachine object in to machineToString
  machineToString =  _ser.serialize_str(const_cast<UMS_Data::Machine_ptr>(&mmachine));

  std::string sshKeyFilePath = mmachine.getSshPublicKey();
  if(sshKeyFilePath.find("\"")!=std::string::npos) {
    throw UMSVishnuException(ERRCODE_INVALID_PARAM, " The machine SshPublicKey contains special character double quote \"");
  }

  //IN Parameters
  if(diet_string_set(diet_parameter(addProfile,0), strdup(sessionKey.c_str()), DIET_VOLATILE)) {
    msg += "with sessionKey parameter "+sessionKey;
    raiseDietMsgException(msg);
  }
  if(diet_string_set(diet_parameter(addProfile,1), strdup(machineToString.c_str()), DIET_VOLATILE)) {
    msg += "with machineToString parameter "+machineToString;
    raiseDietMsgException(msg);
  }

  //OUT Parameters
  diet_string_set(diet_parameter(addProfile,2), NULL, DIET_VOLATILE);
  diet_string_set(diet_parameter(addProfile,3), NULL, DIET_VOLATILE);

  if(!diet_call(addProfile)) {
    if(diet_string_get(diet_parameter(addProfile,2), &machineInString, NULL)){
      msg += "by receiving Machine serialized  message";
      raiseDietMsgException(msg);
    }
    if(diet_string_get(diet_parameter(addProfile,3), &errorInfo, NULL)){
      msg += "by receiving errorInfo message";
      raiseDietMsgException(msg);
    }
  }
  else {
    raiseDietMsgException("DIET call failure");
  }

  /*To raise a vishnu exception if the receiving message is not empty*/
  raiseExceptionIfNotEmptyMsg(errorInfo);

  UMS_Data::Machine_ptr machine_ptr;

  //To parse machine object serialized
  parseEmfObject(std::string(machineInString), machine_ptr, "Error by receiving Machine object serialized");

  mmachine = *machine_ptr;
  delete machine_ptr;

  diet_profile_free(addProfile);

  return 0;

}

/**
 * \brief Function to update machine description
 * \fn  int update()
 * \return raises an exception on error
 */
int MachineProxy::update()
{
  diet_profile_t* updateProfile = NULL;
  std::string sessionKey;
  std::string machineToString;
  char* errorInfo;
  std::string msg = "call of function diet_string_set is rejected ";

  updateProfile = diet_profile_alloc("machineUpdate", 1, 1, 2);
  sessionKey = msessionProxy.getSessionKey();

  ::ecorecpp::serializer::serializer _ser;
  //To serialize the mmachine object in to machineToString
  machineToString =  _ser.serialize_str(const_cast<UMS_Data::Machine_ptr>(&mmachine));

  std::string sshKeyFilePath = mmachine.getSshPublicKey();
  if(sshKeyFilePath.find("\"")!=std::string::npos) {
    throw UMSVishnuException(ERRCODE_INVALID_PARAM, " The machine SshPublicKey contains special character double quote \"");
  }

  //IN Parameters
  if(diet_string_set(diet_parameter(updateProfile,0), strdup(sessionKey.c_str()), DIET_VOLATILE)) {
    msg += "with sessionKey parameter "+sessionKey;
    raiseDietMsgException(msg);
  }
  if(diet_string_set(diet_parameter(updateProfile,1), strdup(machineToString.c_str()), DIET_VOLATILE)) {
    msg += "with machineToString parameter "+machineToString;
    raiseDietMsgException(msg);
  }

  //OUT Parameters
  diet_string_set(diet_parameter(updateProfile,2), NULL, DIET_VOLATILE);

  if(!diet_call(updateProfile)) {
    if(diet_string_get(diet_parameter(updateProfile,2), &errorInfo, NULL)){
      msg += "by receiving errorInfo message";
      raiseDietMsgException(msg);
    }
  }
  else {
    raiseDietMsgException("DIET call failure");
  }

  /*To raise a vishnu exception if the receiving message is not empty*/
  raiseExceptionIfNotEmptyMsg(errorInfo);

  diet_profile_free(updateProfile);

  return 0;
}

/**
 * \brief Function to remove a machine
 * \fn  int deleteMachine()
 * \return raises an exception on error
 */
int MachineProxy::deleteMachine()
{
  diet_profile_t* deleteProfile = NULL;
  std::string sessionKey;
  std::string machineId;
  char* errorInfo;
  std::string msg = "call of function diet_string_set is rejected ";

  deleteProfile = diet_profile_alloc("machineDelete", 1, 1, 2);
  sessionKey = msessionProxy.getSessionKey();
  machineId = mmachine.getMachineId();

  //IN Parameters
  if(diet_string_set(diet_parameter(deleteProfile,0), strdup(sessionKey.c_str()), DIET_VOLATILE)) {
    msg += "with sessionKey parameter "+sessionKey;
    raiseDietMsgException(msg);
  }
  if(diet_string_set(diet_parameter(deleteProfile,1), strdup(machineId.c_str()), DIET_VOLATILE)) {
    msg += "with machineId parameter "+machineId;
    raiseDietMsgException(msg);
  }

  //OUT Parameters
  diet_string_set(diet_parameter(deleteProfile,2), NULL, DIET_VOLATILE);

  if(!diet_call(deleteProfile)) {
    if(diet_string_get(diet_parameter(deleteProfile,2), &errorInfo, NULL)){
      msg += "by receiving errorInfo message";
      raiseDietMsgException(msg);
    }
  }
  else {
    raiseDietMsgException("DIET call failure");
  }

  /*To raise a vishnu exception if the receiving message is not empty*/
  raiseExceptionIfNotEmptyMsg(errorInfo);
  
  diet_profile_free(deleteProfile);

  return 0;
}

/**
 * \brief Function get SessionProxy object which contains the VISHNU session identifier
 * \fn SessionProxy getSessionProxy()
 * \return a SessionProy object which contains the VISHNU session information
 * \return raises an exception on error
 */
SessionProxy MachineProxy::getSessionProxy()
{
  return msessionProxy;
}

/**
 * \brief Function get machine information
 * \fn  UMS_Data::Machine getData()
 * \return Machine object encapsulates the information of the machine
 * \return raises an exception on error
 */
UMS_Data::Machine MachineProxy::getData()
{
  return mmachine;
}

/**
 * \fn ~MachineProxy()
 * \brief Destructor, raises an exception on error
 */
MachineProxy::~MachineProxy()
{
}

