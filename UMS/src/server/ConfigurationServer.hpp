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
* \file ConfigurationServer.hpp
* \brief This file presents the Class which manipulates VISHNU configuration data on server side.
* \author Eugène PAMBA CAPO-CHICHI (eugene.capochichi@sysfera.com)
* \date 31/01/2011
*/
#ifndef CONFIGURATION_SERVER_H
#define CONFIGURATION_SERVER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <ecore.hpp>
#include <ecorecpp.hpp>
#include "SessionServer.hpp"
#include "UMS_Data.hpp"
#include "UMS_Data_forward.hpp"

/**
* \class ConfigurationServer
* \brief ConfigurationServer class implementation
*/
class ConfigurationServer {

public:
  /**
  * \brief Constructor
  * \fn ConfigurationServer(SessionServer session)
  * \param session The object which encapsulates session data
  */
  ConfigurationServer(SessionServer session);
  /**
  * \brief Constructor
  * \fn ConfigurationServer(UMS_Data::Configuration*& configuration, SessionServer session);
  * \param configuration The Configuration data structure
  * \param session The object which encapsulates session data
  */
  ConfigurationServer(UMS_Data::Configuration*& configuration, SessionServer session);
  /**
  * \brief Function to save a VISHNU configuration
  * \fn int save()
  * \return raises an exception on error
  */
  int
  save();
  /**
  * \brief Function to restore a VISHNU configuration
  * \fn int restore(int vishnuId)
  * \param vishnuId The identifier of the vishnu instance
  * \return raises an exception on error
  */
  int
  restore(int vishnuId);
  /**
  * \fn ~ConfigurationServer()
  * \brief Destructor
  */
  ~ConfigurationServer();
  /**
  * \brief Function to get Configuration data structure
  * \fn UMS_Data::Configuration*  getData()
  * \return  The LocalAccount data structure
  */
  UMS_Data::Configuration*
  getData();

private:

  /////////////////////////////////
  // Attributes
  /////////////////////////////////
  /**
  * \brief The Configuration data structure
  */
  UMS_Data::Configuration *mconfiguration;
  /**
  * \brief An object which encapsulates session data
  */
  SessionServer msessionServer;
  /**
  * \brief An instance of vishnu database
  */
  Database *mdatabaseVishnu;

  /////////////////////////////////
  // Functions
  /////////////////////////////////
  /**
  * \brief Function to get the sql code of users from a VISHNU configuration
  * \fn std::string userToSql(UMS_Data::User_ptr user, int vishnuId)
  * \param user The user object
  * \param vishnuId The identifier of the vishnu instance
  * \return the sql code containing the sql code of users
  */
  std::string
  userToSql(UMS_Data::User_ptr user, int vishnuId);
  /**
  * \brief Function to get the sql code of machines from a VISHNU configuration
  * \fn std::string machineToSql(UMS_Data::Machine_ptr machine, int vishnuId)
  * \param machine The machine object
  * \param vishnuId The identifier of the vishnu instance
  * \return the sql code containing the sql code of machines
  */
  std::string
  machineToSql(UMS_Data::Machine_ptr machine, int vishnuId);
  /**
  * \brief Function to get the sql code of machines description from a VISHNU configuration
  * \fn std::string machineDescToSql(UMS_Data::Machine_ptr machine)
  * \param machine The machine object
  * \return the sql code containing the sql code of machines description
  */
  std::string
  machineDescToSql(UMS_Data::Machine_ptr machine);
};
#endif
