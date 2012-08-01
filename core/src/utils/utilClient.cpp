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
 * \file utilClient.cpp
 * \brief This file contains client utils functions for VISHNU client Proxy classes
 * \author Daouda Traore (daouda.traore@sysfera.com)
 * \date April 2011
 */
#include "utilClient.hpp"
#include "utilVishnu.hpp"

/**
 * \brief Function to spread error message to C++ API, Python API, Web service API and command line program
 * \fn void raiseDietMsgException(const std::string& msg)
 * \param msg to spread
 * \return raises an exception on error
 */
void raiseDietMsgException(const std::string& msg) {
  SystemException e(ERRCODE_DIET, msg);
  throw e;
}

/**
 * \brief Function to split the receiving message into error code and message error
 * \fn void raiseExceptionIfNotEmptyMsg(const std::string& msg)
 * \param msg to split
 * \return raises an exception on error
 */
void raiseExceptionIfNotEmptyMsg(const std::string& msg) {

  if(msg.size() > 0 ) {
    size_t pos = msg.find('#');
    if(pos!=std::string::npos) {
      std::string codeInString = msg.substr(0,pos);
      if(codeInString.size()!=0) {
        std::istringstream isCode(codeInString);
        int code;
        isCode >> code;
        std::string message = msg.substr(pos+1);
        if (code<10){
          throw SystemException(code, message);
        } else if (code<100){
          throw UMSVishnuException(code, message);
        } else if ((code >= 100) && (code < 200)) {
          throw TMSVishnuException(code, message);
        }else if ((code >= 200) && (code < 300)){
          throw FMSVishnuException(code, message);
        } else if ((code >= 300) && (code < 400)) {
          throw IMSVishnuException(code, message);
        } else {
          std::string tmp = "Invalid code: ";
          tmp += vishnu::convertToString(code);
          tmp += " with message: ";
          tmp += message;
          throw SystemException(ERRCODE_INVEXCEP, tmp);
        }
      }
    } else {
      throw SystemException(ERRCODE_INVEXCEP, msg);
    }
  }
}
