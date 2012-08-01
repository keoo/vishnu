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
 * \file QueryProxy.hpp
 * \brief This file contains the VISHNU QueryProxy class.
 * \author Daouda Traore (daouda.traore@sysfera.com)
 * \date February 2011
 */
#ifndef _QUERY_PROXY_H_
#define _QUERY_PROXY_H_

#include <string>
#include <iostream>

#include "utilsClient.hpp"
#include "SessionProxy.hpp"
#include "user.pb.h"

/**
 * \class SerializeAdaptor
 * \brief SerializeAdaptor class implementation
 */
template <class Object>
struct SerializeAdaptor {

  /**
   * \brief Function to convert an object type to string 
   * \param object The Object to convert
   */
  static std::string serialize(const Object& object) {
    ::ecorecpp::serializer::serializer _ser;
    return  _ser.serialize_str(const_cast<Object*>(&object));
  }
};
 
/**
 * \class ParseAdaptor
 * \brief ParseAdaptor class implementation
 */
template <class Object>
struct ParseAdaptor {
 
  /**
   * \brief Function to convert an object type to string 
   * \param object The Object to convert
   */
  static void parse(const std::string& objectToParse, Object*& object ) {
  parseEmfObject(objectToParse, object, "Error by receiving List object serialized");
  }


}; 

/**
 * \class SerializeAdaptor
 * \brief Specialization in std::string of the SerializeAdaptor
 */
template <>
struct SerializeAdaptor<std::string> {

  /**
   * \brief Function to convert an object type to string
   * \param object The Object to convert
   */
  static std::string serialize(const std::string& object) {
    return  object;
  }

};

/**
 * \class SerializeAdaptor
 * \brief Specialization in UMS_Data_Proto::ListUsers of the SerializeAdaptor
 */
template <>
struct SerializeAdaptor<UMS_Data_Proto::ListUsers> {

  /**
   * \brief Function to convert an object type to string
   * \param object The Object to convert
   */
  static std::string serialize(const UMS_Data_Proto::ListUsers&  object) {
    return  object.SerializeAsString();
  }

};

/**
 * \class ParseAdaptor
 * \brief ParseAdaptor class implementation
 */
template <>
struct ParseAdaptor<UMS_Data_Proto::ListUsers> {
 
  static void parse(const std::string& objectToParse, UMS_Data_Proto::ListUsers*& object ) {
    object= new UMS_Data_Proto::ListUsers;
    object->ParseFromString(objectToParse);
  }


};




/**
 * \class QueryProxy
 * \brief QueryProxy class implementation
 */
template <class QueryParameters, class ListObject>
class QueryProxy
{

  public:

    /**
     * \param params The object which encapsulates the information of queryProxy options
     * \param session The object which encapsulates the session information (ex: identifier of the session)
     * \param serviceName The name of the service to call
     * \brief Constructor, raises an exception on error
     */
    QueryProxy(const QueryParameters& params,
               const SessionProxy& session,
               const std::string& serviceName);
    /**
     * \param params The object which encapsulates the information of queryProxy options
     * \param session The object which encapsulates the session information (ex: identifier of the session)
     * \param serviceName The name of the service to call
     * \param machineId The identifier of the machine in which the query will be done
     * \brief Constructor, raises an exception on error
     */
    QueryProxy(const QueryParameters& params,
               const SessionProxy& session,
               const std::string& serviceName,
               const std::string& machineId);

    /**
     * \brief Function to change or reset the machineId
     * \param machineId the id of the machine used by the query
     */
    void
    setMachineId(const std::string& machineId);

    /**
     * \brief Function to get the machineId used by the query
     * \return the id of the machine used by the query
     */
    std::string
    getMachineId() const;

    /**
     * \brief Function to list QueryProxy information
     * \fn  ListObject* list()
     * \return The pointer to the ListOject containing list information
     * \return raises an exception on error
     */
    ListObject*
    list();
    
    /**
     * \fn ~QueryProxy()
     * \brief Destructor, raises an exception on error
     */
    ~QueryProxy();

  private:
    /**
     * \brief Define a pointer type for more facilities
     */
    typedef ListObject* ListObject_ptr;
    /**
     * \brief Define a pointer type for more facilities
     */
    typedef QueryParameters* QueryParameters_ptr;

    /////////////////////////////////
    // Attributes
    /////////////////////////////////

    /**
     * \brief The QueryParameters information
     */
    QueryParameters mparameters;
    /**
     * \brief The name of the service
     */
    std::string mserviceName;
    /**
     * \brief The SessionProxy object containing the encrypted identifier of the session
     *  generated by VISHNU
     */
    SessionProxy msessionProxy;
    /**
     * \brief The Object containing query information
     */
    ListObject* mlistObject;
    /**
     * \brief The id of the machine used by the query
     */
    std::string mmachineId;
};

/**
 * \brief A Constructor of the QueryProxy template class
 * \param params The object which encapsulates the information of queryProxy options
 * \param session The object which encapsulates the session information (ex: identifier of the session)
 * \param serviceName The name of the service to call
 * \brief Constructor, raises an exception on error
 */
template <class QueryParameters, class ListObject>
QueryProxy<QueryParameters, ListObject>::QueryProxy(const QueryParameters& params, const SessionProxy& session,
    const std::string& serviceName):
  mparameters(params), mserviceName(serviceName), msessionProxy(session)
{
  mlistObject = NULL;
  mmachineId = "";
}

/**
 * \brief Another constructor of the QueryProxy template class
 * \param params The object which encapsulates the information of queryProxy options
 * \param session The object which encapsulates the session information (ex: identifier of the session)
 * \param serviceName The name of the service to call
 * \param machineId The identifier of the machine in which the query will be done
 * \brief Constructor, raises an exception on error
 */

template <class QueryParameters, class ListObject>
QueryProxy<QueryParameters, ListObject>::QueryProxy(const QueryParameters& params, const SessionProxy& session,
    const std::string& serviceName, const std::string& machineId):
  mparameters(params), mserviceName(serviceName), msessionProxy(session), mmachineId (machineId)
{
  mlistObject = NULL;
}


/**
* \brief Function to reset machineId
* \param machineId The identifier of the machine in which the query will be done
*/
template <class QueryParameters, class ListObject>
void
QueryProxy<QueryParameters, ListObject>::setMachineId(const std::string& machineId) {
  mmachineId = machineId;
}


 /**
* \brief Function to get the machineId used by the query
* \return the id of the machine used by the query
*/
template <class QueryParameters, class ListObject>
std::string
QueryProxy<QueryParameters, ListObject>::getMachineId() const {
  return mmachineId;
}

/**
 * \brief Function to list QueryProxy information
 * \fn  ListObject* QueryProxy<QueryParameters, ListObject>::list()
 * \return The pointer to the ListOject containing list information
 * \return raises an exception on error
 */
  template <class QueryParameters, class ListObject>
ListObject* QueryProxy<QueryParameters, ListObject>::list()
{
  diet_profile_t* profile = NULL;
  std::string sessionKey;
  std::string queryParmetersToString;
  char* listObjectInString;
  char* errorInfo;
  std::string msg = "call of function diet_string_set is rejected ";

  //If the query uses the machineId (machineId not null)
  if (mmachineId.size() != 0) {
    profile = diet_profile_alloc(mserviceName.c_str(), 2, 2, 4);
  }
  else {
    profile = diet_profile_alloc(mserviceName.c_str(), 1, 1, 3);
  }

  sessionKey = msessionProxy.getSessionKey();
  queryParmetersToString =  SerializeAdaptor<QueryParameters>::serialize(mparameters); 

  //IN Parameters
  if(diet_string_set(diet_parameter(profile,0), strdup(sessionKey.c_str()), DIET_VOLATILE)) {
      msg += "with sessionKey parameter "+sessionKey;
      raiseDietMsgException(msg);
    }

  //If the query uses the machineId (machineId not null)
  if (mmachineId.size() != 0) {

    if(diet_string_set(diet_parameter(profile,1), strdup(mmachineId.c_str()), DIET_VOLATILE)) {
      msg += "with machineId parameter "+mmachineId;
      raiseDietMsgException(msg);
    }

    if(diet_string_set(diet_parameter(profile,2), strdup(queryParmetersToString.c_str()), DIET_VOLATILE)) {
      msg += "with queryParmetersToString parameter "+queryParmetersToString;
      raiseDietMsgException(msg);
    }

    //OUT Parameters
    diet_string_set(diet_parameter(profile,3), NULL, DIET_VOLATILE);
    diet_string_set(diet_parameter(profile,4), NULL, DIET_VOLATILE);

    if(!diet_call(profile)) {
      if(diet_string_get(diet_parameter(profile,3), &listObjectInString, NULL)){
        msg += "by receiving listObjectInString message";
        raiseDietMsgException(msg);
      }
      if(diet_string_get(diet_parameter(profile,4), &errorInfo, NULL)){
        msg += "by receiving errorInfo message";
        raiseDietMsgException(msg);
      }
    }
    else {
      raiseDietMsgException("DIET call failure");
    }
  }
  else {

    if(diet_string_set(diet_parameter(profile,1), strdup(queryParmetersToString.c_str()), DIET_VOLATILE)) {
      msg += "with queryParmetersToString parameter "+queryParmetersToString;
      raiseDietMsgException(msg);
    }

    //OUT Parameters
    diet_string_set(diet_parameter(profile,2), NULL, DIET_VOLATILE);
    diet_string_set(diet_parameter(profile,3), NULL, DIET_VOLATILE);

    if(!diet_call(profile)) {
      if(diet_string_get(diet_parameter(profile,2), &listObjectInString, NULL)){
        msg += "by receiving listObjectInString message";
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
  }


  /*To check the receiving message error*/
  raiseExceptionIfNotEmptyMsg(errorInfo);

  //To parse List object serialized
  ParseAdaptor<ListObject>::parse(std::string(listObjectInString),mlistObject);
  return mlistObject;
}

/**
 * \brief A default destructor for QueryProxy
 * \brief Destructor, raises an exception on error
 */
  template <class QueryParameters, class ListObject>
QueryProxy<QueryParameters, ListObject>::~QueryProxy()
{
}

#endif
