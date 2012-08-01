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
 * \file UtilsProxy.cpp
 * \brief This file contains the VISHNU UtilsProxy class.
 * \author Daouda Traore (daouda.traore@sysfera.com)
 * \date February 2011
 */
#include <string>
#include <iostream>
#include <fstream>

#include "UMSVishnuException.hpp"
#include "SystemException.hpp"
#include "UtilsProxy.hpp"
#include "utilsClient.hpp"

/**
 * \fn  UtilsProxy()
 * \brief Constructor, default constructor
 */
UtilsProxy::UtilsProxy()
{
  mcfg  = NULL;
  margc = 0;
  margv = NULL;
}

/**
 * \fn UtilsProxy(char* cfg,
 *                int argc,
 char** argv)
 * \param cfg The SYSFERA-DS configuration file
 * \param argc The number of arguments of the program
 * \param argv The list of arguments
 * \brief Constructor
 */
UtilsProxy::UtilsProxy(char* cfg, int argc, char** argv):
  mcfg(cfg), margc(argc), margv(argv)
{
}

/**
 * \fn UtilsProxy(const std::string& filePath)
 * \param filePath The SYSFERA-DS configuration file
 * \brief Constructor
 */
UtilsProxy::UtilsProxy(const std::string& filePath):
  mfilePath(filePath)
{
  mcfg = NULL;
  margc = 0;
  margv = NULL;
}

/**
 * \brief Function to initialize the SYSFERA-DS configuration
 * \fn  int initialize()
 * \return 0 or GRPC code if success else raises an exception if error
 */
int
UtilsProxy::initialize() {
  int res = 0;
  try {
    res = diet_initialize(mcfg, margc, margv);
  } catch (...) {
    throw SystemException(ERRCODE_DIET, "Internal DIET Exception");
  }
  if (res == -1) {
    throw SystemException(ERRCODE_DIET, "DIET Initialization failure");
  }
  return res;
}

/**
 * \brief Function to finalize
 * \fn  void finalize()
 * \return raises an exception on error
 */
void
UtilsProxy::finalize() {
  diet_finalize();
}
#ifdef BUILD_TESTING
/**
 * \brief Function to initialize the database
 * \fn  int restore()
 * \return an error code
 */
int
UtilsProxy::restore() {

  int READSIZE = 1000;
  diet_profile_t* profile = NULL;
  std::ifstream file(mfilePath.c_str(), std::ios::in);
  char* errorInfo;
  if(!file) {
    return -1;
  }
  // While all has not been read
  while (-1 != file.tellg()){
    char* tmp = new char[READSIZE];
    file.getline(tmp, READSIZE);
    if (strcmp(tmp, "")==0){
      break;
    }
    profile = diet_profile_alloc("restore", 0, 0, 1);
    //IN Parameters
    diet_string_set(diet_parameter(profile,0), tmp, DIET_VOLATILE);
    //OUT Parameters
    diet_string_set(diet_parameter(profile,1), NULL, DIET_VOLATILE);
    if(!diet_call(profile)){
      if(diet_string_get(diet_parameter(profile,1), &errorInfo, NULL)) {
        raiseDietMsgException("DIET call failure");
      }
    } else {
      raiseDietMsgException("DIET call failure");
    }
    raiseExceptionIfNotEmptyMsg(errorInfo);
  }
  return 0;
}
#endif

/**
 * \fn ~UtilsProxy()
 * \brief Destructor, raises an exception on error
 */
UtilsProxy::~UtilsProxy()
{
}

