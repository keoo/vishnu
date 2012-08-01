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
 * \file MapperRegistry.hpp
 * \brief This file defines the registry module
 * \author Kevin Coulomb (kevin.coulomb@sysfera.com)
 * \date 07/02/11
 */


#ifndef __MAPPERREGISTRY__HH__
#define __MAPPERREGISTRY__HH__

#include <map>

#include "SystemException.hpp"
#include "Mapper.hpp"

using namespace std;
class Mapper;
/**
 * \class MapperRegistry
 * \brief Registry of all the mapper
 */
class MapperRegistry{
public :
  /**
   * \brief To add a mapper in the list of active mapper
   * \fn int addMapper(string s, Mapper* m)
   * \param s Mapper name
   * \param m The mapper
   * \return 0 on success, an error code otherwise
   */
  int
  addMapper(string s, Mapper* m);
  /**
   * \brief To get a mapper
   * \fn Mapper* getMapper(const string& name)
   * \param name Name of the mapper needed (IN)
   * \return The mapper
   */
  Mapper*
  getMapper(const string& name);
  /**
   * \brief To remove a mapper off the list of active mapper
   * \fn int removeMapper(string s)
   * \param s Mapper name
   * \return 0 on success, an error code otherwise
   */
  int
  removeMapper(string s);
  /**
   * \brief Default destructor
   * \fn ~MapperRegistry()
   */
  ~MapperRegistry();
  /**
   * \brief To get a mapper registry
   * \fn static MapperRegistry* getInstance()
   */
  static MapperRegistry*
  getInstance();
protected:
private :
  /**
   * \brief Default constructor
   * \fn MapperRegistry()
   */
  MapperRegistry();
  /**
   * \brief Exception to be thrown
   */
  SystemException me;
  /**
   * \brief Return if the list contains the string
   * \fn bool contains(string s)
   * \param s The searched string
   * \return Return true if the list contains the s string
   */
  bool
  contains(string s);
  /**
   * \brief The registry
   */
  static MapperRegistry* mreg;
  /**
   * \brief Map of the map
   */
  map<string, Mapper*> mmapper;
  // DEBUG
  /**
   * \brief Debug function
   * \fn void display()
   */
  void display();
};

#endif // MAPPERREGISTRY

