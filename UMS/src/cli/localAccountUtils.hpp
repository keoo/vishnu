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
 * \file localAccountUtils.hpp
 * \brief This file declares useful functions and types for the VISHNU local account commands
 *  command
 * \author Ibrahima Cisse (ibrahima.cisse@sysfera.com)
 */


#ifndef LOCALACCOUNTUTILS__HH
#define LOCALACCOUNTUTILS__HH


//VISHNU Headers

#include "common.hpp"

//Boost Headers

#include<boost/function.hpp>


class Options;

/**
 * \brief A convenient function type taking a string parameter and
 * without return value
 */

typedef
boost::function1<void,std::string> StringcallBackType;


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
                        StringcallBackType & fHomeDirectory, int type=0);






#endif



