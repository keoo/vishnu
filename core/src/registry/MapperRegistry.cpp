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

#include "MapperRegistry.hpp"

using namespace std;

MapperRegistry* MapperRegistry::mreg = NULL; //%RELAX<MISRA_0_1_3> Used in this file

MapperRegistry::MapperRegistry(){
  mmapper = map<string, Mapper*>();
}

MapperRegistry::~MapperRegistry(){
}

MapperRegistry*
MapperRegistry::getInstance(){
  if (!mreg){
    mreg = new MapperRegistry();
  }
  return mreg;
}

int
MapperRegistry::addMapper(string s, Mapper* mapper){
  if (mreg==NULL){
    me = SystemException(ERRCODE_SYSTEM, "Cannot add to a nill mapper");
    me.setType(VishnuException::INTERNAL);
    me.setMsg(6);
    me.setMsgComp("Error null registry");
    throw(me);
  }
  if (!contains(s)){
    mmapper.insert( pair<string, Mapper*>(s, mapper));
  }
  display();
  return 0;
}

int
MapperRegistry::removeMapper(string s){
  if (!mreg){
    return 0;
  }
  if (contains(s)){
    mmapper.erase(s);
  }
  return 0;
}

Mapper*
MapperRegistry::getMapper(const string& s) {
  map<string, Mapper*>::const_iterator it;
  for (it = mmapper.begin() ; it != mmapper.end() ; it++){
    if (s.compare(it->first)==0){
      return it->second;
    }
  }
  me = SystemException(ERRCODE_SYSTEM, "Mapper not found");
  me.setType(VishnuException::INTERNAL);
  me.setMsg(6);
  me.setMsgComp("Error invalid mapper");
  throw(me);
  return 0;
}

bool
MapperRegistry::contains(string s){
  map<string, Mapper*>::const_iterator it = mmapper.begin();
  for ( ; it != mmapper.end() ; it++){
    if (s.compare(it->first)==0){
      return true;
    }
  }
  return false;
}

void MapperRegistry::display(){
  map<string, Mapper*>::const_iterator it;
  for (it = mmapper.begin() ; it != mmapper.end() ; it++){
  }
}
