/**
 * \file create_file.cpp
 * This file defines the VISHNU submit job command 
 * \author Daouda Traore (daouda.traore@sysfera.com)
 */


#include "CLICmd.hpp"
#include "utilVishnu.hpp"
#include "cliError.hpp"
#include "cliUtil.hpp"
#include "api_ums.hpp"
#include "api_fms.hpp"
#include "sessionUtils.hpp"
#include "FMS_Data.hpp"
#include "cmdArgs.hpp"
#include <boost/bind.hpp>

namespace po = boost::program_options;

using namespace std;
using namespace vishnu;

boost::shared_ptr<Options>
makeListDirOpt(string pgName,
            string& path,
            string& dietConfig,
            FMS_Data::LsDirOptions& lsDirOptions){

  boost::shared_ptr<Options> opt(new Options(pgName));

  // Environement option
  opt->add("dietConfig,c",
      "The diet config file",
      ENV,
      dietConfig);

  opt->add("longFormat,l",
      "It specifies the long display format (all available file information",
      CONFIG);

  if(opt->count("longFormat")){
    lsDirOptions.setLongFormat(true);
  }

  opt->add("allFiles,a",
      "Allows to display all files including hidden file",
      CONFIG);

  if(opt->count("allFiles")){
    lsDirOptions.setAllFiles(true);
  }

   opt->add("path,p",
      "The directory to list following the pattern [host:]directory path.",
      HIDDEN,
      path,1);
  opt->setPosition("path",1);

  return opt;
}


int main (int argc, char* argv[]){
  
  int ret; // Return value

  /******* Parsed value containers ****************/
  string dietConfig;
  string sessionKey;
  string path;
  StringList dirContent;

   /********** EMF data ************/
  FMS_Data::LsDirOptions lsDirOptions;
  
  /**************** Describe options *************/
  boost::shared_ptr<Options> opt=makeListDirOpt(argv[0], path,dietConfig,lsDirOptions);

  CLICmd cmd = CLICmd (argc, argv, opt, dietConfig);

 // Parse the cli and setting the options found
  ret = cmd.parse(env_name_mapper());
  
  if (ret != CLI_SUCCESS){
    helpUsage(*opt,"[options] path");
    return ret;
  }

  // PreProcess (adapt some parameters if necessary)
  checkVishnuConfig(*opt);  
  if ( opt->count("help")){
    helpUsage(*opt,"[options] path");
    return 0;
  }

 if ( opt->count("allFiles")){
     lsDirOptions.setAllFiles(true);
  }

 if ( opt->count("longFormat")){
     lsDirOptions.setLongFormat(true);
  }


  // Process command
  try {
    std::cout << "dietConfig: "  << dietConfig << "\n";
    // initializing DIET
    if (vishnuInitialize(const_cast<char*>(dietConfig.c_str()), argc, argv)) {
      errorUsage(argv[0],dietErrorMsg,EXECERROR);
      return  CLI_ERROR_DIET ;
    }

    // get the sessionKey
    sessionKey=getLastSessionKey(getppid());

    // DIET call 
    if(false==sessionKey.empty()){
      cout <<currentSessionKeyMsg << sessionKey <<endl;
      listDir(sessionKey, path, dirContent, lsDirOptions);

      // FIXME by the Grand Daouda
      std::vector<std::string> dirContentvec=dirContent.getStrings();
      std::vector<string>::const_iterator it;
      std::cout << path << ": \n";
      for (it=dirContentvec.begin(); it!=dirContentvec.end(); ++it){
        std::cout << *it << "\n"; 
      }
    }
  } catch(VishnuException& e){// catch all Vishnu runtime error
    std::string  msg = e.getMsg()+" ["+e.getMsgComp()+"]";
    errorUsage(argv[0], msg,EXECERROR);
    //check the bad session key
    if (checkBadSessionKeyError(e)){
      removeBadSessionKeyFromFile(getppid());
    }
    return e.getMsgI() ;
  } catch(std::exception& e){// catch all std runtime error
    errorUsage(argv[0],e.what());
    return CLI_ERROR_RUNTIME;
  }

  return 0;
}
