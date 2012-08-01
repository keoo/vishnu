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
 * \file ListMachinesServer.hpp
 * \brief This file contains the VISHNU QueryServer class.
 * \author Daouda Traore (daouda.traore@sysfera.com) and
 *   Eugène PAMBA CAPO-CHICHI (eugene.capochichi@sysfera.com)
 * \date February 2011
 */
#ifndef _LIST_MACHINES_SERVER_
#define _LIST_MACHINES_SERVER_

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "boost/date_time/posix_time/posix_time.hpp"

#include "SessionServer.hpp"
#include "QueryServer.hpp"
#include "ListMachineOptions.hpp"
#include "ListMachines.hpp"

/**
 * \class ListMachinesServer
 * \brief ListMachinesServer class implementation
 */
class ListMachinesServer: public QueryServer<UMS_Data::ListMachineOptions, UMS_Data::ListMachines>
{

public:

  /**
   * \fn ListMachinesServer(const SessionServer session)
   * \param session The object which encapsulates the session information (ex: identifier of the session)
   * \brief Constructor, raises an exception on error
   */
  ListMachinesServer(const SessionServer session):
  QueryServer<UMS_Data::ListMachineOptions, UMS_Data::ListMachines>(session)
  {
    mcommandName = "vishnu_list_machines";
  }
  /**
   * \fn ListMachinesServer(UMS_Data::ListMachineOptions_ptr params,
   *                        const SessionServer& session)
   * \param params The object which encapsulates the information of ListMachinesServer options
   * \param session The object which encapsulates the session information (ex: identifier of the session)
   * \brief Constructor, raises an exception on error
   */
  ListMachinesServer(UMS_Data::ListMachineOptions_ptr params, const SessionServer& session):
  QueryServer<UMS_Data::ListMachineOptions, UMS_Data::ListMachines>(params, session)
  {
    mcommandName = "vishnu_list_machines";
  }

  /**
   * \brief Function to treat the ListMachinesServer options
   * \fn void processOptions(UserServer userServer,
   *                         const UMS_Data::ListMachineOptions_ptr& options,
   *                         std::string& sqlRequest)
   * \param userServer the object which encapsulates user information
   * \param options the object which contains the ListMachinesServer options values
   * \param sqlRequest the sql data base request
   * \return raises an exception on error
   */
  void processOptions(UserServer userServer, const UMS_Data::ListMachineOptions_ptr& options, std::string& sqlRequest)
  {
    std::string sqlListofMachinesWithJointure = "SELECT machineid, name, site, machine.status, lang, description, userid "
    " from machine, description, account, users where machine.nummachineid = description.machine_nummachineid "
    " and account.machine_nummachineid=machine.nummachineid and account.users_numuserid=users.numuserid";

    std::string sqlListofMachinesIntial =  sqlRequest;

    size_t userIdSize = options->getUserId().size();
    size_t machineIdSize = options->getMachineId().size();
    bool isListAll = options->isListAllmachine();

    if ((!userServer.isAdmin()) && userIdSize!=0) {
      UMSVishnuException e (ERRCODE_NO_ADMIN);
      throw e;
    }

    if(!isListAll) {
       sqlRequest = sqlListofMachinesWithJointure;
       addOptionRequest("userid", userServer.getData().getUserId(), sqlRequest);
    }

    //The admin option
    if(userIdSize!=0) {
      //To check if the user id is correct
      checkUserId(options->getUserId());

      sqlRequest = sqlListofMachinesWithJointure;
      addOptionRequest("userid", options->getUserId(), sqlRequest);
    }

    if(machineIdSize!=0) {
      //To check if the machine id is correct
      checkMachineId(options->getMachineId());

      if(!isListAll && userIdSize==0) {
         sqlRequest=sqlListofMachinesIntial;
      }
      addOptionRequest("machineid", options->getMachineId(), sqlRequest);
    }

 }

 /**
  * \brief Function to list machines information
  * \fn UMS_Data::ListMachines* list()
  * \return The pointer to the UMS_Data::ListMachines containing machines information
  * \return raises an exception on error
  */
 UMS_Data::ListMachines* list() {
    std::string sqlListofMachines = "SELECT machineid, name, site, status, lang, description from machine, description "
    "where machine.nummachineid = description.machine_nummachineid";

    std::vector<std::string>::iterator ii;
    std::vector<std::string> results;
    UMS_Data::UMS_DataFactory_ptr ecoreFactory = UMS_Data::UMS_DataFactory::_instance();
    mlistObject = ecoreFactory->createListMachines();

    //Creation of the object user
    UserServer userServer = UserServer(msessionServer);
    userServer.init();
    //if the user exists
    if (userServer.exist()) {

      //To process options
      processOptions(userServer, mparameters, sqlListofMachines);

      boost::scoped_ptr<DatabaseResult> ListofMachines (mdatabaseVishnu->getResult(sqlListofMachines.c_str()));
      if (ListofMachines->getNbTuples() != 0){
        for (size_t i = 0; i < ListofMachines->getNbTuples(); ++i) {
          results.clear();
          results = ListofMachines->get(i);
          ii = results.begin();
          UMS_Data::Machine_ptr machine = ecoreFactory->createMachine();
          machine->setMachineId(*ii);
          machine->setName(*(++ii));
          machine->setSite(*(++ii));
          machine->setStatus(convertToInt(*(++ii)));
          machine->setLanguage(*(++ii));
          machine->setMachineDescription(*(++ii));

          mlistObject->getMachines().push_back(machine);
        }
      }

    } else {
      UMSVishnuException e (ERRCODE_UNKNOWN_USER);
      throw e;
    }
    return mlistObject;
  }

  /**
   * \brief Function to get the name of the ListMachinesServer command line
   * \fn std::string getCommandName()
   * \return The the name of the ListMachinesServer command line
   */
  std::string getCommandName()
  {
    return mcommandName;
  }

  /**
   * \fn ~ListMachinesServer()
   * \brief Destructor, raises an exception on error
   */
  ~ListMachinesServer()
  {
  }

  private:

   /////////////////////////////////
  // Attributes
  /////////////////////////////////

  /**
  * \brief The name of the ListMachinesServer command line
  */
  std::string mcommandName;

};

#endif
