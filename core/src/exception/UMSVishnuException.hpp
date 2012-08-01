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
 * \file UMSVishnuException.hpp
 * \brief This file defines the UMS sub class for the Vishnu exceptions.
 * \author Kevin Coulomb (kevin.coulomb@sysfera.com)
 */
#ifndef __UMSVISHNUEXCEPTION__
#define __UMSVISHNUEXCEPTION__

#include "UserException.hpp"


static const int ERRCODE_UNKNOWN_USER = 20;
static const int ERRCODE_UNKNOWN_USERID = 21;
static const int ERRCODE_USERID_EXISTING = 22;
static const int ERRCODE_USER_LOCKED = 23;
static const int ERRCODE_USER_ALREADY_LOCKED = 24;
static const int ERRCODE_NO_ADMIN = 25;
static const int ERRCODE_TEMPORARY_PASSWORD = 26;
static const int ERRCODE_INVALID_MAIL_ADRESS = 27;

static const int ERRCODE_SESSIONKEY_NOT_FOUND = 28;
static const int ERRCODE_SESSIONKEY_EXPIRED = 29;
static const int ERRCODE_UNKNOWN_SESSION_ID = 30;
static const int ERRCODE_COMMAND_RUNNING = 31;

static const int ERRCODE_UNKNOWN_MACHINE = 32;
static const int ERRCODE_MACHINE_EXISTING = 33;
static const int ERRCODE_MACHINE_LOCKED = 34;
static const int ERRCODE_MACHINE_ALREADY_LOCKED = 35;
static const int ERRCODE_UNUSABLE_MACHINE = 36;

static const int ERRCODE_LOCAL_ACCOUNT_EXIST = 37;
static const int ERRCODE_UNKNOWN_LOCAL_ACCOUNT = 38;

static const int ERRCODE_SAVE_CONFIG_ERROR = 39;
static const int ERRCODE_RESTORE_CONFIG_ERROR = 40;

static const int ERRCODE_UNKNOWN_OPTION = 41;
static const int ERRCODE_UNKNOWN_CLOSURE_MODE = 42;
static const int ERRCODE_INCORRECT_TIMEOUT = 43;
static const int ERRCODE_INCORRECT_TRANSFER_CMD = 44;

static const int ERRCODE_ROOT_USER_ONLY = 45;
static const int ERRCODE_LOGIN_ALREADY_USED = 46;

/**
 * \class UMSVishnuException
 * \brief Specialisation of the user exception for the UMS module
 */
class UMSVishnuException: public UserException{

public:
  /**
   * \brief Default constructor
   * \fn UMSVishnuException()
   */
  UMSVishnuException();
  /**
   * \brief Copy constructor
   * \fn UMSVishnuException(const UMSVishnuException& e)
   * \param e The copied exception
   */
  UMSVishnuException(const UMSVishnuException& e);
  /**
   * \brief Constructor
   * \fn UMSVishnuException(int msg, std::string msgComp = "")
   * \param msg The message to use to build
   * \param msgComp Th complementary message used to build the exception
   */
  UMSVishnuException(int msg, std::string msgComp = "");
  /**
   * \brief Default constructor
   * \fn ~UMSVishnuException()
   */
  ~UMSVishnuException()throw (){};
  /**
   * \brief Function to initialize all UMS generic messages
   * \fn void initMsg()
   */
  void
  initMsg();
};

#endif // UMSVishnuException
