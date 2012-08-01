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
 * \file UtilsProxy.hpp
 * \brief This file contains the VISHNU UtilsProxy class.
 * \author Daouda Traore (daouda.traore@sysfera.com)
 * \date February 2011
 */
#ifndef _UTILS_PROXY_H_
#define _UTILS_PROXY_H_

#include "DIET_client.h"

/**
 * \brief The class with the utilitaries function (not in the cli api)
 * \class UtilsProxy
 */
class UtilsProxy
{

  public:

    /**
     * \fn  UtilsProxy() 
     * \brief Constructor, default constructor
     */
    UtilsProxy();

    /**
     * \fn UtilsProxy(char* cfg,
     *                int argc,
     *                char** argv)
     * \param cfg The SYSFERA-DS configuration file
     * \param argc The number of arguments of the program
     * \param argv The list of arguments
     * \brief Constructor
     */
    UtilsProxy(char* cfg, int argc, char** argv);

    /**
     * \fn UtilsProxy(const std::string& filePath)
     * \param filePath The file used by the restore function 
     * \brief Constructor
     */
    UtilsProxy(const std::string& filePath);

    /**
     * \brief Function to initialize the SYSFERA-DS configuration
     * \fn  int initialize()
     * \return 0 if success else 1 if error
     */
    int
      initialize();
    /**
     * \brief Function to finalize
     * \fn  void finalize()
     * \return raises an exception on error
     */
    void
      finalize();

#ifdef BUILD_TESTING
    /**
     * \brief Function to initialize the database
     * \fn int restore()
     * \return an error code
     */
    int
      restore();
#endif

    ~UtilsProxy();

  private:

    /////////////////////////////////
    // Attributes
    /////////////////////////////////

    /**
     * \brief The name of the Sysfera-DS configuration file 
     */
    char* mcfg;
    /**
     * \brief The number of arguments used Sysfera-DS  
     */
    int margc;
    /**
     * \brief The list of arguments used Sysfera-DS  
     */
    char** margv;
    /**
     * \brief The file used by the restore function  
     */
    std::string mfilePath;

};
#endif
