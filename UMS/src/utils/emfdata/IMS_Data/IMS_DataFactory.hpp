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
 * IMS_Data/IMS_DataFactory.hpp
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
 * \file IMS_DataFactory.hpp
 * \brief The IMS_DataFactory class
 * \author Generated file
 * \date 31/03/2011
 */
#ifndef _IMS_DATAFACTORY_HPP
#define _IMS_DATAFACTORY_HPP

#include <ecore/EFactory.hpp>
#include <IMS_Data.hpp>

namespace IMS_Data
{
    /**
     * \class IMS_DataFactory
     * \brief The factory class for generated model IMS_Data
     */
    class IMS_DataFactory: public virtual ::ecore::EFactory
    {
    public:

        /**
         * \brief To get the instance of the singleton
         * \return Pointer to the instance
         */
        static IMS_DataFactory_ptr _instance();

        /**
         * \brief Creates a new object of class Metric
         * \return Pointer to the object
         */
        virtual Metric_ptr createMetric();
        /**
         * \brief Creates a new object of class ListMetric
         * \return Pointer to the object
         */
        virtual ListMetric_ptr createListMetric();
        /**
         * \brief Creates a new object of class ListProcesses
         * \return Pointer to the object
         */
        virtual ListProcesses_ptr createListProcesses();
        /**
         * \brief Creates a new object of class SystemInfo
         * \return Pointer to the object
         */
        virtual SystemInfo_ptr createSystemInfo();
        /**
         * \brief Creates a new object of class Process
         * \return Pointer to the object
         */
        virtual Process_ptr createProcess();
        /**
         * \brief Creates a new object of class ExportOp
         * \return Pointer to the object
         */
        virtual ExportOp_ptr createExportOp();
        /**
         * \brief Creates a new object of class MetricHistOp
         * \return Pointer to the object
         */
        virtual MetricHistOp_ptr createMetricHistOp();
        /**
         * \brief Creates a new object of class RestartOp
         * \return Pointer to the object
         */
        virtual RestartOp_ptr createRestartOp();
        /**
         * \brief Creates a new object of class CurMetricOp
         * \return Pointer to the object
         */
        virtual CurMetricOp_ptr createCurMetricOp();
        /**
         * \brief Creates a new object of class ProcessOp
         * \return Pointer to the object
         */
        virtual ProcessOp_ptr createProcessOp();
        /**
         * \brief Creates a new object of class ThresholdOp
         * \return Pointer to the object
         */
        virtual ThresholdOp_ptr createThresholdOp();
        /**
         * \brief Creates a new object of class ListThreshold
         * \return Pointer to the object
         */
        virtual ListThreshold_ptr createListThreshold();
        /**
         * \brief Creates a new object of class Threshold
         * \return Pointer to the object
         */
        virtual Threshold_ptr createThreshold();
        /**
         * \brief Creates a new object of class SysInfoOp
         * \return Pointer to the object
         */
        virtual SysInfoOp_ptr createSysInfoOp();
        /**
         * \brief Creates a new object of class ListSysInfo
         * \return Pointer to the object
         */
        virtual ListSysInfo_ptr createListSysInfo();

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
        static std::auto_ptr< IMS_DataFactory > s_instance;

        /**
         * \brief Constructor
         */
        IMS_DataFactory();

    };

} // IMS_Data


#endif // _IMS_DATAFACTORY_HPP
