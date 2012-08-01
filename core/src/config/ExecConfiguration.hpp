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
 * \file ExecConfiguration.hpp
 */

#ifndef _EXECCONFIGURATION_HPP_
#define _EXECCONFIGURATION_HPP_

#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

#include "constants.hpp"
#include "CommonParser.hpp"
#include "FileParser.hpp"
#include "UserException.hpp"

/**
 * \class simple_cast_traits
 * \brief traits class used by simple cast that sets zero_value
 * by default to 0, specialize for each type that requires.
 */
template <typename T>
class simple_cast_traits {
public:
  /**
   * \brief To store the zero value
   */
  static const T zero_value = 0;
};

/**
 * \brief A specialization of the simple_cast_traits class for string type
 */
template <>
class simple_cast_traits<std::string> {
public:
  /**
   * \brief To store the empty string
   */
  static const std::string zero_value ;
};

/**
 * \brief lexical_cast
 * empty strings are handled by using a traits class
 * \param arg argument
 * \return properly casted argument
 */
template <typename T, typename S>
T simple_cast(const S& arg) {
  T output = simple_cast_traits<T>::zero_value;
  std::stringstream buffer;
  buffer << arg;
  buffer >> output;

  return output;
}

/**
 * \class ExecConfiguration
 * \brief Program configuration based on key/value pairs stored in a file
 */
class ExecConfiguration {

public:
  ExecConfiguration();

  /**
   * \brief Initialize from a file
   * \param filePath  full path of the configuration filePath
   */
  void initFromFile(std::string filePath) throw (UserException);

  /**
   * \brief Get the value of a configuration parameter
   * \param[in]  param
   * \param[out] value result
   * \return param has been set or not
   */
  template<typename T>
  bool
  getConfigValue(vishnu::param_type_t param, T& value) const
  {
    const std::string& key = (vishnu::params)[param].value;
    ConfigMap::const_iterator it = mconfig.find(key);
    if (mconfig.end() == it) {
      return false;
    } else {
      value = simple_cast<T>(it->second);
      return true;
    }
  }

  /**
   * \brief Check and get the value of a configuration parameter
   * \param[in]  param
   * \param[out] value result
   */
  template<typename T>
  void
  getRequiredConfigValue(vishnu::param_type_t param, T& value) const throw (UserException)
  {
    if (!getConfigValue<T>(param, value)) {
      throw UserException(ERRCODE_CONFIGNOTFOUND, vishnu::params[param].value);
    }
  }

  /**
   * \brief To convert the script in a string
   */
  std::string
  scriptToString();

  /**
   * \brief To get the full path to the current executable
   */
  static std::string
  getCurrentBinaryDir();

protected:

  /**
   * \brief To store the configuration map
   */

  ConfigMap mconfig;
};

#endif /* _EXECCONFIGURATION_HPP_ */
