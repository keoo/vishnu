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
* \file MachineClientServer.hpp
* \brief This file presents the Class which manipulates the VISHNU client machine data on server side.
* \author Eugène PAMBA CAPO-CHICHI (eugene.capochichi@sysfera.com)
* \date 31/01/2011
*/

#ifndef MACHINE_CLIENT_SERVER_H
#define MACHINE_CLIENT_SERVER_H

#include <sstream>
#include <exception>
#include "VishnuException.hpp"
#include "UMSVishnuException.hpp"
#include "Database.hpp"

/**
* \class MachineClientServer
* \brief MachineClientServer class implementation
*/
class MachineClientServer {
public:
  /**
  * \brief Constructor
  * \fn MachineClientServer(std::string sshKey, std::string host)
  * \param sshKey The ssh key of the client machine
  * \param host The name of the client host
  */
  MachineClientServer(std::string sshKey, std::string host);
  /**
  * \brief Function to record the client machine on the database
  * \fn int recordMachineClient()
  * \return raises an exception on error
  */
  int
  recordMachineClient();
  /**
  * \brief Function to get the id number of the client machine
  * \fn std::string getId()
  * \return raises an exception on error
  */
  std::string
  getId();
  /**
  * \brief Function to get the ssh key of the client machine
  * \fn std::string getSSHKey() const
  * \return raises an exception on error
  */
  std::string
  getSSHKey() const;
  /**
  * \brief Function to get the hostname of the client machine
  * \fn std::string getHost() const
  * \return raises an exception on error
  */
  std::string
  getHost() const;
  /**
  * \fn ~MachineClientServer()
  * \brief Destructor
  */
  ~MachineClientServer();

private:
   /////////////////////////////////
  // Attributes
  /////////////////////////////////
  /**
  * \brief The ssh key of the client machine
  */
  std::string mmachineSSHKey;
  /**
  * \brief The hostname of the client machine
  */
  std::string mhostname;
  /**
  * \brief An instance of vishnu database
  */
  Database *mdatabaseVishnu;

  /////////////////////////////////
  // Functions
  /////////////////////////////////
  /**
  * \brief Function to check the client machine on the database
  * \fn bool exist()
  * \return true if the machine exists on the database else false
  */
  bool exist();
};
#endif//MACHINE_CLIENT_SERVER_H
