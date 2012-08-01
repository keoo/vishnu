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

#include "SystemException.hpp"


SystemException::SystemException():VishnuException(){initMsg();}

SystemException::SystemException(const SystemException& e):VishnuException(e){initMsg();}

SystemException::SystemException(int msg, std::string msgComp):VishnuException(msg, msgComp){initMsg();}

std::string
SystemException::getTypeS() const{

  std::string errorTypeStr;

  switch (mtype){
  case 0 :
    errorTypeStr="UMS";
    break;
  case 1 :
   errorTypeStr= "TMS";
    break;
  case 2 :
   errorTypeStr= "FMS";
    break;
  case 3 :
   errorTypeStr= "IMS";
    break;
  case 4 :
   errorTypeStr= "NONE";
    break;
  default :
   errorTypeStr= "->not found<-";
    break;
  }
  return errorTypeStr;
}

void
SystemException::initMsg(){
  mp.insert(std::pair<int, std::string>(ERRCODE_DIET, std::string("Vishnu not available (Service bus failure)")));
  mp.insert(std::pair<int, std::string>(ERRCODE_DBERR, std::string("Vishnu not available (Database error)")));
  mp.insert(std::pair<int, std::string>(ERRCODE_DBCONN, std::string("Vishnu not available (Database connection)")));
  mp.insert(std::pair<int, std::string>(ERRCODE_SYSTEM, std::string("Vishnu not available (System)")));
  mp.insert(std::pair<int, std::string>(ERRCODE_INVCOMP, std::string("Vishnu not available (Component)")));
  mp.insert(std::pair<int, std::string>(ERRCODE_INVMAPPER, std::string("Vishnu not available (Mapper)")));
  mp.insert(std::pair<int, std::string>(ERRCODE_INVDATA, std::string("Vishnu not available (Data error)")));
  mp.insert(std::pair<int, std::string>(ERRCODE_SSH, std::string("Vishnu not available (SSH error)")));
}

std::string
SystemException::getMsg() const{
  if (mp.count(mval)){
    return mp[mval];
  }
  return "Internal Error: Unknown error code.\n";
}
