/**
 * \file PingerProxy.cpp
 * \brief This file contains the VISHNU implementation of the PingerProxy class.
 * \author Kevin Coulomb (kevin.coulomb@sysfera.com)
 * \date December 2013
 */

#include <map>
#include <string>
#include "PingerProxy.hpp"
#include "DIET_client.h"
#include "utilClient.hpp"

PingerProxy::PingerProxy(){
}

PingerProxy::~PingerProxy(){
}

// Looking the service whose name starts by "service" and that is the longest
std::string
PingerProxy::getLongestService(std::vector<std::string>& list, std::string service){
  std::string res = "";
  std::vector<std::string>::iterator it;
  for (it = list.begin() ; it != list.end() ; ++it){
    if (it->find(service) == 0 &&
	it->size() > res.size()){
      res = *it;
    }
  }
  return res;
}

std::string
PingerProxy::ping(const std::string& server, const std::string mid){
  std::string msg;
  if (server.compare("dispatcher") == 0){
    communicate_dispatcher("3", msg);
  } else {
    diet_profile_t* profile = NULL;
    std::string serviceName = "heartbeat"+server;
    if (!mid.empty())
      serviceName += std::string("@")+mid;
    profile = diet_profile_alloc(serviceName,0,0,1);
    if(diet_call(profile)){
      raiseCommunicationMsgException("VISHNU call failure");
    }
    diet_string_get(profile,1, msg);
  }
  return msg;
}

void
PingerProxy::allPing(std::map<std::string, std::string>& result){
  std::string response;
// Ping the dispatcher
  communicate_dispatcher("3", response);
  result.insert(std::pair<std::string, std::string>("dispatcher", response));

// Get the list of the servers in the dispatcher
  communicate_dispatcher("2", response);
  std::vector<boost::shared_ptr<Server> > servers;
  extractServersFromMessage(response, servers);
  // For each server ping it
  std::vector<boost::shared_ptr<Server> >::iterator it;
  for (it = servers.begin() ; it != servers.end() ; ++it){
    diet_profile_t* profile = NULL;
    std::string service = getLongestService(it->get()->getServices(), "heartbeat");
    profile = diet_profile_alloc(service,0,0,1);
    // Pinging
    if (diet_call_gen(profile, it->get()->getURI())){
      result.insert(std::pair<std::string, std::string>(it->get()->getURI(), "FAILURE"));
    } else {
      std::string tmp;
      diet_string_get(profile, 1, tmp);
      result.insert(std::pair<std::string, std::string>(it->get()->getURI(), tmp));
    }
    diet_profile_free(profile);
  }
}
