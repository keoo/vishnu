/**
 * \file ServerUMS.hpp
 * \brief This file presents the implementation of the UMS server.
 * \author Eugène PAMBA CAPO-CHICHI (eugene.capochichi@sysfera.com)
 * \date 31/01/2001
*/

#ifndef _SERVERUMS_H_
#define _SERVERUMS_H_

#include <string>
/**
 * \brief Number of service in UMS
 */
#define NB_SRV 25
#include "DIET_server.h"
#include "UMSMapper.hpp"
#include "TMSMapper.hpp"
#include "FMSMapper.hpp"
#include "IMSMapper.hpp"
#include "MapperRegistry.hpp"
#include "DbConfiguration.hpp"

class SOCIDatabase;

static const char* SRV[NB_SRV] = {
  "sessionConnect",
  "sessionReconnect",
  "sessionClose",
  "userCreate",
  "userUpdate",
  "userDelete",
  "userPasswordChange",
  "userPasswordReset",
  "machineCreate",
  "machineUpdate",
  "machineDelete",
  "localAccountCreate",
  "localAccountUpdate",
  "localAccountDelete",
  "configurationSave",
  "configurationRestore",
  "optionValueSet",
  "optionValueSetDefault",
  "sessionList",
  "localAccountList",
  "machineList",
  "commandList",
  "optionValueList",
  "userList",
  "restore"};
/**
 * \class ServerUMS
 * \brief This class describes the UMS server
 */
class ServerUMS {
public :

  /**
   * \brief To get the unique instance of the server
   */
  static ServerUMS*  getInstance();

  /**
  * \brief To get the vishnuId
  * \fn int getVishnuId()const
  * \return the path of the configuration file
  */
  int
  getVishnuId() const;

  /**
  * \brief To get the path to the sendmail script
  * \fn std::string getSendmailScriptPath() const
  * \return the path of the configuration file
  */
  std::string
  getSendmailScriptPath() const;

   /**
   * \brief To initialize the UMS server
   * \param vishnuId  The identifier of the vishnu instance
   * \param dbConfig  The configuration of the database
   * \param sendmailScriptPath The path to the script for sending emails
   * \return an error code (0 if success and 1 if an error occurs)
   */
  int
  init(int vishnuId, DbConfiguration dbConfig, std::string sendmailScriptPath);

  /**
   * \brief Destructor, raises an exception on error
   * \fn ~ServerUMS()
   */
  ~ServerUMS();

private :

  /**
   * \brief Constructor, private because class is singleton
   */
  ServerUMS();

  /**
   * \brief operator=
   */
  ServerUMS& operator=(const ServerUMS&);

  /////////////////////////////////
  // Attributes
  /////////////////////////////////
  /**
   * \brief The singleton reference
   */
  static ServerUMS *minstance;
  /**
  * \brief The path to the sendmail script
  */
  std::string msendmailScriptPath;
  /**
  * \brief The vishnu id
  */
  int mvishnuId;
  /**
  * \brief Structure representing a profile description
  */
  diet_profile_desc_t* mprofile;
  /**
  * \brief Instance of Database
  */
  static SOCIDatabase *mdatabaseVishnu;
  /**
  * \brief Instance of UMSMapper
  */
  static UMSMapper *mmapper;
  /**
  * \brief Instance of UMSMapper
  */
  static TMSMapper *mmapperTMS;
  /**
  * \brief Instance of UMSMapper
  */
  static FMSMapper *mmapperFMS;
  /**
  * \brief Instance of UMSMapper
  */
  static IMSMapper *mmapperIMS;
};
#endif // SERVERUMS