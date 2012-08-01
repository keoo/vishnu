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

class Database;

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
  static Database *mdatabaseVishnu;
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
