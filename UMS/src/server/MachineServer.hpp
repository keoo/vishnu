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
* \file MachineServer.hpp
* \brief This file presents the Class which manipulates VISHNU machine data on server side.
* \author Eugène PAMBA CAPO-CHICHI (eugene.capochichi@sysfera.com)
* \date 31/01/2011
*/

#ifndef MACHINE_SERVER_H
#define MACHINE_SERVER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <exception>
#include "VishnuException.hpp"
#include "UMSVishnuException.hpp"
#include "SessionServer.hpp"
#include "UMS_Data.hpp"
#include "UMS_Data_forward.hpp"


using namespace vishnu;


/**
* \class MachineServer
* \brief MachineServer class implementation
*/
class MachineServer {

public:
  /**
  * \brief Constructor
  * \fn MachineServer(UMS_Data::Machine*& machine)
  * \param machine The machine data structure
  */
  MachineServer(UMS_Data::Machine*& machine);
  /**
  * \brief Constructor
  * \fn MachineServer(UMS_Data::Machine*& machine, SessionServer& session)
  * \param machine The machine data structure
  * \param session The object which encapsulates session data
  */
  MachineServer(UMS_Data::Machine*& machine, SessionServer& session);
  /**
  * \brief Function to add a new VISHNU machine
  * \fn int add(int vishnuId)
  * \param vishnuId The identifier of the vishnu instance
  * \return raises an exception on error
  */
  int
  add(int vishnuId);
  /**
  * \brief Function to update a VISHNU machine
  * \fn int update()
  * \return raises an exception on error
  */
  int
  update();
  /**
  * \brief Function to delete a VISHNU machine
  * \fn int deleteMachine()
  * \return raises an exception on error
  */
  int
  deleteMachine();
  /**
  * \fn ~MachineServer()
  * \brief Destructor
  */
  ~MachineServer();
  /**
  * \brief Function to get machine information
  * \fn UMS_Data::Machine* getData()
  * \return  The user data structure
  */
  UMS_Data::Machine*
  getData();
  /**
  * \brief Function to get machine information from the database vishnu
  * \fn getAttribut(std::string condition, std::string attrname);
  * \param condition The condition of the select request
  * \param attrname the name of the attribut to get
  * \return the value of the attribut or empty string if no results
  */
  std::string
  getAttribut(std::string condition, std::string attrname = "nummachineid");
  /**
  * \brief Function to get the content of the public ssh key
  * \fn std::string getPublicKey()
  * \return The content of the ssh public key
  */
  std::string
  getPublicKey();

  /**
   * \brief Function to get the machine 
   * \return The name of the machine 
   */
  std::string getMachineName();

  /**
   * \brief Function to check the machineId
   * \return raises an exception 
   */
  void checkMachine();

private:
  /////////////////////////////////
  // Attributes
  /////////////////////////////////
  /**
  * \brief The machine data structure
  */
  UMS_Data::Machine *mmachine;
  /**
  * \brief An object which encapsulates session data
  */
  SessionServer msessionServer;
  /**
  * \brief An instance of vishnu database
  */
  Database *mdatabaseVishnu;
  /**
  * \brief The content of the ssh public key
  */
  std::string msshpublickey;

};
#endif
