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
 * \file ListCommandsServer.hpp
 * \brief This file contains the VISHNU QueryServer class.
 * \author Daouda Traore (daouda.traore@sysfera.com) and
 *   Eugène PAMBA CAPO-CHICHI (eugene.capochichi@sysfera.com)
 * \date February 2011
 */
#ifndef _LIST_COMMANDS_SERVER
#define _LIST_COMMANDS_SERVER

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "boost/date_time/posix_time/posix_time.hpp"

#include "SessionServer.hpp"
#include "ListCmdOptions.hpp"
#include "UMSMapper.hpp"
#include "MapperRegistry.hpp"
#include "CommandServer.hpp"

/**
 * \class ListCommandsServer
 * \brief ListCommandsServer class implementation
 */
class ListCommandsServer: public QueryServer<UMS_Data::ListCmdOptions, UMS_Data::ListCommands>
{

public:

  /**
   * \fn ListCommandsServer(const SessionServer session)
   * \param session The object which encapsulates the session information (ex: identifier of the session)
   * \brief Constructor, raises an exception on error
   */
  ListCommandsServer(const SessionServer session):
    QueryServer<UMS_Data::ListCmdOptions, UMS_Data::ListCommands>(session)
  {
    mcommandName ="vishnu_list_history_cmd";
  }
  /**
   * \fn ListCommandsServer(UMS_Data::ListCmdOptions_ptr params,
   *                        const SessionServer& session)
   * \param params The object which encapsulates the information of ListCommandsServer options
   * \param session The object which encapsulates the session information (ex: identifier of the session)
   * \brief Constructor, raises an exception on error
   */
  ListCommandsServer(UMS_Data::ListCmdOptions_ptr params, const SessionServer& session):
    QueryServer<UMS_Data::ListCmdOptions, UMS_Data::ListCommands>(params, session)
  {
    mcommandName ="vishnu_list_history_cmd";
  }

  /**
   * \brief Function to treat the ListCommandsServer options
   * \fn void processOptions(UserServer userServer,
   *                         const UMS_Data::ListCmdOptions_ptr& options,
   *                         std::string& sqlRequest)
   * \param userServer the object which encapsulates user information
   * \param options the object which contains the ListCommandsServer options values
   * \param sqlRequest the sql data base request
   * \return raises an exception on error
   */
  void processOptions(UserServer userServer, const UMS_Data::ListCmdOptions_ptr& options, std::string& sqlRequest)
  {
    boost::posix_time::ptime pt;
    size_t userIdSize = options->getUserId().size();
    bool listAll = options->isAdminListOption();

    if ((!userServer.isAdmin()) && (userIdSize!=0 || listAll)) {
       UMSVishnuException e (ERRCODE_NO_ADMIN);
       throw e;
    }

    if(userIdSize!=0) {
       //To check if the user id is correct
      checkUserId(options->getUserId());

      addOptionRequest("userid", options->getUserId(), sqlRequest);
    } else {
            if(!listAll) {
               addOptionRequest("userid", userServer.getData().getUserId(), sqlRequest);
            }
    }

    if(options->getSessionId().size()!=0) {
      //To check if the session id is correct
      checkSessionId(options->getSessionId());

      addOptionRequest("vsessionid", options->getSessionId(), sqlRequest);
    }

    time_t startDate = static_cast<time_t>(options->getStartDateOption());
    if(startDate!=-1) {
      pt =  boost::posix_time::from_time_t(startDate);
      std::string startDateStr =  boost::posix_time::to_simple_string(pt);
      addTimeRequest("starttime", startDateStr, sqlRequest, ">=");
    }

    time_t endDate = static_cast<time_t>(options->getEndDateOption());
    if(endDate!=-1) {
      pt =  boost::posix_time::from_time_t(endDate);
      std::string endDateStr =  boost::posix_time::to_simple_string(pt);
      addTimeRequest("endtime", endDateStr, sqlRequest, "<=");
    }
  }

  /**
   * \brief Function to list commands information
   * \fn UMS_Data::ListCommands* list()
   * \return The pointer to the UMS_Data::ListCommands containing commands information
   * \return raises an exception on error
   */
  UMS_Data::ListCommands* list()
  {
    std::string sqlListOfCommands;
    std::vector<std::string>::iterator ii;
    std::vector<std::string> results;
    std::string description;

    sqlListOfCommands = "SELECT ctype, vsessionid, name, description, starttime, endtime, command.status from "
                         " vsession, clmachine, command, users where vsession.numsessionid=command.vsession_numsessionid and "
                         " vsession.clmachine_numclmachineid=clmachine.numclmachineid and  vsession.users_numuserid=users.numuserid";


    UMS_Data::UMS_DataFactory_ptr ecoreFactory = UMS_Data::UMS_DataFactory::_instance();
    mlistObject = ecoreFactory->createListCommands();

    //Creation of the object user
    UserServer userServer = UserServer(msessionServer);
    userServer.init();
    //if the user exists
    if (userServer.exist()) {

      processOptions(userServer, mparameters, sqlListOfCommands);

      sqlListOfCommands.append(" order by starttime");
      //To get the list of commands from the database
      boost::scoped_ptr<DatabaseResult> ListOfCommands (mdatabaseVishnu->getResult(sqlListOfCommands.c_str()));
      if (ListOfCommands->getNbTuples() != 0){
        for (size_t i = 0; i < ListOfCommands->getNbTuples(); ++i) {
          results.clear();
          results = ListOfCommands->get(i);
          ii = results.begin();

          UMS_Data::Command_ptr command = ecoreFactory->createCommand();
          CmdType currentCmdType = static_cast<CmdType>(convertToInt(*ii));
          command->setCommandId(convertCmdType(static_cast<CmdType>(currentCmdType)));
          command->setSessionId(*(++ii));
          command->setMachineId(*(++ii));
          //MAPPER CREATION
          Mapper* mapper = MapperRegistry::getInstance()->getMapper(convertypetoMapperName(currentCmdType));
          description = mapper->decode(*(++ii));
          command->setCmdDescription(description);
          command->setCmdStartTime(convertToTimeType(*(++ii)));
          command->setCmdEndTime(convertToTimeType(*(++ii)));
          command->setStatus(convertToInt(*(++ii)));

          mlistObject->getCommands().push_back(command);
        }
    }

  }
  else {
      UMSVishnuException e (ERRCODE_UNKNOWN_USER);
      throw e;
  }
  return mlistObject;
  }

  /**
   * \brief Function to get the name of the ListCommandsServer command line
   * \fn std::string getCommandName()
   * \return The the name of the ListCommandsServer command line
   */
  std::string getCommandName()
  {
    return mcommandName;
  }

  /**
   * \brief To convert the command type in string
   * \fn std::string convertCmdType(CmdType type)
   * \param type The type to convert
   * \return The corresponding string
   */
  std::string convertCmdType(CmdType type) {

    std::string cmd;
    switch(type) {
      case UMS :
         cmd = "UMS";
         break;
      case TMS :
         cmd = "TMS";
         break;
      case FMS :
         cmd = "FMS";
         break;
      case IMS :
         cmd = "IMS";
         break;
      default:
         cmd = "Unknown Command";
         break;
    }
    return cmd;
  }

  /**
   * \brief To convert the command type to the corresponding Mapper name
   * \fn std::string convertypetoMapperName(CmdType type)
   * \param type The type to convert
   * \return The corresponding mapper name
   */
  std::string
  convertypetoMapperName(CmdType type) {

    std::string mapperName;
    switch(type) {
      case UMS :
         mapperName = UMSMAPPERNAME;
         break;
      case TMS :
         mapperName = TMSMAPPERNAME;
         break;
      case FMS :
         mapperName = FMSMAPPERNAME;
         break;
      case IMS :
         mapperName = IMSMAPPERNAME;
         break;
      default:
         mapperName = "Uknown Mapper Name";
         break;
    }
    return mapperName;
  }

  /**
   * \fn ~ListCommandsServer()
   * \brief Destructor, raises an exception on error
   */
  ~ListCommandsServer()
  {
  }

  private:

   /////////////////////////////////
  // Attributes
  /////////////////////////////////

  /**
  * \brief The name of the ListCommandsServer command line
  */
  std::string mcommandName;
};

#endif
