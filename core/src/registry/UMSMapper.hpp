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
 * \file UMSMapper.hpp
 * \brief Mapper for the UMS module
 * \author Kevin Coulomb (kevin.coulomb@sysfera.com)
 * \date 10/02/11
 */

#ifndef __UMSMAPPER__HH__
#define __UMSMAPPER__HH__

#include <map>
#include <vector>

#include "Mapper.hpp"
#include "MapperRegistry.hpp"
#include "utilVishnu.hpp"

using namespace std;

/**
 * \brief Connection key
 */
const int VISHNU_CONNECT                  = 1 ;
/**
 * \brief Reconnection key
 */
const int VISHNU_RECONNECT 	     	  = 2 ;
/**
 * \brief Closure key
 */
const int VISHNU_CLOSE 	     	          = 3 ;
/**
 * \brief Add user key
 */
const int VISHNU_ADD_VISHNU_USER   	  = 4 ;
/**
 * \brief Update user key
 */
const int VISHNU_UPDATE_VISHNU_USER 	  = 5 ;
/**
 * \brief Delete user key
 */
const int VISHNU_DELETE_VISHNU_USER 	  = 6 ;
/**
 * \brief Change password key
 */
const int VISHNU_CHANGE_PASSWORD   	  = 7 ;
/**
 * \brief Reset password key
 */
const int VISHNU_RESET_PASSWORD    	  = 8 ;
/**
 * \brief Add account key
 */
const int VISHNU_ADD_LOCAL_ACCOUNT        = 9 ;
/**
 * \brief Update account key
 */
const int VISHNU_UPDATE_LOCAL_ACCOUNT     = 10;
/**
 * \brief Delete account key
 */
const int VISHNU_DELETE_LOCAL_ACCOUNT     = 11;
/**
 * \brief Save configuration key
 */
const int VISHNU_SAVE_CONFIGURATION       = 12;
/**
 * \brief Restore configuration key
 */
const int VISHNU_RESTORE_CONFIGURATION    = 13;
/**
 * \brief Add machine key
 */
const int VISHNU_ADD_MACHINE 	          = 14;
/**
 * \brief Update machine key
 */
const int VISHNU_UPDATE_MACHINE           = 15;
/**
 * \brief Delete machine key
 */
const int VISHNU_DELETE_MACHINE           = 16;
/**
 * \brief List account key
 */
const int VISHNU_LIST_LOCAL_ACCOUNT       = 17;
/**
 * \brief List machine key
 */
const int VISHNU_LIST_MACHINE 	          = 18;
/**
 * \brief List history key
 */
const int VISHNU_LIST_HISTORY_CMD         = 19;
/**
 * \brief List option key
 */
const int VISHNU_LIST_OPTIONS 	          = 20;
/**
 * \brief List user key
 */
const int VISHNU_LIST_USERS 	          = 21;
/**
 * \brief List session key
 */
const int VISHNU_LIST_SESSIONS 	          = 22;
/**
 * \brief Configure default option key
 */
const int VISHNU_CONFIGURE_DEFAULT_OPTION = 23;
/**
 * \brief Configure option key
 */
const int VISHNU_CONFIGURE_OPTION	  = 24;


/**
 * \class UMSMapper
 * \brief Mapper implementation for the UMS module
 */
class UMSMapper : Mapper{
public :
  /**
   * \brief Constructor
   * \fn UMSMapper(MapperRegistry* reg, string name)
   * \param reg Registry to be linked to
   * \param name Name of the mapper
   */
  UMSMapper(MapperRegistry* reg, string name);
  /**
   * \brief Default constructor
   * \fn UMSMapper()
   */
  UMSMapper();
  /**
   * \brief Destructor
   * \fn ~UMSMapper()
   */
  ~UMSMapper();
  /**
   * \brief To register a mapper in the list of active mapper
   * \fn virtual int registerMapper()
   * \return 0 on success, an error code otherwise
   */
  virtual int
  registerMapper();

  /**
   * \brief To unregister a mapper in the list of active mapper
   * \fn virtual int unregisterMapper()
   * \return 0 on success, an error code otherwise
   */
  virtual int
  unregisterMapper();

  /**
   * \brief To get the command corresponding to a key
   * \fn virtual int getCommand(const int& key,string& command)
   * \param key The key to use
   * \param command OUT, the command corresponding to the key
   * \return 0 on success, an error code otherwise
   */
  virtual int
  getCommand(const int& key,string& command);

  /**
   * \brief To get the key corresponding to a command
   * \fn virtual int getKey(const string& command, int& key)
   * \param command The 'key' to use
   * \param key OUT, the key corresponding to the command
   * \return 0 on success, an error code otherwise
   */
  virtual int
  getKey(const string& command, int& key);

  /**
   * \brief Function to add an element to code
   * \fn  virtual int code(const string& cmd, unsigned int code = 0)
   * \param cmd The string to add
   * \param code If 0, the code is created, otherwize it is the key in the map to add the string
   * \return if param code = 0, the assigned code to add other element to the same item, otherwize return 0
   */
  virtual int
  code(const string& cmd, unsigned int code = 0);

  /**
   * \brief To get, from a coded string, the cli like command that made it
   * \fn virtual string decode (const string& msg);
   * \param msg The coded string
   * \return The cli like command
   */
  virtual string
  decode (const string& msg);


protected:

  /**
   * \brief To decode the close call sequence of the string returned by finalize
   * \fn string decodeClose(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like close command
   */
  virtual string
  decodeClose(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeAddUser(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like add user command
   */
  virtual string
  decodeAddUser(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeUpUser(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like update user command
   */
  virtual string
  decodeUpUser(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeDelUser(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like delete user command
   */
  virtual string
  decodeDelUser(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeChangePwd(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like change password command
   */
  virtual string
  decodeChangePwd(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeResetPwd(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like reset password command
   */
  virtual string
  decodeResetPwd(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeAddAcc(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like add account command
   */
  virtual string
  decodeAddAcc(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeUpAcc(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like update account command
   */
  virtual string
  decodeUpAcc(vector<int> separator, const string& msg);
  
  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeDelAcc(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like delete account command
   */
  virtual string
  decodeDelAcc(vector<int> separator, const string& msg);
  
  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeSaveConf(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like save configuration command
   */
  virtual string
  decodeSaveConf(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeRestoreConf(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like crestore configuration command
   */
  virtual string
  decodeRestoreConf(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeAddM(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like add machine command
   */
  virtual string
  decodeAddM(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeUpM(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like update machine command
   */
  virtual string
  decodeUpM(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeDelM(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like delete machine command
   */
  virtual string
  decodeDelM(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeListAcc(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like list account command
   */
  virtual string
  decodeListAcc(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeListM(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like list machine command
   */
  virtual string
  decodeListM(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeListH(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like list history command
   */
  virtual string
  decodeListH(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeListOp(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like list option command
   */
  virtual string
  decodeListOp(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeListUser(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like list user command
   */
  virtual string
  decodeListUser(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeListSession(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like list session command
   */
  virtual string
  decodeListSession(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeConfDefaultOp(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like configure default option command
   */
  virtual string
  decodeConfDefaultOp(vector<int> separator, const string& msg);

  /**
   * \brief To decode the add user call sequence of the string returned by finalize
   * \fn string decodeConfOp(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like configure option command
   */
  virtual string
  decodeConfOp(vector<int> separator, const string& msg);

  
  /**
   * \brief To deserialize the serial string, make a user objet, and get the values in the same string
   * \fn string getU(string serial)
   * \param serial The serialized object
   * \return A string containing the user fields in the right order
   */
  string
  getU(string serial);

  /**
   *\brief To deserialize the serial string, make a user objet, and get the values in the same string
   *\fn string getUupdate(string serial)
   *\param serial The serialized object
   *\return A string containing the user fields in the right order
   */
  string
  getUupdate(string serial);
private:
};


#endif
