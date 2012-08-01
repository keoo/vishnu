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
 * \file Mapper.hpp
 * \brief This file defines the generic mapper class
 * \author Kevin Coulomb (kevin.coulomb@sysfera.com)
 * \date 07/02/11
 */

#ifndef __MAPPER__HH__
#define __MAPPER__HH__

#include <map>
#include <vector>

#include <pthread.h>
#include "MapperRegistry.hpp"

class MapperRegistry;
using namespace std;

/**
 * \class Mapper
 * \brief Generic mapper
 */
class Mapper{
public :
  /**
   * \brief Constructor
   * \fn Mapper(MapperRegistry* reg)
   * \param reg Registry to register
   */
  Mapper(MapperRegistry* reg);
  /**
   * \brief Default constructor
   * \fn Mapper()
   */
  Mapper();
  /**
   * \brief Destructor
   * \fn ~Mapper()
   */
  ~Mapper();
  /**
   * \brief Copy constructor
   * \fn Mapper(const Mapper& m)
   * \param m The mapper to copy
   */
  Mapper(const Mapper& m);
  /**
   * \brief To register a mapper in the list of active mapper
   * \fn virtual int registerMapper()
   * \return 0 on success, an error code otherwise
   */
  virtual int
  registerMapper(){return 0;}

  /**
   * \brief To unregister a mapper in the list of active mapper
   * \fn virtual int unregisterMapper()
   * \return 0 on success, an error code otherwise
   */
  virtual int
  unregisterMapper() {return 0;}

  /**
   * \brief To get the command corresponding to a key
   * \fn virtual int getCommand(const string& key,string& command)
   * \param key The key to use
   * \param command OUT, the command corresponding to the key
   * \return 0 on success, an error code otherwise
   */
  virtual int
  getCommand(const string& key,string& command) {return 0;}

  /**
   * \brief To get the key corresponding to a command
   * \fn virtual int getKey(const string& command, string& key)
   * \param command The 'key' to use
   * \param key OUT, the key corresponding to the command
   * \return 0 on success, an error code otherwise
   */
  virtual int
  getKey(const string& command, string& key) {return 0;}

  /**
   * \brief Function to add an element to code
   * \fn  virtual int code(const string& cmd, unsigned int code = 0)
   * \param cmd The string to add
   * \param code If 0, the code is created, otherwize it is the key in the map to add the string
   * \return if param code = 0, the assigned code to add other element to the same item, otherwize return 0
   */
  virtual int
  code(const string& cmd, unsigned int code = 0) {return 0;}

  /**
   * \brief To end a command, delete it from the map and get its value
   * \fn virtual string finalize(int key)
   * \param key The entry in the map to get an remove
   * \return The coded value of the command
   */
  virtual string
  finalize(int key);

  /**
   * \brief To get, from a coded string, the CPP command that made it
   * \fn virtual string decode (const string& msg)
   * \param msg The coded string
   * \return The CPP command
   */
  virtual string
  decode(const string& msg) {return "";}

protected:
  /**
   * \brief To find all the separator in the string s and fill the vector with their position in the string
   * \fn void findSeparator(const string& s, vector<int>& vec)
   * \param s The string to find the separator
   * \param vec A vector containing the position of the separator in the string s (OUT)
   * \return The cli like close command
   */
  void
  findSeparator(const string& s, vector<int>& vec);

  /**
   * \brief The mapper registry
   */
  MapperRegistry* mreg;
  /**
   * \brief The map containing the function and their code
   */
  map<int, string> mmap;
  /**
   * \brief The name of the mapper
   */
  string mname;

  /**
   * \brief Map used to store the string that are decoded
   */
  map<int, string> mcmd;
  /**
   * \brief Mutex to protect the id generation for the mcmd map
   */
  pthread_mutex_t mutex;
private:
};


#endif
