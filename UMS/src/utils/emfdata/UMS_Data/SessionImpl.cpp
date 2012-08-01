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
 * UMS_Data/SessionImpl.cpp
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

#include "Session.hpp"
#include <UMS_Data/UMS_DataPackage.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::UMS_Data;

/*PROTECTED REGION ID(SessionImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void Session::_initialize()
{
    // Supertypes

    // Rerefences

    /*PROTECTED REGION ID(SessionImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject Session::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::UMS_Data::UMS_DataPackage::SESSION__SESSIONID:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_sessionId);
    }
        return _any;
    case ::UMS_Data::UMS_DataPackage::SESSION__USERID:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_userId);
    }
        return _any;
    case ::UMS_Data::UMS_DataPackage::SESSION__SESSIONKEY:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_sessionKey);
    }
        return _any;
    case ::UMS_Data::UMS_DataPackage::SESSION__DATELASTCONNECT:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::ELong >::toAny(_any,
                m_dateLastConnect);
    }
        return _any;
    case ::UMS_Data::UMS_DataPackage::SESSION__DATECREATION:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::ELong >::toAny(_any,
                m_dateCreation);
    }
        return _any;
    case ::UMS_Data::UMS_DataPackage::SESSION__DATECLOSURE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::ELong >::toAny(_any,
                m_dateClosure);
    }
        return _any;
    case ::UMS_Data::UMS_DataPackage::SESSION__STATUS:
    {
        ::ecorecpp::mapping::any_traits< ::UMS_Data::StatusType >::toAny(_any,
                m_status);
    }
        return _any;
    case ::UMS_Data::UMS_DataPackage::SESSION__CLOSEPOLICY:
    {
        ::ecorecpp::mapping::any_traits< ::UMS_Data::SessionCloseType >::toAny(
                _any, m_closePolicy);
    }
        return _any;
    case ::UMS_Data::UMS_DataPackage::SESSION__TIMEOUT:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::ELong >::toAny(_any,
                m_timeout);
    }
        return _any;

    }
    throw "Error";
}

void Session::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::UMS_Data::UMS_DataPackage::SESSION__SESSIONID:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_sessionId);
    }
        return;
    case ::UMS_Data::UMS_DataPackage::SESSION__USERID:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_userId);
    }
        return;
    case ::UMS_Data::UMS_DataPackage::SESSION__SESSIONKEY:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_sessionKey);
    }
        return;
    case ::UMS_Data::UMS_DataPackage::SESSION__DATELASTCONNECT:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::ELong >::fromAny(_newValue,
                m_dateLastConnect);
    }
        return;
    case ::UMS_Data::UMS_DataPackage::SESSION__DATECREATION:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::ELong >::fromAny(_newValue,
                m_dateCreation);
    }
        return;
    case ::UMS_Data::UMS_DataPackage::SESSION__DATECLOSURE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::ELong >::fromAny(_newValue,
                m_dateClosure);
    }
        return;
    case ::UMS_Data::UMS_DataPackage::SESSION__STATUS:
    {
        ::ecorecpp::mapping::any_traits< ::UMS_Data::StatusType >::fromAny(
                _newValue, m_status);
    }
        return;
    case ::UMS_Data::UMS_DataPackage::SESSION__CLOSEPOLICY:
    {
        ::ecorecpp::mapping::any_traits< ::UMS_Data::SessionCloseType >::fromAny(
                _newValue, m_closePolicy);
    }
        return;
    case ::UMS_Data::UMS_DataPackage::SESSION__TIMEOUT:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::ELong >::fromAny(_newValue,
                m_timeout);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean Session::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::UMS_Data::UMS_DataPackage::SESSION__SESSIONID:
        return m_sessionId != "";
    case ::UMS_Data::UMS_DataPackage::SESSION__USERID:
        return m_userId != "";
    case ::UMS_Data::UMS_DataPackage::SESSION__SESSIONKEY:
        return m_sessionKey != "";
    case ::UMS_Data::UMS_DataPackage::SESSION__DATELASTCONNECT:
        return m_dateLastConnect != -1;
    case ::UMS_Data::UMS_DataPackage::SESSION__DATECREATION:
        return m_dateCreation != -1;
    case ::UMS_Data::UMS_DataPackage::SESSION__DATECLOSURE:
        return m_dateClosure != -1;
    case ::UMS_Data::UMS_DataPackage::SESSION__STATUS:
        return m_status != 1;
    case ::UMS_Data::UMS_DataPackage::SESSION__CLOSEPOLICY:
        return m_closePolicy != 0;
    case ::UMS_Data::UMS_DataPackage::SESSION__TIMEOUT:
        return m_timeout != 0;

    }
    throw "Error";
}

void Session::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr Session::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::UMS_Data::UMS_DataPackage_ptr > (::UMS_Data::UMS_DataPackage::_instance())->getSession();
    return _eclass;
}

