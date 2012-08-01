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
 * TMS_Data/QueueImpl.cpp
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

#include "Queue.hpp"
#include <TMS_Data/TMS_DataPackage.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::TMS_Data;

/*PROTECTED REGION ID(QueueImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void Queue::_initialize()
{
    // Supertypes

    // Rerefences

    /*PROTECTED REGION ID(QueueImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject Queue::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::TMS_Data::TMS_DataPackage::QUEUE__NAME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any, m_name);
    }
        return _any;
    case ::TMS_Data::TMS_DataPackage::QUEUE__MAXJOBCPU:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EInt >::toAny(_any,
                m_maxJobCpu);
    }
        return _any;
    case ::TMS_Data::TMS_DataPackage::QUEUE__MAXPROCCPU:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EInt >::toAny(_any,
                m_maxProcCpu);
    }
        return _any;
    case ::TMS_Data::TMS_DataPackage::QUEUE__MEMORY:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EInt >::toAny(_any, m_memory);
    }
        return _any;
    case ::TMS_Data::TMS_DataPackage::QUEUE__WALLTIME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::ELong >::toAny(_any,
                m_wallTime);
    }
        return _any;
    case ::TMS_Data::TMS_DataPackage::QUEUE__NODE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EInt >::toAny(_any, m_node);
    }
        return _any;
    case ::TMS_Data::TMS_DataPackage::QUEUE__NBRUNNINGJOBS:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EInt >::toAny(_any,
                m_nbRunningJobs);
    }
        return _any;
    case ::TMS_Data::TMS_DataPackage::QUEUE__NBJOBSINQUEUE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EInt >::toAny(_any,
                m_nbJobsInQueue);
    }
        return _any;
    case ::TMS_Data::TMS_DataPackage::QUEUE__STATE:
    {
        ::ecorecpp::mapping::any_traits< ::TMS_Data::QueueStatus >::toAny(_any,
                m_state);
    }
        return _any;
    case ::TMS_Data::TMS_DataPackage::QUEUE__PRIORITY:
    {
        ::ecorecpp::mapping::any_traits< ::TMS_Data::QueuePriority >::toAny(
                _any, m_priority);
    }
        return _any;
    case ::TMS_Data::TMS_DataPackage::QUEUE__DESCRIPTION:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_description);
    }
        return _any;

    }
    throw "Error";
}

void Queue::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::TMS_Data::TMS_DataPackage::QUEUE__NAME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_name);
    }
        return;
    case ::TMS_Data::TMS_DataPackage::QUEUE__MAXJOBCPU:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EInt >::fromAny(_newValue,
                m_maxJobCpu);
    }
        return;
    case ::TMS_Data::TMS_DataPackage::QUEUE__MAXPROCCPU:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EInt >::fromAny(_newValue,
                m_maxProcCpu);
    }
        return;
    case ::TMS_Data::TMS_DataPackage::QUEUE__MEMORY:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EInt >::fromAny(_newValue,
                m_memory);
    }
        return;
    case ::TMS_Data::TMS_DataPackage::QUEUE__WALLTIME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::ELong >::fromAny(_newValue,
                m_wallTime);
    }
        return;
    case ::TMS_Data::TMS_DataPackage::QUEUE__NODE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EInt >::fromAny(_newValue,
                m_node);
    }
        return;
    case ::TMS_Data::TMS_DataPackage::QUEUE__NBRUNNINGJOBS:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EInt >::fromAny(_newValue,
                m_nbRunningJobs);
    }
        return;
    case ::TMS_Data::TMS_DataPackage::QUEUE__NBJOBSINQUEUE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EInt >::fromAny(_newValue,
                m_nbJobsInQueue);
    }
        return;
    case ::TMS_Data::TMS_DataPackage::QUEUE__STATE:
    {
        ::ecorecpp::mapping::any_traits< ::TMS_Data::QueueStatus >::fromAny(
                _newValue, m_state);
    }
        return;
    case ::TMS_Data::TMS_DataPackage::QUEUE__PRIORITY:
    {
        ::ecorecpp::mapping::any_traits< ::TMS_Data::QueuePriority >::fromAny(
                _newValue, m_priority);
    }
        return;
    case ::TMS_Data::TMS_DataPackage::QUEUE__DESCRIPTION:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_description);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean Queue::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::TMS_Data::TMS_DataPackage::QUEUE__NAME:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_name);
    case ::TMS_Data::TMS_DataPackage::QUEUE__MAXJOBCPU:
        return m_maxJobCpu != -1;
    case ::TMS_Data::TMS_DataPackage::QUEUE__MAXPROCCPU:
        return m_maxProcCpu != -1;
    case ::TMS_Data::TMS_DataPackage::QUEUE__MEMORY:
        return m_memory != -1;
    case ::TMS_Data::TMS_DataPackage::QUEUE__WALLTIME:
        return m_wallTime != -1;
    case ::TMS_Data::TMS_DataPackage::QUEUE__NODE:
        return m_node != -1;
    case ::TMS_Data::TMS_DataPackage::QUEUE__NBRUNNINGJOBS:
        return m_nbRunningJobs != 0;
    case ::TMS_Data::TMS_DataPackage::QUEUE__NBJOBSINQUEUE:
        return m_nbJobsInQueue != 0;
    case ::TMS_Data::TMS_DataPackage::QUEUE__STATE:
        return m_state != -1;
    case ::TMS_Data::TMS_DataPackage::QUEUE__PRIORITY:
        return m_priority != -1;
    case ::TMS_Data::TMS_DataPackage::QUEUE__DESCRIPTION:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_description);

    }
    throw "Error";
}

void Queue::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr Queue::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::TMS_Data::TMS_DataPackage_ptr > (::TMS_Data::TMS_DataPackage::_instance())->getQueue();
    return _eclass;
}

