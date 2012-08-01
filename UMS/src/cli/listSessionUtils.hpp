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

/**
 * \file listSessionUtils.hpp
 * \brief This file declares useful functions and types for the VISHNU list session
 *  command
 * \author Ibrahima Cisse (ibrahima.cisse@sysfera.com)
 */



#ifndef LISTSESSIONUTILS__HH
#define LISTSESSIONUTILS__HH

//VISHNU Headers

#include "common.hpp"

//Boost Headers

#include<boost/function.hpp>



class Options;

/**
 * \brief A convenient function type taking a string parameter and
 * without return value
 */

typedef 
boost::function1<void,std::string> StringcallBackType;

/**
 * \brief The close policy option callback type
 */

typedef  
boost::function1<void,UMS_Data::SessionCloseType> ClosePolicycallBackType;

/**
 * \brief The status option callback type
 */

typedef
boost::function1<void,UMS_Data::UMS_Data::StatusType> StatuscallBackType;

/**
 * \brief A convenient function type taking a long integer parameter and
 * without return value
 */


typedef 
boost::function1<void,long> LongcallBackType;

/**
 * \brief A convenient function type taking a integer parameter and
 * without return value
 */

typedef
boost::function1<void,int> IntcallBackType;


/**
 * \brief To build options for the VISHNU list session command
 * \param pgName : The name of the command
 * \param fUserId: The user identifier option callback
 * \param dietConfig: Represents the VISHNU config file
 * \param fMachineId: The machine identifier option callback
 * \param fSessionId: The session identifier option callback
 * \param fStatus: The session status option callback
 * \param fClosePolicy: The session close policy option callback
 * \param fSessionInactivityDelay: The session inactivity delay option callback
 * \param fStartDateOption: The session start date option callback
 * \param fEndDateOption: The session end date option callback
 * \return The description of all options allowed by the command
 */


boost::shared_ptr<Options> 
makeListSessionOptions(std::string pgName,StringcallBackType& fUserId,
                       std::string & dietConfig,  StringcallBackType& fMachineId, 
                       StringcallBackType& fSessionId, StatuscallBackType& fStatus,
                       ClosePolicycallBackType& fClosePolicy, IntcallBackType& fSessionInactivityDelay,
                       LongcallBackType& fStartDateOption, LongcallBackType& fEndDateOption);




#endif



