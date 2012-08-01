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

#ifndef VISHNUTESTUTILS_HPP
#define VISHNUTESTUTILS_HPP

#include <iostream>
#include <fstream>
#include <boost/test/unit_test.hpp>
#include "api_ums.hpp"

class VishnuConnection {

public:
  VishnuConnection(const std::string& uid,
                   const std::string& upwd,
                   const UMS_Data::ConnectOptions& co = UMS_Data::ConnectOptions())
  :muid(uid), mupwd(upwd), mco(co), open(false) {};

  ~VishnuConnection() {
    if(true==open) {
      try {
        BOOST_REQUIRE_EQUAL(vishnu::close(msession.getSessionKey()),0);
        BOOST_TEST_MESSAGE("The session is closed");
      } catch (VishnuException& e) {
        BOOST_MESSAGE(e.what());
        BOOST_CHECK(false);
      }
    }
  };

  std::string getSessionKey() {
    try {
      BOOST_REQUIRE(vishnu::connect(muid,mupwd,msession,mco)==0);
      open=true;
      BOOST_TEST_MESSAGE("The session is open");
      return msession.getSessionKey();
    } catch (VishnuException& e) {
      BOOST_MESSAGE(e.what());
      BOOST_CHECK(false);
    }
    return "";
  };

private:
  UMS_Data::Session msession;
  UMS_Data::ConnectOptions mco;
  std::string muid;
  std::string mupwd;
  bool open;
};

template<int FILESIZE>
int createFile(const std::string& filePath) {
  static const int BUFFER_SIZE = 1024;
  char buffer[BUFFER_SIZE + 1];
  for (unsigned int i = 0; i < BUFFER_SIZE; i++) {
    buffer[i] = (char)(i%8 + 'a');
  }
  buffer[BUFFER_SIZE] = '\0';
  std::ofstream outFile(filePath.c_str());
  for (unsigned int i = 0; i < FILESIZE; i++) {
    outFile << buffer;
  }
  outFile.close();

  return 0;
}

#endif
