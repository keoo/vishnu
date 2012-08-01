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

#include "UMSVishnuException.hpp"

UMSVishnuException::UMSVishnuException(const UMSVishnuException& e):UserException(e){
  mtype = VishnuException::UMS;
  initMsg();
}
UMSVishnuException::UMSVishnuException(int msg, std::string msgComp):UserException(msg, msgComp){
  mtype = VishnuException::UMS;
  initMsg();
}
UMSVishnuException::UMSVishnuException():UserException(){
  mtype = VishnuException::UMS;
  initMsg();
}
void
UMSVishnuException::initMsg(){
  mp.insert(std::pair<int, std::string>(ERRCODE_UNKNOWN_USER, std::string("The user is unknown or the password is wrong")));
  mp.insert(std::pair<int, std::string>(ERRCODE_UNKNOWN_USERID, std::string("The userid is unknown")));
  mp.insert(std::pair<int, std::string>(ERRCODE_USERID_EXISTING, std::string("The userid already exists")));
  mp.insert(std::pair<int, std::string>(ERRCODE_USER_LOCKED, std::string("The user is locked")));
  mp.insert(std::pair<int, std::string>(ERRCODE_USER_ALREADY_LOCKED, std::string("The user is already locked")));
  mp.insert(std::pair<int, std::string>(ERRCODE_NO_ADMIN, std::string("The user is not an administrator")));
  mp.insert(std::pair<int, std::string>(ERRCODE_TEMPORARY_PASSWORD, std::string("The password is a temporary password")));
  mp.insert(std::pair<int, std::string>(ERRCODE_INVALID_MAIL_ADRESS, std::string("The mail adress is invalid")));

  mp.insert(std::pair<int, std::string>(ERRCODE_SESSIONKEY_NOT_FOUND, std::string("The session key is unrecognized")));
  mp.insert(std::pair<int, std::string>(ERRCODE_SESSIONKEY_EXPIRED, std::string("The session key is expired. The session is closed.")));
  mp.insert(std::pair<int, std::string>(ERRCODE_UNKNOWN_SESSION_ID, std::string("The session id is unknown")));
  mp.insert(std::pair<int, std::string>(ERRCODE_COMMAND_RUNNING, std::string("Commands are running")));

  mp.insert(std::pair<int, std::string>(ERRCODE_UNKNOWN_MACHINE, std::string("The machine id is unknown")));
  mp.insert(std::pair<int, std::string>(ERRCODE_MACHINE_EXISTING, std::string("The machine id already exists")));
  mp.insert(std::pair<int, std::string>(ERRCODE_MACHINE_LOCKED, std::string("The machine is locked")));
  mp.insert(std::pair<int, std::string>(ERRCODE_MACHINE_ALREADY_LOCKED, std::string("The machine is already locked")));
  mp.insert(std::pair<int, std::string>(ERRCODE_UNUSABLE_MACHINE, std::string("The machine does not exist or it is locked")));

  mp.insert(std::pair<int, std::string>(ERRCODE_LOCAL_ACCOUNT_EXIST, std::string("The local account already exists")));
  mp.insert(std::pair<int, std::string>(ERRCODE_UNKNOWN_LOCAL_ACCOUNT, std::string("The local account is unknown")));

  mp.insert(std::pair<int, std::string>(ERRCODE_SAVE_CONFIG_ERROR, std::string("A problem occurs during the configuration saving ")));
  mp.insert(std::pair<int, std::string>(ERRCODE_RESTORE_CONFIG_ERROR, std::string("A problem occurs during the configuration restoring")));

  mp.insert(std::pair<int, std::string>(ERRCODE_UNKNOWN_OPTION, std::string("The name of the user option is unknown")));
  mp.insert(std::pair<int, std::string>(ERRCODE_UNKNOWN_CLOSURE_MODE, std::string("The closure policy is unknown")));
  mp.insert(std::pair<int, std::string>(ERRCODE_INCORRECT_TIMEOUT, std::string("The value of the timeout is incorrect")));
  mp.insert(std::pair<int, std::string>(ERRCODE_INCORRECT_TRANSFER_CMD, std::string("The value of the transfer command is incorrect")));

  mp.insert(std::pair<int, std::string>(ERRCODE_ROOT_USER_ONLY, std::string("It can be done by the root user only")));
  mp.insert(std::pair<int, std::string>(ERRCODE_LOGIN_ALREADY_USED, std::string("The account login is already used by another VISHNU user")));
}
