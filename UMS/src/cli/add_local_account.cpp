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
 * \file add_local_account.cpp
 * This file defines the VISHNU add local account command 
 * \author Ibrahima Cisse (ibrahima.cisse@sysfera.com)
 */



#include "common.hpp"
#include "cliUtil.hpp"
#include "utils.hpp"
#include "localAccountUtils.hpp"
#include "sessionUtils.hpp"
#include "utilVishnu.hpp"
#include <boost/bind.hpp>
#include <boost/filesystem.hpp>
#include "GenericCli.hpp"
namespace po = boost::program_options;

using namespace std;
using namespace vishnu;

struct AddLocalAccountFunc {

  UMS_Data::LocalAccount mnewAcLogin;

  AddLocalAccountFunc(UMS_Data::LocalAccount newAcLogin): mnewAcLogin(newAcLogin)
  {};

  int operator()(std::string sessionKey) {
    string sshPublicKey;
    int res=addLocalAccount(sessionKey,mnewAcLogin,sshPublicKey);// call the UMS add local account service

    //To construct the file to save
    boost::filesystem::path home_dir = getenv("HOME");
    boost::filesystem::path  config_dir = home_dir;
    config_dir /= ".vishnu";
    config_dir /= "localAccountPublicKey";


    if(!boost::filesystem::exists(config_dir)){
      boost::filesystem::create_directories(config_dir);
    }

    std::string publicKeyName;
    publicKeyName.append(config_dir.string()+"/");
    publicKeyName.append(mnewAcLogin.getUserId());
    publicKeyName.append("-"+mnewAcLogin.getMachineId());

    ofstream os(publicKeyName.c_str());
    os << sshPublicKey;

    std::cout << "The ssh public key path is  " << publicKeyName << std::endl;

    return res;
  }
};

int main (int ac, char* av[]){

  /******* Parsed value containers ****************/

  string dietConfig;

  /********** EMF data ************/

  UMS_Data::LocalAccount newAcLogin;

  /******** Callback functions ******************/

  boost::function1<void,string> fUserId( boost::bind(&UMS_Data::LocalAccount::setUserId,boost::ref(newAcLogin),_1));
  boost::function1<void,string> fMachineId( boost::bind(&UMS_Data::LocalAccount::setMachineId,boost::ref(newAcLogin),_1));
  boost::function1<void,string> fAcLogin( boost::bind(&UMS_Data::LocalAccount::setAcLogin,boost::ref(newAcLogin),_1));
  boost::function1<void,string> fSshKeyPath( boost::bind(&UMS_Data::LocalAccount::setSshKeyPath,boost::ref(newAcLogin),_1));
  boost::function1<void,string> fHomeDirectory( boost::bind(&UMS_Data::LocalAccount::setHomeDirectory,boost::ref(newAcLogin),_1));


  /**************** Describe options *************/

  boost::shared_ptr<Options> opt=makeLocalAccountOptions(av[0], fUserId,dietConfig,fMachineId,
      fAcLogin,fSshKeyPath,fHomeDirectory,1);

  CLICmd cmd = CLICmd (ac, av, opt);
  int ret = cmd.parse(env_name_mapper());

  if (ret != CLI_SUCCESS){
    helpUsage(*opt,"userId machineId acLogin sshKeyPath homeDirectory");
    return ret;
  }

  // PreProcess (adapt some parameters if necessary)
  checkVishnuConfig(*opt);
  if ( opt->count("help")){
    helpUsage(*opt,"userId machineId acLogin sshKeyPath homeDirectory");
    return 0;
  }

  AddLocalAccountFunc apiFunc(newAcLogin);
  return GenericCli().run(apiFunc, dietConfig, ac, av);

}// end of main




