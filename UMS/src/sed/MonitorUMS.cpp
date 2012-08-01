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
* \file MonitorUMS.cpp
* \brief This file presents the implementation of the UMS Monitor
* \author Eugène PAMBA CAPO-CHICHI (eugene.capochichi@sysfera.com)
* \date 31/01/2001
*/

#include <boost/scoped_ptr.hpp>
#include "MonitorUMS.hpp"
#include "SystemException.hpp"

/**
* \brief Constructor, raises an exception on error
* \fn ServerUMS(std::string cfg)
* \param interval The interval to check the database
*/
MonitorUMS::MonitorUMS(int interval) {
minterval = interval;
mdatabaseVishnu = NULL;
}

/**
* \brief Destructor
* \fn ~MonitorUMS()
*/

MonitorUMS::~MonitorUMS() {
  if (mdatabaseVishnu != NULL) {
    delete mdatabaseVishnu;
  }
}


/**
* \brief To initialize the UMS monitor with individual parameters instead of configuration file
* \fn int init(int vishnuId, int dbType, std::string dbHost, std::string dbUsername, std::string dbPassword)
* \param vishnuId The password of the root user vishnu_user for the connection with the database
* \param dbConfig The configuration of the database
* \return raises an execption
*/
void
MonitorUMS::init(int vishnuId, DbConfiguration dbConfig) {

  DbFactory factory;

  mdatabaseVishnu = factory.createDatabaseInstance(dbConfig);

  std::string sqlCommand("SELECT * FROM vishnu where vishnuid="+convertToString(vishnuId));

  try {
    /*connection to the database*/
    mdatabaseVishnu->connect();

    /* Checking of vishnuid on the database */
    boost::scoped_ptr<DatabaseResult> result(mdatabaseVishnu->getResult(sqlCommand.c_str()));
    if (result->getResults().size() == 0) {
      throw SystemException(ERRCODE_DBERR, "The vishnuid is unrecognized");
    }
  } catch (VishnuException& e) {
    exit(0);
  }

}

/**
* \brief To launch the UMS Monitor
* \fn int run()
* \return raises an exception
*/
int
MonitorUMS::run() {

  std::vector<std::string>::iterator ii;
  std::vector<std::string> tmp;
  SessionServer closer;

  try {
    boost::scoped_ptr<DatabaseResult> result(closer.getSessionToclosebyTimeout());

    if (result->getNbTuples() != 0) {
      for (size_t i = 0; i < result->getNbTuples(); ++i) {
        tmp.clear();
        tmp = result->get(i);

        ii = tmp.begin();
        SessionServer sessionServer (*ii);

        try {
          //closure of the session
          sessionServer.close();
        }
        catch (VishnuException& e) {
          string errorInfo =  e.buildExceptionString();
          cerr << errorInfo << endl;
        }
      }
    }
    sleep(minterval);

  } catch (VishnuException& e) {
    string errorInfo =  e.buildExceptionString();
    if (e.getMsgI() == ERRCODE_DBERR) {
      cerr << errorInfo << endl;
      exit(1);
    }
    sleep(minterval);
  }
  return 0;
}
