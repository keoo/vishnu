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

// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * UMS_Data_forward.hpp
 * Copyright (C) Cátedra SAES-UMU 2010 <andres.senac@um.es>
 *
 * EMF4CPP is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EMF4CPP is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _UMS_DATA_FORWARD_HPP
#define _UMS_DATA_FORWARD_HPP

#include <ecorecpp/mapping_forward.hpp>

/*PROTECTED REGION ID(UMS_Data_forward) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
// Additional headers here
/*PROTECTED REGION END*/

// EPackage


#include <ecore_forward.hpp> // for EDataTypes
namespace UMS_Data
{

    // EDataType
    /*PROTECTED REGION ID(UMS_Data_SessionCloseType) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    typedef int SessionCloseType;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(UMS_Data_PrivilegeType) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    typedef int PrivilegeType;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(UMS_Data_StatusType) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    typedef int StatusType;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(UMS_Data_CommandStatusType) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    typedef int CommandStatusType;
    /*PROTECTED REGION END*/

    // EClass

    // ConnectOptions
    class ConnectOptions;
    typedef ConnectOptions* ConnectOptions_ptr;

    // Session
    class Session;
    typedef Session* Session_ptr;

    // ListSessions
    class ListSessions;
    typedef ListSessions* ListSessions_ptr;

    // ListSessionOptions
    class ListSessionOptions;
    typedef ListSessionOptions* ListSessionOptions_ptr;

    // User
    class User;
    typedef User* User_ptr;

    // ListUsers
    class ListUsers;
    typedef ListUsers* ListUsers_ptr;

    // Command
    class Command;
    typedef Command* Command_ptr;

    // ListCommands
    class ListCommands;
    typedef ListCommands* ListCommands_ptr;

    // ListCmdOptions
    class ListCmdOptions;
    typedef ListCmdOptions* ListCmdOptions_ptr;

    // LocalAccount
    class LocalAccount;
    typedef LocalAccount* LocalAccount_ptr;

    // ListLocalAccounts
    class ListLocalAccounts;
    typedef ListLocalAccounts* ListLocalAccounts_ptr;

    // ListLocalAccOptions
    class ListLocalAccOptions;
    typedef ListLocalAccOptions* ListLocalAccOptions_ptr;

    // Machine
    class Machine;
    typedef Machine* Machine_ptr;

    // ListMachines
    class ListMachines;
    typedef ListMachines* ListMachines_ptr;

    // ListMachineOptions
    class ListMachineOptions;
    typedef ListMachineOptions* ListMachineOptions_ptr;

    // Configuration
    class Configuration;
    typedef Configuration* Configuration_ptr;

    // OptionValue
    class OptionValue;
    typedef OptionValue* OptionValue_ptr;

    // ListOptionsValues
    class ListOptionsValues;
    typedef ListOptionsValues* ListOptionsValues_ptr;

    // ListOptOptions
    class ListOptOptions;
    typedef ListOptOptions* ListOptOptions_ptr;

    // Package & Factory
    class UMS_DataFactory;
    typedef UMS_DataFactory * UMS_DataFactory_ptr;
    class UMS_DataPackage;
    typedef UMS_DataPackage * UMS_DataPackage_ptr;

    template< typename T, typename S >
    inline T* instanceOf(S* _s)
    {
        return dynamic_cast< T* > (_s);
    }

} // UMS_Data


#endif // _UMS_DATA_FORWARD_HPP
