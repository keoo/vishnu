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
 * \file TMSVishnuException.hpp
 * \brief This file defines the TMS sub class for the Vishnu exceptions.
 * \author Kevin Coulomb (kevin.coulomb@sysfera.com)
 */
#ifndef __TMSVISHNUEXCEPTION__
#define __TMSVISHNUEXCEPTION__

#include "UserException.hpp"

// Definitions of TMS specific error codes
static const int ERRCODE_UNKNOWN_BATCH_SCHEDULER = 101;
static const int ERRCODE_BATCH_SCHEDULER_ERROR = 102;
static const int ERRCODE_UNKNOWN_JOBID = 103;
static const int ERRCODE_PERMISSION_DENIED = 104;
static const int ERRCODE_ALREADY_TERMINATED = 105;
static const int ERRCODE_ALREADY_CANCELED = 106;
static const int ERRCODE_JOB_IS_NOT_TERMINATED = 107;
static const int ERRCODE_ALREADY_DOWNLOADED = 108;

/**
 * \brief This class allows to treat an error specific to  TMS Module
 */ 
class TMSVishnuException: public UserException{

  public:
  /**
   * \brief Default constructor
   * \fn TMSVishnuException()
   */
  TMSVishnuException();
  /**
   * \brief Copy constructor
   * \param e the object to copy
   */
  TMSVishnuException(const TMSVishnuException& e);
  /**
   * \brief Constructor
   * \param msg the exception code
   * \param msgComp The complementary message
   */
  TMSVishnuException(int msg, std::string msgComp= "");
  /**
   * \brief Default constructor
   * \fn ~TMSVishnuException()
   */
  ~TMSVishnuException() throw (){};

  /**
   * \brief Function to initialize all UMS generic messages
   * \fn void initMsg()
   */
  void
  initMsg();


};

#endif // TMSVishnuException
