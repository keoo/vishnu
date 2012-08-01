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

/**s
* \file CommandServer.hpp
* \brief This file presents the Class which manipulates Commands on server side.
* \author Eugène PAMBA CAPO-CHICHI (eugene.capochichi@sysfera.com)
* \date 31/01/2011
*/

#ifndef COMMAND_SERVER_H
#define COMMAND_SERVER_H

#include <string>
#include <iostream>
#include "SessionServer.hpp"

/**
* \class CommandServer
* \brief CommandServer class implementation
*/
class CommandServer {
public:
  /**
  * \brief Constructor
  * \fn CommandServer(SessionServer session)
  * \param session The object which encapsulates session data
  */
  CommandServer(SessionServer session);
  /**
  * \brief Constructor
  * \fn CommandServer(std::string cmd, SessionServer session)
  * \param cmd The cmd launched by the user
  * \param session The object which encapsulates session data
  */
	CommandServer(std::string cmd, SessionServer session);
  /**
  * \brief Function to get the command description
  * \fn    std::string getCommand()
  * \return the current command
  */
  std::string
  getCommand();
  /**
  * \brief Function to record the command on the database
  * \param cmdType The type of the command (UMS, TMS, FMS, IMS)
  * \param cmdStatus The status of the command
  * \param newVishnuObjectID the new vishnu object Id
  * \param startTime The start time of command
  * \param endTime The end time of command
  * \return raises an exception on error
  */
	int
	record(CmdType cmdType,
         vishnu::CmdStatus cmdStatus,
         std::string newVishnuObjectID = " ",
         std::string startTime = "CURRENT_TIMESTAMP",
         std::string endTime = "CURRENT_TIMESTAMP");
  /**
  * \brief Function to check if commands are running
  * \fn    bool isRunning()
  * \return true if commands are running else false
  */
  bool
  isRunning();
  /**
  * \brief Destructor
  * \fn    ~CommandServer()
  */
	~CommandServer();

  private:
  /**
  * \brief An instance of vishnu database
  */
  Database *mdatabaseVishnu;
  /**
  * \brief An object which encapsulates session data
  */
  SessionServer msessionServer;
  /**
  * \brief The command launched by the user
  */
  std::string mcommand;
};
#endif
