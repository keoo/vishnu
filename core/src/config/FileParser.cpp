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
 * \file FileParser.cpp
 * \brief Parser for configuration file
 * \author Gael Le Mahec <gael.le.mahec@ens-lyon.fr>
 * \author Haikel Guemar <hguemar@sysfera.com>
 */

#include <cctype>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "CommonParser.hpp"
#include "FileParser.hpp"

FileParser::FileParser() {
}

FileParser::FileParser(const std::string& path) {
  parseFile(path);
}

void
FileParser::parseFile(const std::string& path) {
  std::ifstream file(path.c_str());

  unsigned int l = 0;

  if (!file.is_open()) {
    throw UserException(ERRCODE_FILENOTFOUND, path);
  }

  Splitter split('=');

  while (!file.eof()) {
    char buffer[1024];
    std::string line, key, value;
    std::string::size_type pos;

    l++;
    file.getline(buffer, 1024);
    line = buffer;
    /* Remove comments. */
    pos = line.find('#');
    if (std::string::npos != pos) {
      line = line.substr(0, pos);
    }

    /* Remove white spaces.
       use remove then erase idiom
       use ::isspace so we don't get the std::locale plagued C++ variant*/
    line.erase(
               std::remove_if(line.begin(), line.end(), ::isspace),
               line.end());

    /* Empty line => continue. */
    if (line.empty()) {
      continue;
    }

    /* Cut the line on '=' character. */
    split.reset(line);

    std::string& token = split();
    key.swap(token);

    if (!split.hasNext()) {
      debug << "Warning : " << key
            << " has no value! (line " << l << ")\n";
    }

    token = split();
    value.swap(token);

    if (split.hasNext()) {
      debug << "Warning : " << key
            << " has multiple values! "
            << split()
            << " (line " << l << ")\n";
    }


    std::map<std::string, std::string>::iterator it = options_.find(key);
    if (options_.end() == it) {
      options_[key] = value;
    } else {
      debug << "Warning : " << key
            << " already defined! \n"
            << "old value : " << it->second << "\n"
            << "new value : " << value << " (line " << l << ")\n";
    }
  }
}

// use of operator[] is more idiomatic
std::string&
FileParser::operator[](const std::string& key) {
  return options_[key];
}


const std::string&
FileParser::operator[](const std::string& key) const {
  return options_[key];
}


const std::map<std::string, std::string>&
FileParser::getConfiguration() const {
  return options_;
}

