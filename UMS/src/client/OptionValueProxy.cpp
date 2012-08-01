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
 * \file OptionValueProxy.cpp
 * \brief This file contains the VISHNU OptionValueProxy class.
 * \author Daouda Traore (daouda.traore@sysfera.com)
 * \date February 2011
 */
#include "UMSVishnuException.hpp"
#include "utilsClient.hpp"
#include "OptionValueProxy.hpp"

/**
 * \fn OptionValueProxy(const UMS_Data::OptionValue& optionValue,
 *                      const SessionProxy& session)
 * \param optionValue The object which encapsulates the information of the option
 * \param session The object which encapsulates the session information (ex: identifier of the session)
 * \brief Constructor, raises an exception on error
 */
OptionValueProxy::OptionValueProxy(const UMS_Data::OptionValue& optionValue, const SessionProxy& session):
  moptionValue(optionValue), msessionProxy(session)
{
}

/**
 * \brief Function to combine configureOption() and configureDefaultOption() into one function
 * \fn  int setOptionValue(bool defaultValue=true);
 * \param defaultValue to select the call of configureOption() or configureOption() function
 * \return raises an exception on error
 */
int OptionValueProxy::setOptionValue(bool defaultValue)
{
  diet_profile_t* profile = NULL;
  std::string sessionKey;
  std::string optionValueToString;
  char* errorInfo;
  std::string msg = "call of function diet_string_set is rejected ";

  if(defaultValue) {
    profile = diet_profile_alloc("optionValueSetDefault", 1, 1, 2);
  }
  else {
    profile = diet_profile_alloc("optionValueSet", 1, 1, 2);
  }
  sessionKey = msessionProxy.getSessionKey();

  ::ecorecpp::serializer::serializer _ser;
  //To serialize the moptionValue object in to optionValueToString
  optionValueToString =  _ser.serialize_str(const_cast<UMS_Data::OptionValue_ptr>(&moptionValue));

  //IN Parameters
  if(diet_string_set(diet_parameter(profile,0), strdup(sessionKey.c_str()), DIET_VOLATILE)) {
    msg += "with sessionKey parameter "+sessionKey;
    raiseDietMsgException(msg);
  }
  if(diet_string_set(diet_parameter(profile,1), strdup(optionValueToString.c_str()), DIET_VOLATILE)) {
    msg += "with optionValueToString parameter "+optionValueToString;
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
 * \brief Function to configure an option of the user
 * \fn  int configureOption()
 * \return raises an exception on error
 */
int OptionValueProxy::configureOption()
{
  return setOptionValue(false);
}

/**
 * \brief Function to configure a default option value
 * \fn  int configureDefaultOption()
 * \return raises an exception on error
 */
int OptionValueProxy::configureDefaultOption()
{
  return setOptionValue();
}

/**
 * \brief Function get option information
 * \fn  UMS_Data::OptionValue getData()
 * \return OptionValue object encapsulates the information of the machine
 * \return raises an exception on error
 */
UMS_Data::OptionValue OptionValueProxy::getData()
{
  return moptionValue;
}

/**
 * \brief Function get SessionProxy object which contains the VISHNU session identifier
 * \fn SessionProxy getSessionProxy()
 * \return a SessionProy object which contains the VISHNU session information
 * \return raises an exception on error
 */
SessionProxy OptionValueProxy::getSessionProxy()
{
  return msessionProxy;
}

/**
 * \fn ~OptionValueProxy()
 * \brief Destructor, raises an exception on error
 */
OptionValueProxy::~OptionValueProxy()
{
}
