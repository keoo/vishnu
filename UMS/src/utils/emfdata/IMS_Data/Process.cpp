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
 * IMS_Data/Process.cpp
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

#include "Process.hpp"
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "IMS_Data/IMS_DataPackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::IMS_Data;

// Default constructor
Process::Process() :
    m_processName(""), m_machineId(""), m_dietId(""), m_state(0),
            m_timestamp(0), m_script("")
{

    /*PROTECTED REGION ID(ProcessImpl__ProcessImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

Process::~Process()
{
}

/*PROTECTED REGION ID(Process.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::EString const& Process::getProcessName() const
{
    return m_processName;
}

void Process::setProcessName(::ecore::EString const& _processName)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_processName = m_processName;
#endif
    m_processName = _processName;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::IMS_Data::IMS_DataPackage::_instance()->getProcess__processName(),
                _old_processName,
                m_processName
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& Process::getMachineId() const
{
    return m_machineId;
}

void Process::setMachineId(::ecore::EString const& _machineId)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_machineId = m_machineId;
#endif
    m_machineId = _machineId;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::IMS_Data::IMS_DataPackage::_instance()->getProcess__machineId(),
                _old_machineId,
                m_machineId
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& Process::getDietId() const
{
    return m_dietId;
}

void Process::setDietId(::ecore::EString const& _dietId)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_dietId = m_dietId;
#endif
    m_dietId = _dietId;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::IMS_Data::IMS_DataPackage::_instance()->getProcess__dietId(),
                _old_dietId,
                m_dietId
        );
        eNotify(&notification);
    }
#endif
}

::IMS_Data::ProcessState Process::getState() const
{
    return m_state;
}

void Process::setState(::IMS_Data::ProcessState _state)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::IMS_Data::ProcessState _old_state = m_state;
#endif
    m_state = _state;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::IMS_Data::IMS_DataPackage::_instance()->getProcess__state(),
                _old_state,
                m_state
        );
        eNotify(&notification);
    }
#endif
}

::ecore::ELong Process::getTimestamp() const
{
    return m_timestamp;
}

void Process::setTimestamp(::ecore::ELong _timestamp)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::ELong _old_timestamp = m_timestamp;
#endif
    m_timestamp = _timestamp;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::IMS_Data::IMS_DataPackage::_instance()->getProcess__timestamp(),
                _old_timestamp,
                m_timestamp
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& Process::getScript() const
{
    return m_script;
}

void Process::setScript(::ecore::EString const& _script)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_script = m_script;
#endif
    m_script = _script;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::IMS_Data::IMS_DataPackage::_instance()->getProcess__script(),
                _old_script,
                m_script
        );
        eNotify(&notification);
    }
#endif
}

// References

