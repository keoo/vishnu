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
 * IMS_Data_forward.hpp
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

#ifndef _IMS_DATA_FORWARD_HPP
#define _IMS_DATA_FORWARD_HPP

#include <ecorecpp/mapping_forward.hpp>

/*PROTECTED REGION ID(IMS_Data_forward) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
// Additional headers here
/*PROTECTED REGION END*/

// EPackage


#include <ecore_forward.hpp> // for EDataTypes
namespace IMS_Data
{

    // EDataType
    /*PROTECTED REGION ID(IMS_Data_MetricType) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    typedef int MetricType;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(IMS_Data_LoadShedType) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    typedef int LoadShedType;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(IMS_Data_ExportType) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    typedef int ExportType;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(IMS_Data_ProcessState) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    typedef int ProcessState;
    /*PROTECTED REGION END*/
    /*PROTECTED REGION ID(IMS_Data_SeDType) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    typedef int SeDType;
    /*PROTECTED REGION END*/

    // EClass

    // Metric
    class Metric;
    typedef Metric* Metric_ptr;

    // ListMetric
    class ListMetric;
    typedef ListMetric* ListMetric_ptr;

    // ListProcesses
    class ListProcesses;
    typedef ListProcesses* ListProcesses_ptr;

    // SystemInfo
    class SystemInfo;
    typedef SystemInfo* SystemInfo_ptr;

    // Process
    class Process;
    typedef Process* Process_ptr;

    // ExportOp
    class ExportOp;
    typedef ExportOp* ExportOp_ptr;

    // MetricHistOp
    class MetricHistOp;
    typedef MetricHistOp* MetricHistOp_ptr;

    // RestartOp
    class RestartOp;
    typedef RestartOp* RestartOp_ptr;

    // CurMetricOp
    class CurMetricOp;
    typedef CurMetricOp* CurMetricOp_ptr;

    // ProcessOp
    class ProcessOp;
    typedef ProcessOp* ProcessOp_ptr;

    // ThresholdOp
    class ThresholdOp;
    typedef ThresholdOp* ThresholdOp_ptr;

    // ListThreshold
    class ListThreshold;
    typedef ListThreshold* ListThreshold_ptr;

    // Threshold
    class Threshold;
    typedef Threshold* Threshold_ptr;

    // SysInfoOp
    class SysInfoOp;
    typedef SysInfoOp* SysInfoOp_ptr;

    // ListSysInfo
    class ListSysInfo;
    typedef ListSysInfo* ListSysInfo_ptr;

    // Package & Factory
    class IMS_DataFactory;
    typedef IMS_DataFactory * IMS_DataFactory_ptr;
    class IMS_DataPackage;
    typedef IMS_DataPackage * IMS_DataPackage_ptr;

    template< typename T, typename S >
    inline T* instanceOf(S* _s)
    {
        return dynamic_cast< T* > (_s);
    }

} // IMS_Data


#endif // _IMS_DATA_FORWARD_HPP
