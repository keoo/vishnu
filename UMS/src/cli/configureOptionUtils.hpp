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
 * \file configureOptionUtils.hpp
 * \brief This file declare useful functions and types for the VISHNU configure 
 * option command
 * \author Ibrahima Cisse (ibrahima.cisse@sysfera.com)
 */

#ifndef CONFIGUREOPTIONUTILS__HH
#define CONFIGUREOPTIONUTILS__HH

//VISHNU Headers

#include "cliUtil.hpp"
#include "common.hpp"
#include "sessionUtils.hpp"
//Boost Headers
#include <boost/function.hpp>


/**
 * \brief A convenient function type taking a string parameter and
 * without return value
 */


typedef
boost::function1<void,std::string> StringcallBackType;


/**
 * \brief Another convenient function type to handle the callback 
 * 
 */


typedef  
boost::function2<int,const std::string&,const UMS_Data::OptionValue&> ConfigureCallBackType;

/**
 * \brief To build options for the VISHNU configure option command
 * \param opt: Describes all allowed options for the VISHNU configure option
 * command
 * \param dietConfig: Represents the VISHNU config file
 * \param fOptionName : A callback for the option name
 * \param fValue      : A callback for the option value
 */

void
makeConfigureOptions(boost::shared_ptr<Options> opt,std::string& dietConfig,
		                      StringcallBackType& fOptionName,StringcallBackType& fValue
                         );
/**
 * \brief A common function betwenn the VISHNU configure option command
 * and the VISHNU configure default option command
 * \param opt:  Describes all allowed options for the command
 * \param ac :  The number of parameters the command takes
 * \param av : The name of all of that parameters
 * \param conf_func: The VISHNU API function, configureOption our
 * ConfigureDefaultOption
 * \return 0 if the function succeeds, an error code otherwise
 */
int
commonConfigure(boost::shared_ptr<Options> opt, int ac, char* av[] , const ConfigureCallBackType& conf_func);



#endif



