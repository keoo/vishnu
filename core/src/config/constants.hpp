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


#ifndef _CONSTANTS_HPP_
#define _CONSTANTS_HPP_

#include <string>

namespace vishnu {
  /**
   * \brief Define a constant type
   */
  typedef enum {
    NONE_PARAMETER,
    BOOL_PARAMETER,
    INT_PARAMETER,
    ULONG_PARAMETER,
    STRING_PARAMETER,
    ADDRESS_PARAMETER
  } c_type_t ;

/**
 * \brief Define a parameter type
 */

  typedef enum {
    DIETCONFIGFILE=0,
    VISHNUID,
    DBTYPE,
    DBHOST,
    DBPORT,
    DBNAME,
    DBUSERNAME,
    DBPASSWORD,
    SENDMAILSCRIPT,
    BATCHTYPE,
    MACHINEID,
    REMOTEBINDIR,
    INTERVALMONITOR,
    DBPOOLSIZE
  } param_type_t;

  /**
   * \brief A convenient data type to store a parameter
   */
  struct param_t
  {
    /**
     * \brief key to retrieve the parameter
     */
    param_type_t key;


    /**
     * \brief the value of the parameter
     */
    const std::string value;

   /**
    * \brief the type of the parameter
    */

    c_type_t type;

  };

  /**
   * \brief An arry to store all paraeters
   */
  extern param_t params[]; //%RELAX<MISRA_3_1_3> Because this table is defined in constants.cpp 
}

#endif /* _CONSTANTS_HPP_ */
