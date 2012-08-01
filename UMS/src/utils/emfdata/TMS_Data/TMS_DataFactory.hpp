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
 * TMS_Data/TMS_DataFactory.hpp
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

/**
 * \file TMS_DataFactory.hpp
 * \brief The TMS_DataFactory class
 * \author Generated file
 * \date 31/03/2011
 */
#ifndef _TMS_DATAFACTORY_HPP
#define _TMS_DATAFACTORY_HPP

#include <ecore/EFactory.hpp>
#include <TMS_Data.hpp>

namespace TMS_Data
{
    /**
     * \class TMS_DataFactory
     * \brief The factory class for generated model TMS_Data
     */
    class TMS_DataFactory: public virtual ::ecore::EFactory
    {
    public:

        /**
         * \brief To get the instance of the singleton
         * \return Pointer to the instance
         */
        static TMS_DataFactory_ptr _instance();

        /**
         * \brief Creates a new object of class Job
         * \return Pointer to the object
         */
        virtual Job_ptr createJob();
        /**
         * \brief Creates a new object of class ListJobs
         * \return Pointer to the object
         */
        virtual ListJobs_ptr createListJobs();
        /**
         * \brief Creates a new object of class SubmitOptions
         * \return Pointer to the object
         */
        virtual SubmitOptions_ptr createSubmitOptions();
        /**
         * \brief Creates a new object of class ListJobsOptions
         * \return Pointer to the object
         */
        virtual ListJobsOptions_ptr createListJobsOptions();
        /**
         * \brief Creates a new object of class ProgressOptions
         * \return Pointer to the object
         */
        virtual ProgressOptions_ptr createProgressOptions();
        /**
         * \brief Creates a new object of class ListProgression
         * \return Pointer to the object
         */
        virtual ListProgression_ptr createListProgression();
        /**
         * \brief Creates a new object of class Progression
         * \return Pointer to the object
         */
        virtual Progression_ptr createProgression();
        /**
         * \brief Creates a new object of class ListQueues
         * \return Pointer to the object
         */
        virtual ListQueues_ptr createListQueues();
        /**
         * \brief Creates a new object of class Queue
         * \return Pointer to the object
         */
        virtual Queue_ptr createQueue();
        /**
         * \brief Creates a new object of class JobResult
         * \return Pointer to the object
         */
        virtual JobResult_ptr createJobResult();
        /**
         * \brief Creates a new object of class ListJobResults
         * \return Pointer to the object
         */
        virtual ListJobResults_ptr createListJobResults();

        /**
         * \brief To create an object of a given class (reflective API)
         * \param _eClass The class object to create (obtained using the Package class)
         * \return Generic pointer to the object
         */
        virtual ::ecore::EObject_ptr create(::ecore::EClass_ptr _eClass);

        /**
         * \brief To create an object from a string (deserialize)
         * \param _eDataType The datatype
         * \param _literalValue The string
         * \return Generic pointer to the object
         */
        virtual ::ecore::EJavaObject createFromString(
                ::ecore::EDataType_ptr _eDataType,
                ::ecore::EString const& _literalValue);

        /**
         * \brief To convert an object to a string (serialize)
         * \param _eDataType The datatype
         * \param _instanceValue Value of the instance
         * \return The object serialized in a string
         */
        virtual ::ecore::EString convertToString(
                ::ecore::EDataType_ptr _eDataType,
                ::ecore::EJavaObject const& _instanceValue);

    protected:

        /**
         * \brief The instance of the singleton
         */
        static std::auto_ptr< TMS_DataFactory > s_instance;

        /**
         * \brief Constructor
         */
        TMS_DataFactory();

    };

} // TMS_Data


#endif // _TMS_DATAFACTORY_HPP
