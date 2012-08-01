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
* \file LocalAccountServer.hpp
* \brief This file presents the Class which manipulates VISHNU localAccount data on server side.
* \author Eugène PAMBA CAPO-CHICHI (eugene.capochichi@sysfera.com)
* \date 31/01/2011
*/

#ifndef LOCAL_ACCOUNT_SERVER_H
#define LOCAL_ACCOUNT_SERVER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include "SessionServer.hpp"
#include "UMS_Data.hpp"
#include "UMS_Data_forward.hpp"
#include "MachineServer.hpp"

/**
* \class LocalAccountServer
* \brief LocalAccountServer class implementation
*/
class LocalAccountServer {
public:
  /**
  * \brief Constructor
  * \fn LocalAccountServer(UMS_Data::LocalAccount*& account, SessionServer& session)
  * \param account The LocalAccount data structure
  * \param session The object which encapsulates session data
  */
  LocalAccountServer(UMS_Data::LocalAccount*& account, SessionServer& session);
  /**
  * \brief Function to add a new VISHNU localAccount
  * \fn int add()
  * \return raises an exception on error
  */
  int
  add();
  /**
  * \brief Function to update a VISHNU localAccount
  * \fn int update()
  * \return raises an exception on error
  */
  int
  update();
  /**
* \brief Function to delete a VISHNU localAccount
* \fn int deleteLocalAccount()
* \return raises an exception on error
*/
  int
  deleteLocalAccount();
  /**
  * \fn ~LocalAccountServer
  * \brief Destructor,
  */
  ~LocalAccountServer();
  /**
  * \brief Function to get localAccount data structure
  * \fn UMS_Data::LocalAccount getData()
  * \return  The LocalAccount data structure
  */
  UMS_Data::LocalAccount*
  getData();
  /**
  * \brief Function to get localAccount information from the database vishnu
  * \fn getAttribut(std::string condition, std::string attrname);
  * \param condition The condition of the select request
  * \param attrname the name of the attribut to get
  * \return the value of the attribut or empty string if no results
  */
  std::string
  getAttribut(std::string condition, std::string attrname = "numaccountid");
  /**
  * \brief Function to get the content of the public ssh generated
  * \fn std::string getPublicKey()
  * \return The content of the ssh public key generated
  */
  std::string
  getPublicKey();

private:
  /////////////////////////////////
  // Attributes
  /////////////////////////////////
  /**
  * \brief The localAccount data structure
  */
  UMS_Data::LocalAccount *mlocalAccount;
  /**
  * \brief An object which encapsulates session data
  */
  SessionServer msessionServer;
  /**
  * \brief An instance of vishnu database
  */
  Database *mdatabaseVishnu;
  /**
  * \brief The content of the ssh public key generated
  */
  std::string msshpublickey;

  /////////////////////////////////
  // Functions
  /////////////////////////////////
  /**
  * \brief Function to generate a private/public ssh key
  * \fn std::string generateKey()
  */
  std::string
  generateKey();
  /**
  * \brief Function to check localAccount on database
  * \fn bool exist(std::string idmachine, std::string iduser)
  * \param idmachine The id of the machine
  * \param iduser The id of the user
  * \return true if the localAccount exists else false
  */
  bool
  exist(std::string idmachine, std::string iduser);
  /**
  * \brief Function to check if a given login is used on a machine
  * \param numMachine the internal id of the machine
  * \param acLogin the account login
  * \return true if the login is already used on the machine
  */
  bool
  isLoginUsed(std::string numMachine, std::string acLogin);
};
#endif
