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
 * \file FileParser.hpp
 * \brief Parser for configuration file
 * \author Gael Le Mahec <gael.le.mahec@ens-lyon.fr>
 * \author Haikel Guemar <hguemar@sysfera.com>
 */
#ifndef _FILE_PARSER_HH_
#define _FILE_PARSER_HH_

#include <map>
#include <string>

#include "UserException.hpp"
#include "CommonParser.hpp"

/**
 * @class FileParser
 * @brief Simple Configuration File Parser
 *
 * support ini-like format, options are stored in a std::map
 */
class FileParser {
private:

  /**
   * @brief To store the options
   */

    mutable OptionMap options_;
public:
    /**
     * @brief default constructor
     */
    FileParser();
    /**
     * @brief constructor
     * @param path path to config file
     */
    explicit FileParser(const std::string& path);
    /**
     * @brief parse configuration file
     * @param path path to config file
     * @exception FileOpenError
     */
    void parseFile(const std::string& path);

    /**
     * @brief subscript operator
     * @param key option name
     * @return option value
     */
    std::string& operator[](const std::string& key); // setter
    /**
     * @brief subscript operator
     * @param key option name
     * @return option value
     */
    const std::string& operator[](const std::string& key) const; //getter

    /**
     * @brief return options
     * @return configuration map (key, value)
     */
    const std::map<std::string, std::string>& getConfiguration() const;
};

#endif /* _FILE_PARSER_HH_ */
