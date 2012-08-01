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
 * TMS_Data_forward.hpp
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

#ifndef _TMS_DATA_FORWARD_HPP
#define _TMS_DATA_FORWARD_HPP

#include <ecorecpp/mapping_forward.hpp>

/*PROTECTED REGION ID(TMS_Data_forward) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
// Additional headers here
/*PROTECTED REGION END*/

// EPackage


#include <ecore_forward.hpp> // for EDataTypes
namespace TMS_Data
{

    // EDataType
    /*PROTECTED REGION ID(TMS_Data_JobPriority) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    typedef int JobPriority;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(TMS_Data_JobStatus) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    typedef int JobStatus;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(TMS_Data_QueuePriority) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    typedef int QueuePriority;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(TMS_Data_QueueStatus) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    typedef int QueueStatus;
    /*PROTECTED REGION END*/

    // EClass

    // Job
    class Job;
    typedef Job* Job_ptr;

    // ListJobs
    class ListJobs;
    typedef ListJobs* ListJobs_ptr;

    // SubmitOptions
    class SubmitOptions;
    typedef SubmitOptions* SubmitOptions_ptr;

    // ListJobsOptions
    class ListJobsOptions;
    typedef ListJobsOptions* ListJobsOptions_ptr;

    // ProgressOptions
    class ProgressOptions;
    typedef ProgressOptions* ProgressOptions_ptr;

    // ListProgression
    class ListProgression;
    typedef ListProgression* ListProgression_ptr;

    // Progression
    class Progression;
    typedef Progression* Progression_ptr;

    // ListQueues
    class ListQueues;
    typedef ListQueues* ListQueues_ptr;

    // Queue
    class Queue;
    typedef Queue* Queue_ptr;

    // JobResult
    class JobResult;
    typedef JobResult* JobResult_ptr;

    // ListJobResults
    class ListJobResults;
    typedef ListJobResults* ListJobResults_ptr;

    // Package & Factory
    class TMS_DataFactory;
    typedef TMS_DataFactory * TMS_DataFactory_ptr;
    class TMS_DataPackage;
    typedef TMS_DataPackage * TMS_DataPackage_ptr;

    template< typename T, typename S >
    inline T* instanceOf(S* _s)
    {
        return dynamic_cast< T* > (_s);
    }

} // TMS_Data


#endif // _TMS_DATA_FORWARD_HPP
