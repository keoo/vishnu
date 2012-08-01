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
 * \file TMSMapper.hpp
 * \brief Mapper for the TMS module
 * \author Kevin Coulomb (kevin.coulomb@sysfera.com)
 * \date 10/02/11
 */

#ifndef __TMSMAPPER__HH__
#define __TMSMAPPER__HH__

#include <map>

#include "Mapper.hpp"
#include "MapperRegistry.hpp"


using namespace std;

/**
 * \brief Submit job key
 */
const int VISHNU_SUBMITJOB               = 1;
/**
 * \brief Get job info key
 */
const int VISHNU_GETJOBINFO              = 2;
/**
 * \brief Get job progress key
 */
const int VISHNU_GETJOBPROG              = 3;
/**
 * \brief List queues key
 */
const int VISHNU_LISTQUEUES              = 4;
/**
 * \brief List jobs key
 */
const int VISHNU_LISTJOBS                = 5;
/**
 * \brief Get job output key
 */
const int VISHNU_GETJOBOUTPUT            = 6;
/**
 * \brief Get all job output key
 */
const int VISHNU_GETCOMPLETEDJOB         = 7;
/**
 * \brief Cancel key
 */
const int VISHNU_CANCEL                  = 8;

/**
 * \class TMSMapper
 * \brief Mapper implementation for the TMS module
 */
class TMSMapper : Mapper{
public :
  /**
   * \brief Constructor
   * \fn TMSMapper(MapperRegistry* reg, string name)
   * \param reg Registry to register
   * \param name Name to use to register
   */
  TMSMapper(MapperRegistry* reg, string name);
  /**
   * \brief Default constructor
   * \fn TMSMapper()
   */
  TMSMapper();
  /**
   * \brief Destructor
   * \fn ~TMSMapper()
   */
  ~TMSMapper();
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
   * \brief To decode the submit call sequence of the string returned by finalize
   * \fn string decodeSubmit(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like close command
   */
  virtual string
  decodeSubmit(vector<int> separator, const string& msg);
  
  /**
   * \brief To decode the get progression call sequence of the string returned by finalize
   * \fn string decodeProg(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like close command
   */
  virtual string
  decodeProg(vector<int> separator, const string& msg);

  /**
   * \brief To decode the get queue call sequence of the string returned by finalize
   * \fn string decodeQueue(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like close command
   */
  virtual string
  decodeQueue(vector<int> separator, const string& msg);

  /**
   * \brief To decode the get list job call sequence of the string returned by finalize
   * \fn string decodeListJob(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like close command
   */
  virtual string
  decodeListJob(vector<int> separator, const string& msg);

  /**
   * \brief To decode the get output call sequence of the string returned by finalize
   * \fn string decodeOutput(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like close command
   */
  virtual string
  decodeOutput(vector<int> separator, const string& msg);

  /**
   * \brief To decode the get all output call sequence of the string returned by finalize
   * \fn string decodeCompletedJob(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like close command
   */
  virtual string
  decodeCompletedJob(vector<int> separator, const string& msg);

  /**
   * \brief To decode the cancel call sequence of the string returned by finalize
   * \fn string decodeCancel(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like close command
   */
  virtual string
  decodeCancel(vector<int> separator, const string& msg);

  /**
   * \brief To decode the get job info call sequence of the string returned by finalize
   * \fn string decodeJobInfo(vector<int> separator, const string& msg)
   * \param separator A vector containing the position of the separator in the message msg
   * \param msg The message to decode
   * \return The cli like close command
   */
  virtual string
  decodeJobInfo(vector<int> separator, const string& msg);
private:
};


#endif
