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
 * TMS_Data/ListJobs.cpp
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

#include "ListJobs.hpp"
#include <TMS_Data/Job.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "TMS_Data/TMS_DataPackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::TMS_Data;

// Default constructor
ListJobs::ListJobs() :
    m_nbJobs(0), m_nbRunningJobs(0), m_nbWaitingJobs(0)
{

    m_jobs.reset(new ::ecorecpp::mapping::ReferenceEListImpl< ::TMS_Data::Job,
            -1, true, false >(this, NULL));

    /*PROTECTED REGION ID(ListJobsImpl__ListJobsImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

ListJobs::~ListJobs()
{
}

/*PROTECTED REGION ID(ListJobs.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::ELong ListJobs::getNbJobs() const
{
    return m_nbJobs;
}

void ListJobs::setNbJobs(::ecore::ELong _nbJobs)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::ELong _old_nbJobs = m_nbJobs;
#endif
    m_nbJobs = _nbJobs;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::TMS_Data::TMS_DataPackage::_instance()->getListJobs__nbJobs(),
                _old_nbJobs,
                m_nbJobs
        );
        eNotify(&notification);
    }
#endif
}

::ecore::ELong ListJobs::getNbRunningJobs() const
{
    return m_nbRunningJobs;
}

void ListJobs::setNbRunningJobs(::ecore::ELong _nbRunningJobs)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::ELong _old_nbRunningJobs = m_nbRunningJobs;
#endif
    m_nbRunningJobs = _nbRunningJobs;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::TMS_Data::TMS_DataPackage::_instance()->getListJobs__nbRunningJobs(),
                _old_nbRunningJobs,
                m_nbRunningJobs
        );
        eNotify(&notification);
    }
#endif
}

::ecore::ELong ListJobs::getNbWaitingJobs() const
{
    return m_nbWaitingJobs;
}

void ListJobs::setNbWaitingJobs(::ecore::ELong _nbWaitingJobs)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::ELong _old_nbWaitingJobs = m_nbWaitingJobs;
#endif
    m_nbWaitingJobs = _nbWaitingJobs;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::TMS_Data::TMS_DataPackage::_instance()->getListJobs__nbWaitingJobs(),
                _old_nbWaitingJobs,
                m_nbWaitingJobs
        );
        eNotify(&notification);
    }
#endif
}

// References
::ecorecpp::mapping::EList< ::TMS_Data::Job >& ListJobs::getJobs()
{
    return *m_jobs;
}

