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
 * UMS_Data.hpp
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

#ifndef UMS_DATA_HPP
#define UMS_DATA_HPP

#include "UMS_Data_forward.hpp"
#include <ecorecpp/mapping.hpp>

// EPackage


// EClass
#include "UMS_Data/ConnectOptions.hpp"
#include "UMS_Data/Session.hpp"
#include "UMS_Data/ListSessions.hpp"
#include "UMS_Data/ListSessionOptions.hpp"
#include "UMS_Data/User.hpp"
#include "UMS_Data/ListUsers.hpp"
#include "UMS_Data/Command.hpp"
#include "UMS_Data/ListCommands.hpp"
#include "UMS_Data/ListCmdOptions.hpp"
#include "UMS_Data/LocalAccount.hpp"
#include "UMS_Data/ListLocalAccounts.hpp"
#include "UMS_Data/ListLocalAccOptions.hpp"
#include "UMS_Data/Machine.hpp"
#include "UMS_Data/ListMachines.hpp"
#include "UMS_Data/ListMachineOptions.hpp"
#include "UMS_Data/Configuration.hpp"
#include "UMS_Data/OptionValue.hpp"
#include "UMS_Data/ListOptionsValues.hpp"
#include "UMS_Data/ListOptOptions.hpp"

// Package & Factory
#include "UMS_Data/UMS_DataPackage.hpp"
#include "UMS_Data/UMS_DataFactory.hpp"

#endif // UMS_DATA_HPP
