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
 * \file utilsClient.hpp
 * \brief This file contains client utils functions for VISHNU client Proxy classes
 * \author Daouda Traore (daouda.traore@sysfera.com)
 * \date February 2011
 */
#ifndef  _utilsClient_H_
#define  _utilsClient_H_

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

#include "utilClient.hpp"
#include "UMSVishnuException.hpp"

/**
 * \brief Function to print an error message and the line and file where this error has been occured
 * \fn  inline void errMsg(const std::string& msg)
 * \param msg to print
 */
inline void errMsg(const std::string& msg) {
  std::cerr << "Error line " << __LINE__-1  << " in file " << __FILE__ << " with message: ";
  std::cerr << std::endl;
  std::cerr << msg << std::endl;
}

/**
 * \brief Function to check if a text is empty
 * \param text The text to check
 * \param compMsg The complementary message to print
 * \param execpetionType The type of exception to raise
 * \exception raises an exception on error
 */
void checkIfTextIsEmpty(const std::string& text, const std::string& compMsg, const int& execpetionType);

/**
 * \brief Function to check if an email is valid
 * \param mail The email to check
 * \return raises an exception on error
 */
void checkEmail(const std::string& mail);

#endif
