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
 * UMS_Data/ConnectOptions.cpp
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

#include "ConnectOptions.hpp"
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "UMS_Data/UMS_DataPackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::UMS_Data;

// Default constructor
ConnectOptions::ConnectOptions() :
    m_closePolicy(0), m_sessionInactivityDelay(0)
{

    /*PROTECTED REGION ID(ConnectOptionsImpl__ConnectOptionsImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

ConnectOptions::~ConnectOptions()
{
}

/*PROTECTED REGION ID(ConnectOptions.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::UMS_Data::SessionCloseType ConnectOptions::getClosePolicy() const
{
    return m_closePolicy;
}

void ConnectOptions::setClosePolicy(::UMS_Data::SessionCloseType _closePolicy)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::UMS_Data::SessionCloseType _old_closePolicy = m_closePolicy;
#endif
    m_closePolicy = _closePolicy;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::UMS_Data::UMS_DataPackage::_instance()->getConnectOptions__closePolicy(),
                _old_closePolicy,
                m_closePolicy
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EInt ConnectOptions::getSessionInactivityDelay() const
{
    return m_sessionInactivityDelay;
}

void ConnectOptions::setSessionInactivityDelay(
        ::ecore::EInt _sessionInactivityDelay)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EInt _old_sessionInactivityDelay = m_sessionInactivityDelay;
#endif
    m_sessionInactivityDelay = _sessionInactivityDelay;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::UMS_Data::UMS_DataPackage::_instance()->getConnectOptions__sessionInactivityDelay(),
                _old_sessionInactivityDelay,
                m_sessionInactivityDelay
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& ConnectOptions::getSubstituteUserId() const
{
    return m_substituteUserId;
}

void ConnectOptions::setSubstituteUserId(
        ::ecore::EString const& _substituteUserId)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_substituteUserId = m_substituteUserId;
#endif
    m_substituteUserId = _substituteUserId;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::UMS_Data::UMS_DataPackage::_instance()->getConnectOptions__substituteUserId(),
                _old_substituteUserId,
                m_substituteUserId
        );
        eNotify(&notification);
    }
#endif
}

// References

