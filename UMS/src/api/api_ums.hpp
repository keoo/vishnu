/**
 * \file api_ums.hpp
 * \brief This file contains the VISHNU api functions.
 * \authors Daouda Traore (daouda.traore@sysfera.com) and Ibrahima Cisse (ibrahima.cisse@sysfera.com)
 */
#ifndef _API_UMS_H_
#define _API_UMS_H_

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "SessionProxy.hpp"
#include "MachineProxy.hpp"
#include "LocalAccountProxy.hpp"
#include "ConfigurationProxy.hpp"
#include "OptionValueProxy.hpp"
#include "QueryProxy.hpp"

/**
   * \brief Function to initialize the SYSFERA-DS configuration
   * \fn int vishnuInitialize(char* cfg, int argc, char** argv)
   * \param cfg The SYSFERA-DS configuration file
   * \param argc 
   * \param argv
   * \return 
 */
int vishnuInitialize(char* cfg, int argc, char** argv);

/**
   * \brief Function to 
   * \fn int vishnuFinalize() 
   * \return 
 */
void vishnuFinalize();

 /**
   * \brief Function to open a session 
   * \fn int connect(const std::string& userId, const std::string& password, std::string& sessionKey(), 
   *                  const UMS_Data::ConnectOptions& connectOpt=UMS_Data::ConnectOptions())
   * \param userId The VISHNU user identifier
   * \param password The password of the user
   * \param sessionKey The encrypted identifier of the session generated by VISHNU 
   * \param connectOpt To encapsulate the options available for the connect method. It allows the user 
   *  to choose the way for way for closing the session automatically on TIMEOUT or on DISCONNECT and the
   *  possibility for an admin to open a session as she was a specific user
   *  \return raises an exception on error
   */
int connect(const std::string& userId, const std::string& password, std::string& sessionKey, 
            const UMS_Data::ConnectOptions& connectOpt=UMS_Data::ConnectOptions()); 

int reconnect(const std::string& userId, const std::string& password, const std::string& sessionId, std::string& sessionKey);

int close(const std::string& sessionKey);

int addVishnuUser(const std::string& sessionKey, const UMS_Data::User& newUser);

int updateUser(const std::string& sessionKey, const UMS_Data::User& user);

int deleteUser(const std::string& sessionKey, const std::string& userId);

int changePassword(const std::string& userId, const std::string& password, const std::string& passwordNew);

int resetPassword(const std::string& sessionKey, const std::string& userId);

int addMachine(const std::string& sessionKey, const UMS_Data::Machine& newMachine);

int updateMachine(const std::string& sessionKey, const UMS_Data::Machine& machine);

int deleteMachine(const std::string& sessionKey, const std::string& machineId);

int addLocalAccount(const std::string& sessionKey, const UMS_Data::LocalAccount& newLocalAccount, std::string&  sshPublicKey);

int updateLocalAccount(const std::string& sessionKey, const UMS_Data::LocalAccount& localAccount);

int deleteLocalAccount(const std::string& sessionKey, const std::string& userId, const std::string& machineId);

int saveConfiguration(const std::string& sessionKey, const std::string& filePath, UMS_Data::Configuration& config);

int restoreConfiguration(const std::string& sessionKey, const std::string& filePath);

int configureOption(const std::string& sessionKey, const UMS_Data::OptionValue& optionValue);

int configureDefaultOption(const std::string& sessionKey, const UMS_Data::OptionValue& optionValue);

int listSessions(const std::string& sessionKey, UMS_Data::ListSessions& listSession, 
                 const UMS_Data::ListSessionOptions& options=UMS_Data::ListSessionOptions());

int listLocalAccount(const std::string& sessionKey, UMS_Data::ListLocalAccounts& listLocalAcc,
                     const UMS_Data::ListLocalAccOptions& options=UMS_Data::ListLocalAccOptions()); 

int listMachine(const std::string& sessionKey, UMS_Data::ListMachines& listMachine,
                const UMS_Data::ListMachineOptions& options=UMS_Data::ListMachineOptions());

int listHistoryCmd(const std::string& sessionKey, UMS_Data::ListCommands& listCommands,
                   const UMS_Data::ListCmdOptions& options=UMS_Data::ListCmdOptions());

int listOptions(const std::string& sessionKey, UMS_Data::ListOptionsValues& listOptValues,
                const UMS_Data::ListOptOptions& options=UMS_Data::ListOptOptions());

int listUsers(const std::string& sessionKey, UMS_Data::ListUsers& listUsers, 
              const std::string& userIdOption=std::string());

#endif
