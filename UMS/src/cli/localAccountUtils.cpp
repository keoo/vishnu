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
 * \file localAccountUtils.cpp
 * \brief This file defines useful functions and types for the VISHNU local account commands
 *  command
 * \author Ibrahima Cisse (ibrahima.cisse@sysfera.com)
 */



#include "Options.hpp"

#include "connectUtils.hpp"
#include "localAccountUtils.hpp"
#include<iostream>
using namespace std;
/**
 * \brief To build options for the VISHNU local account commands
 * \param pgName : The name of the command
 * \param fUserId: The user identifier option callback
 * \param dietConfig: Represents the VISHNU config file
 * \param fMachineId: The machine identifier option callback 
 * \param fAcLogin: The user login option callback
 * \param fSshKeyPath: The user ssh key path option callback
 * \param fHomeDirectory: The user home directory option callback
 * \param type: Indicates if it is an add or an update command, 0 means update, and 1 means add
 * \return The description of all options allowed by the command
 */

boost::shared_ptr<Options>
makeLocalAccountOptions(std::string pgName,StringcallBackType& fUserId,
                        std::string & dietConfig, StringcallBackType & fMachineId,
                        StringcallBackType& fAcLogin, StringcallBackType& fSshKeyPath,
                        StringcallBackType & fHomeDirectory, int type){

  boost::shared_ptr<Options> opt=makeConnectOptions(pgName,fUserId,1,dietConfig);

  opt->setPosition("userId",1);

  Group_type group=CONFIG;

  if(type){// type =0 for "update function" and type=1 for "add function"

    group=HIDDEN;
  }



  opt->add("machineId",
           "the identifier of the machine associated to the local user configuration",
           HIDDEN,
           fMachineId,
           1);


  opt->setPosition("machineId",1);

  opt->add("acLogin,l",
           "login of the user on the associated machine",
           group,
           fAcLogin,
           type);

  if (type){
    opt->setPosition("acLogin",1);
  }

  opt->add("sshKeyPath,s",
           "The path of the ssh key of the user on the associated machine",
           group,
           fSshKeyPath,
           type);

  if (type){
    opt->setPosition("sshKeyPath",1);
  }

  opt->add("homeDirectory,d",
           "The path of the home directory of the user on the associated machine",
           group,
           fHomeDirectory,
           type);

  if (type){
    opt->setPosition("homeDirectory",1);
  }

  return opt;



}






