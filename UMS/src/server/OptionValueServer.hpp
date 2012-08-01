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
* \file OptionValueServer.hpp
* \brief This file presents the Class which manipulates VISHNU options on server side.
* \author Eugène PAMBA CAPO-CHICHI (eugene.capochichi@sysfera.com)
* \date 31/01/2011
*/

#ifndef OPTION_VALUE_SERVER_H
#define OPTION_VALUE_SERVER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <exception>
#include "VishnuException.hpp"
#include "UMS_Data.hpp"
#include "UMS_Data_forward.hpp"
#include "Database.hpp"

class SessionServer;

static const std::string CLOSEPOLICY_OPT = "VISHNU_CLOSE_POLICY";
static const std::string TIMEOUT_OPT = "VISHNU_TIMEOUT";
static const std::string TRANSFERCMD_OPT = "VISHNU_TRANSFER_CMD";

/**
* \class OptionValueServer
* \brief OptionValueServer class implementationT
*/
class OptionValueServer {

public:
  /**
  * \brief Constructor
  * \fn OptionValueServer()
  */
  OptionValueServer();
  /**
  * \brief Constructor
  * \fn OptionValueServer(UMS_Data::OptionValue*& optionvalue, SessionServer session)
  * \param optionvalue the option data structure
  * \param session The object to manipulate session
  */
  OptionValueServer(UMS_Data::OptionValue*& optionvalue, SessionServer session);
  /**
  * \brief Function to configure options on the database
  * \fn    int configureOption(bool defaultOptions = false)
  * \param defaultOptions the flag to get data from defauts options table
  * \return  raises an exception on error
  */
  int
  configureOption(bool defaultOptions = false);
  /**
  * \brief Destructor
  * \fn  ~OptionValueServer()
  */
  ~OptionValueServer();
  /**
  * \brief Function to get option data structure
  * \fn UMS_Data::OptionValue getData()
  * \return  The user data structure
  */
  UMS_Data::OptionValue*
  getData();
  /**
  * \brief Function to get option information from the database vishnu
  * \fn std::string getAttribut(std::string condition, std::string attrname="value", bool defaultOptions=false);
  * \param condition The condition of the select request
  * \param attrname the name of the attribut to get
  * \param defaultOptions the flag to get data from defauts options table
  * \return the value of the attribut or empty string if no results
  */
  std::string
  getAttribut(std::string condition, std::string attrname="value", bool defaultOptions=false);
  /**
  * \brief Function to get user option value
  * \param numuserId The database number id of the user
  * \param optionName the name of the option
  * \return The error or success code
  */
  int
  getOptionValueForUser(std::string numuserId, std::string optionName);

private:
  /////////////////////////////////
  // Attributes
  /////////////////////////////////
  /**
  * \brief The option data structure
  */
  UMS_Data::OptionValue *moptionValue;
  /**
  * \brief An instance of vishnu database
  */
  Database *mdatabaseVishnu;
  /**
  * \brief An object which encapsulates user data
  */
  SessionServer *msessionServer;

  /////////////////////////////////
  // Function
  /////////////////////////////////
  /**
  * \brief Function to check the value for a specific option
  * \fn bool isCorrectValue()
  * \return  true if the option value is correct else false
  */
  bool
  isCorrectValue();
};
#endif//OPTION_VALUE_SERVER_H
