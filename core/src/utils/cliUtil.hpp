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

#include "Options.hpp"

#ifndef CORECLIUTIL_HPP
#define CORECLIUTIL_HPP

/**
 * \brief Contains a generic diet error message
 */
const std::string dietErrorMsg="DIET initialization failed !";

/**
 * \struct env_name_mapper
 * \brief a environment variable name mapper
 *
 * For each environment variable, the name_mapper function
 * is called to obtain the option name. If it returns empty string
 * the variable is ignored.
 */
struct env_name_mapper{

/**
 * Mapper operator for environnement variable
 * \param name The environment variable name
 * \return The name used in the program
 */

	std::string operator ()(std::string name){

		std::string result= "";

                if (name=="VISHNU_CONFIG_FILE") {

                        result="dietConfig";
                }


		return result;
	}
};

/**
 * \enum ErrorType
 * \brief a convenient type to classify error type
 */
typedef enum{
PARAMERROR,/*!< for any invalid parameter error */
EXECERROR /*!<  for any runtime error */
}ErrorType;

/**
 * \brief helper function to display help about a specific command
 * \param opt: describes all options allowed by the command
 * \param signature: defines the usage of the command
 */
void
helpUsage (const Options& opt,const std::string& signature);

/**
 * \brief helper function to display error about a specific command
 * \param cli   :The name of the command
 * \param errMsg: The error message to display
 * \param err   : The error type
 */

void
errorUsage (const std::string& cli,const std::string& errMsg,const ErrorType& err=PARAMERROR);

/**
 * \brief Helper function to display information (error or usage) about a specific command
 * \param opt   :describes all options allowed by the command
 * \param mess: The help usage message to display
 * \param ewhat   : The error message to display
 * \return 0 if an help is required or 1 if an error must me displayed
 */

int
usage (const Options& opt,const std::string& mess,const std::string& ewhat);


/**
 * \brief A helper function which check if VISHNU_CONFIG_FILE is set
 *\param opt: describes all options allowed by the command
 *\exception raise a runtime exception if the VISHNU_CONFIG_FILE is not set
 */
void
checkVishnuConfig(const Options& opt);

#endif
