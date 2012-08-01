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
 * UMS_Data/ConfigurationImpl.cpp
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

#include "Configuration.hpp"
#include <UMS_Data/UMS_DataPackage.hpp>
#include <UMS_Data/User.hpp>
#include <UMS_Data/Machine.hpp>
#include <UMS_Data/LocalAccount.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::UMS_Data;

/*PROTECTED REGION ID(ConfigurationImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void Configuration::_initialize()
{
    // Supertypes

    // Rerefences
    for (size_t i = 0; i < m_listConfUsers->size(); i++)
    {
        (*m_listConfUsers)[i]->_initialize();
        (*m_listConfUsers)[i]->_setEContainer(
                this,
                ::UMS_Data::UMS_DataPackage::_instance()->getConfiguration__listConfUsers());
    }
    for (size_t i = 0; i < m_listConfMachines->size(); i++)
    {
        (*m_listConfMachines)[i]->_initialize();
        (*m_listConfMachines)[i]->_setEContainer(
                this,
                ::UMS_Data::UMS_DataPackage::_instance()->getConfiguration__listConfMachines());
    }
    for (size_t i = 0; i < m_listConfLocalAccounts->size(); i++)
    {
        (*m_listConfLocalAccounts)[i]->_initialize();
        (*m_listConfLocalAccounts)[i]->_setEContainer(
                this,
                ::UMS_Data::UMS_DataPackage::_instance()->getConfiguration__listConfLocalAccounts());
    }

    /*PROTECTED REGION ID(ConfigurationImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject Configuration::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::UMS_Data::UMS_DataPackage::CONFIGURATION__LISTCONFUSERS:
    {
        _any = m_listConfUsers->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::UMS_Data::UMS_DataPackage::CONFIGURATION__LISTCONFMACHINES:
    {
        _any = m_listConfMachines->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::UMS_Data::UMS_DataPackage::CONFIGURATION__LISTCONFLOCALACCOUNTS:
    {
        _any = m_listConfLocalAccounts->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::UMS_Data::UMS_DataPackage::CONFIGURATION__FILEPATH:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_filePath);
    }
        return _any;

    }
    throw "Error";
}

void Configuration::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::UMS_Data::UMS_DataPackage::CONFIGURATION__LISTCONFUSERS:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::UMS_Data::Configuration::getListConfUsers().clear();
        ::UMS_Data::Configuration::getListConfUsers().insert_all(*_t0);
    }
        return;
    case ::UMS_Data::UMS_DataPackage::CONFIGURATION__LISTCONFMACHINES:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::UMS_Data::Configuration::getListConfMachines().clear();
        ::UMS_Data::Configuration::getListConfMachines().insert_all(*_t0);
    }
        return;
    case ::UMS_Data::UMS_DataPackage::CONFIGURATION__LISTCONFLOCALACCOUNTS:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::UMS_Data::Configuration::getListConfLocalAccounts().clear();
        ::UMS_Data::Configuration::getListConfLocalAccounts().insert_all(*_t0);
    }
        return;
    case ::UMS_Data::UMS_DataPackage::CONFIGURATION__FILEPATH:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_filePath);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean Configuration::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::UMS_Data::UMS_DataPackage::CONFIGURATION__LISTCONFUSERS:
        return m_listConfUsers && m_listConfUsers->size();
    case ::UMS_Data::UMS_DataPackage::CONFIGURATION__LISTCONFMACHINES:
        return m_listConfMachines && m_listConfMachines->size();
    case ::UMS_Data::UMS_DataPackage::CONFIGURATION__LISTCONFLOCALACCOUNTS:
        return m_listConfLocalAccounts && m_listConfLocalAccounts->size();
    case ::UMS_Data::UMS_DataPackage::CONFIGURATION__FILEPATH:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_filePath);

    }
    throw "Error";
}

void Configuration::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr Configuration::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::UMS_Data::UMS_DataPackage_ptr > (::UMS_Data::UMS_DataPackage::_instance())->getConfiguration();
    return _eclass;
}

