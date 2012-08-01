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

#include "TMSVishnuException.hpp"


TMSVishnuException::TMSVishnuException(const TMSVishnuException& e):UserException(e){
  mtype = VishnuException::TMS;
  initMsg();
}

TMSVishnuException::TMSVishnuException(int msg, std::string msgComp):UserException(msg, msgComp){
  mtype = VishnuException::TMS;
  initMsg();
}

TMSVishnuException::TMSVishnuException():UserException(){
  mtype = VishnuException::TMS;
  initMsg();
}

void
TMSVishnuException::initMsg(){

  mp.insert(std::pair<int, std::string>(ERRCODE_UNKNOWN_BATCH_SCHEDULER, std::string("The batch scheduler type is unknown")));
  mp.insert(std::pair<int, std::string>(ERRCODE_BATCH_SCHEDULER_ERROR, std::string("The batch scheduler indicates an error")));
  mp.insert(std::pair<int, std::string>(ERRCODE_UNKNOWN_JOBID, std::string("The job id is unknown")));
  mp.insert(std::pair<int, std::string>(ERRCODE_PERMISSION_DENIED, std::string("Permission denied")));
  mp.insert(std::pair<int, std::string>(ERRCODE_ALREADY_TERMINATED, std::string("The job is already terminated")));
  mp.insert(std::pair<int, std::string>(ERRCODE_ALREADY_CANCELED, std::string("The job is already canceled")));
  mp.insert(std::pair<int, std::string>(ERRCODE_JOB_IS_NOT_TERMINATED, std::string("The job is not terminated")));
  mp.insert(std::pair<int, std::string>(ERRCODE_ALREADY_DOWNLOADED, std::string("The job is already downloaded")));
}
