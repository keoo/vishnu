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
 * FMS_Data/FileTransferImpl.cpp
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

#include "FileTransfer.hpp"
#include <FMS_Data/FMS_DataPackage.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::FMS_Data;

/*PROTECTED REGION ID(FileTransferImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void FileTransfer::_initialize()
{
    // Supertypes

    // Rerefences

    /*PROTECTED REGION ID(FileTransferImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject FileTransfer::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__TRANSFERID:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_transferId);
    }
        return _any;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__STATUS:
    {
        ::ecorecpp::mapping::any_traits< ::FMS_Data::Status >::toAny(_any,
                m_status);
    }
        return _any;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__USERID:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_userId);
    }
        return _any;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__CLIENTMACHINEID:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_clientMachineId);
    }
        return _any;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__SOURCEMACHINEID:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_sourceMachineId);
    }
        return _any;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__DESTINATIONMACHINEID:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_destinationMachineId);
    }
        return _any;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__SOURCEFILEPATH:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_sourceFilePath);
    }
        return _any;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__DESTINATIONFILEPATH:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_destinationFilePath);
    }
        return _any;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__SIZE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::ELong >::toAny(_any, m_size);
    }
        return _any;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__START_TIME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::ELong >::toAny(_any,
                m_start_time);
    }
        return _any;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__TRCOMMAND:
    {
        ::ecorecpp::mapping::any_traits< ::FMS_Data::TransferCommand >::toAny(
                _any, m_trCommand);
    }
        return _any;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__ERRORMSG:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_errorMsg);
    }
        return _any;

    }
    throw "Error";
}

void FileTransfer::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__TRANSFERID:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_transferId);
    }
        return;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__STATUS:
    {
        ::ecorecpp::mapping::any_traits< ::FMS_Data::Status >::fromAny(
                _newValue, m_status);
    }
        return;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__USERID:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_userId);
    }
        return;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__CLIENTMACHINEID:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_clientMachineId);
    }
        return;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__SOURCEMACHINEID:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_sourceMachineId);
    }
        return;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__DESTINATIONMACHINEID:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_destinationMachineId);
    }
        return;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__SOURCEFILEPATH:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_sourceFilePath);
    }
        return;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__DESTINATIONFILEPATH:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_destinationFilePath);
    }
        return;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__SIZE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::ELong >::fromAny(_newValue,
                m_size);
    }
        return;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__START_TIME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::ELong >::fromAny(_newValue,
                m_start_time);
    }
        return;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__TRCOMMAND:
    {
        ::ecorecpp::mapping::any_traits< ::FMS_Data::TransferCommand >::fromAny(
                _newValue, m_trCommand);
    }
        return;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__ERRORMSG:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_errorMsg);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean FileTransfer::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__TRANSFERID:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_transferId);
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__STATUS:
        return m_status != 4;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__USERID:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_userId);
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__CLIENTMACHINEID:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_clientMachineId);
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__SOURCEMACHINEID:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_sourceMachineId);
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__DESTINATIONMACHINEID:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_destinationMachineId);
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__SOURCEFILEPATH:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_sourceFilePath);
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__DESTINATIONFILEPATH:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_destinationFilePath);
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__SIZE:
        return ::ecorecpp::mapping::set_traits< ::ecore::ELong >::is_set(m_size);
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__START_TIME:
        return m_start_time != 0;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__TRCOMMAND:
        return m_trCommand != 2;
    case ::FMS_Data::FMS_DataPackage::FILETRANSFER__ERRORMSG:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_errorMsg);

    }
    throw "Error";
}

void FileTransfer::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr FileTransfer::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::FMS_Data::FMS_DataPackage_ptr > (::FMS_Data::FMS_DataPackage::_instance())->getFileTransfer();
    return _eclass;
}

