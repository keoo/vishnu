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
* \file MachineClientServer.cpp
* \brief This file implements the Class which manipulates the VISHNU client machine data on server side.
* \author Eugène PAMBA CAPO-CHICHI (eugene.capochichi@sysfera.com)
* \date 31/01/2011
*/

#include <boost/scoped_ptr.hpp>
#include "MachineClientServer.hpp"
#include "POSTGREDatabase.hpp"
#include "DbFactory.hpp"
#include "DatabaseResult.hpp"
#include "utilVishnu.hpp"

/**
* \brief Constructor
* \fn MachineClientServer(std::string sshKey, std::string host)
* \param sshKey The ssh key of the client machine
* \param host The name of the client host
*/
MachineClientServer::MachineClientServer(std::string sshKey, std::string host) {
  DbFactory factory;
  mmachineSSHKey = sshKey;
  mhostname = host;
  mdatabaseVishnu = factory.getDatabaseInstance();
}

/**
* \brief Function to record the client machine on the database
* \fn int recordMachineClient()
* \return raises an exception on error
*/
int MachineClientServer::recordMachineClient() {

  //If the machine is not on the database
  if (!exist()) {
    std::string sqlCmd = std::string("insert into clmachine (sshkey, name) values ('");
    sqlCmd.append(mmachineSSHKey+"','");
    sqlCmd.append(mhostname+"')");

    mdatabaseVishnu->process(sqlCmd.c_str());

  } //End if the machine is not on the database
  else {
  }
  return 0;
}

/**
* \brief Function to get the id number of the client machine
* \fn std::string getId()
* \return raises an exception on error
*/
std::string
MachineClientServer::getId() {

  std::string sqlCommand("SELECT numclmachineid FROM clmachine where sshkey='");
  sqlCommand.append(mmachineSSHKey+ "' and name='");
  sqlCommand.append(mhostname+"'");

  boost::scoped_ptr<DatabaseResult> result(mdatabaseVishnu->getResult(sqlCommand.c_str()));
  return result->getFirstElement();
}
/**
* \brief Function to get the ssh key of the client machine
* \fn std::string getSSHKey()
* \return raises an exception on error
*/
std::string MachineClientServer::getSSHKey() const{
  return mmachineSSHKey;
}

/**
* \brief Function to get the hostname of the client machine
* \fn std::string getHost()
* \return raises an exception on error
*/
std::string MachineClientServer::getHost() const{
  return mhostname;
}
/**
* \fn ~MachineClientServer()
* \brief Destructor
*/
MachineClientServer::~MachineClientServer() {
}

/**
* \brief Function to check the client machine on the database
* \fn bool exist()
* \return true if the machine exists on the database else false
*/
bool MachineClientServer::exist(){
  return (getId().size() != 0);
}

