#include "Server.hpp"
#include <vector>
#include <string>
#include <sstream>
#include <boost/shared_ptr.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/lexical_cast.hpp>

Server::Server(const std::string& name, const std::vector<std::string> &serv,
               const std::string& uri) :
    mname(name), mservices(serv), muri(uri){
}

Server::~Server(){
}


int
Server::add(const std::string& service) {
  bool found = false;
  unsigned int i;
  for (i = 0; i < mservices.size(); ++i) {
    if (service.compare(mservices.at(i)) == 0) {
      found = true;
    }
  }
  if (!found) {
    mservices.push_back(service);
  }
  return 0;
}

int
Server::remove(const std::string& service) {
  unsigned int i;
  for (i = 0; i < mservices.size(); ++i) {
    if (service.compare(mservices.at(i)) == 0) {
      mservices.erase(mservices.begin() + i);
    }
  }
  return 0;
}

bool
Server::hasService(const std::string& service) const {
  unsigned int i;
  for (i = 0; i < mservices.size(); i++){
    if (mservices[i] == service) {
      return true;
    }
  }
  return false;
}

std::string
Server::getName() const {
  return mname;
}


std::string
Server::getURI() const {
  return muri;
}

std::vector<std::string>&
Server::getServices() {
  return mservices;
}



std::string
Server::toString() {
  std::stringstream res;
  unsigned int i;
  res << mname << "$$$"
      << muri << "$$$";
  for (i = 0 ; i < mservices.size() - 1 ; ++i){
    res << mservices.at(i) << "$$$";
  }
  res << mservices.at(mservices.size()-1);
  return res.str();
}

boost::shared_ptr<Server>
Server::fromString(const std::string& prof) {
  boost::shared_ptr<Server> res;
  std::vector<std::string> vecString;
  boost::algorithm::split_regex(vecString, prof, boost::regex("\\${3}"));
  std::string name;
  std::string uri;
  std::vector<std::string> services;

  if (!vecString.empty()) {
    std::vector<std::string>::iterator it = vecString.begin();
    name = std::string(strdup((it++)->c_str()));
    uri = std::string(strdup((it++)->c_str()));

    for (int i = 0; it != vecString.end(); ++it, i++) {
      services.push_back(std::string(strdup(it->c_str())));
    }
    res.reset(new Server(name, services, uri));
  }
  return res;
}
