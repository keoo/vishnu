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
 * \file utils.hpp
 * \brief this file contains a declaration of helper functions used by the command line interface 
 * \authors Daouda Traore (daouda.traore@sysfera.com) and Ibrahima Cisse (ibrahima.cisse@sysfera.com)
 */


#ifndef CLIUTILS_HPP
#define CLIUTILS_HPP

#include "UMS_Data.hpp"
#include "user.pb.h"
#include <iostream>


class Options;


/**
 * \brief Display a '-' caracter 
 * \param size: The number of '-' to diplay
 * \param os The output stream in which the display will be done.
 */

void 
setFill(int size, std::ostream& os) ;

/**
 * \brief Helper function to display a session
 * \param os: An output stream in which the session will be printed 
 * \param session: The session to display
 * \return The output stream in which the session has been printed
 */



std::ostream&
operator<<(std::ostream& os, const UMS_Data::Session_ptr& session);

/**
 * \brief Helper function to display a list of session
 * \param os: The output stream in which the list will be printed 
 * \param listSession: The list to display
 * \return The output stream in which the list of sessions has been printed
 */

std::ostream&
operator<<(std::ostream& os, UMS_Data::ListSessions& listSession);

/**
 * \brief Helper function to display a local account
 * \param os: The output stream in which the local account will be printed 
 * \param account: The local account  to display
 * \return The output stream in which the local account has been printed
 */


std::ostream&
operator<<(std::ostream& os, const UMS_Data::LocalAccount_ptr& account);

/**
 * \brief Helper function to display a list of local accounts
 * \param os: The output stream in which the list will be printed 
 * \param lsLocalAccounts: The list to display
 * \return The output stream in which the list of local accounts has been printed
 */


std::ostream&
operator<<(std::ostream& os, UMS_Data::ListLocalAccounts& lsLocalAccounts);


/**
 * \brief Helper function to display a machine 
 * \param os: The output stream in which the machine will be printed 
 * \param machine: The machine  to display
 * \return The output stream in which the machine has been printed
 */



std::ostream&
operator<<(std::ostream& os, const UMS_Data::Machine_ptr& machine);


/**
 * \brief Helper function to display a list of machines
 * \param os: The output stream in which the list will be printed 
 * \param lsMachine: The list to display
 * \return The output stream in which the list of machines has been printed
 */

std::ostream&
operator<<(std::ostream& os, UMS_Data::ListMachines& lsMachine);


/**
 * \brief Helper function to display a command 
 * \param os: The output stream in which the command will be printed 
 * \param command: The command  to display
 * \return The output stream in which the command has been printed
 */


std::ostream&
operator<<(std::ostream& os, const UMS_Data::Command_ptr& command);

/**
 * \brief Helper function to display a list of command
 * \param os: The output stream in which the list will be printed 
 * \param lsCommand: The list to display
 * \return The output stream in which the list of command has been printed
 */


std::ostream& 
operator<<(std::ostream& os, UMS_Data::ListCommands& lsCommand);

/**
 * \brief Helper function to display an option value
 * \param os: The output stream in which the option value will be printed 
 * \param optionValue: The option value to display
 * \return The output stream in which the option value has been printed
 */



std::ostream&
operator<<(std::ostream& os,const UMS_Data::OptionValue_ptr& optionValue);

/**
 * \brief Helper function to display a list of options
 * \param os: The output stream in which the list will be printed 
 * \param lsOptions: The list to display
 * \return The output stream in which the list of options has been printed
 */


std::ostream&
operator<<(std::ostream& os, UMS_Data::ListOptionsValues& lsOptions);

/**
 * \brief Helper function to display a user
 * \param os: The output stream in which the user will be printed 
 * \param user: The user to display
 * \return The output stream in which the user has been printed
 */

std::ostream&
operator<<(std::ostream& os, const UMS_Data::User_ptr& user);

/**
 * \brief Helper function to display a list of users
 * \param os: The output stream in which the list will be printed 
 * \param lsUsers: The list to display
 * \return The output stream in which the list of users has been printed
 */

std::ostream&
operator<<(std::ostream& os, const UMS_Data::ListUsers& lsUsers);

/**
 * \brief Helper function to display a user
 * \param os: The output stream in which the user will be printed 
 * \param user: The user to display
 * \return The output stream in which the user has been printed
 */

std::ostream&
operator<<(std::ostream& os, const UMS_Data_Proto::User& user);

/**
 * \brief Helper function to display a list of users
 * \param os: The output stream in which the list will be printed 
 * \param lsUsers: The list to display
 * \return The output stream in which the list of users has been printed
 */

std::ostream&
operator<<(std::ostream& os, const UMS_Data_Proto::ListUsers& lsUsers);


#endif
