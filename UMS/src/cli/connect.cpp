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
 * \file connect.cpp
 * This file defines the VISHNU connect command 
 * \author Ibrahima Cisse (ibrahima.cisse@sysfera.com)
 */

#include "common.hpp"
#include "cliUtil.hpp"
#include "utils.hpp"
#include "connectUtils.hpp"
#include "sessionUtils.hpp"
#include <boost/bind.hpp>
#include "daemon_cleaner.hpp"
#include "utilVishnu.hpp"
#include "UMSVishnuException.hpp"

namespace po = boost::program_options;

using namespace std;
using namespace vishnu;



int main (int ac, char* av[]){


  /******* Parsed value containers ****************/

  string dietConfig;

  std::string userId;

  std::string password;


  /********** EMF Data ****************************/


  UMS_Data::ConnectOptions connectOpt;



  /******** Callback functions ******************/

  boost::function1<void,UMS_Data::SessionCloseType> fClosePolicy( boost::bind(&UMS_Data::ConnectOptions::setClosePolicy,boost::ref(connectOpt),_1));
  boost::function1<void,int> fSessionInactivityDelay( boost::bind(&UMS_Data::ConnectOptions::setSessionInactivityDelay,boost::ref(connectOpt),_1));
  boost::function1<void,string> fSubstituteUserId( boost::bind(&UMS_Data::ConnectOptions::setSubstituteUserId,boost::ref(connectOpt),_1));

  /*********** Out parameters *********************/


  UMS_Data::Session session;

  /**************** Describe options *************/

  boost::shared_ptr<Options> opt=makeConnectOptions(av[0],userId,1,dietConfig);

  opt->setPosition("userId",-1);

  opt->add("sessionInactivityDelay,d", "The session inactivity delay",CONFIG,fSessionInactivityDelay);


  opt->add("substituteUserId,s","The substitute user identifier",CONFIG,fSubstituteUserId);

  opt->add("closePolicy,p","for closing session automatically",ENV,fClosePolicy );
  
  opt->add("password,w","To give the password ",CONFIG,password );

  try{


    /**************  Parse to retrieve option values  ********************/

    opt->parse_cli(ac,av);

    opt->parse_env(UMS_env_name_mapper());

    opt->notify();


    /********  Process **************************/

    checkVishnuConfig(*opt);

    //Fix me

    if(0==opt->count("password")){

    password= vishnu::takePassword("password: ");
    
    }

    /************** Call UMS connect service *******************************/

    cleaner(const_cast<char*>(dietConfig.c_str()), ac, av);// lauch the daemon cleaner if it is not already running

    // initializing DIET
    if (vishnuInitialize(const_cast<char*>(dietConfig.c_str()), ac, av)) {
    
      errorUsage(av[0],dietErrorMsg,EXECERROR);
    
      return  CLI_ERROR_DIET ;
    }


    connect(userId,password, session, connectOpt);// call the api extern connect service to get a session key

    vishnuFinalize();

    storeLastSession(session.getSessionKey(),session.getClosePolicy(),getppid()); // store sessionKey into $HOME/.vishnu/sessions

    std::cout << "sessionId: " << session.getSessionId() << "\n";
    printSuccessMessage();


  }// End of try bloc


  catch(po::required_option& e){// a required parameter is missing

    usage(*opt,"[options] userId ",requiredParamMsg);
    
    return CLI_ERROR_MISSING_PARAMETER;
  }
  // {{RELAX<CODEREDUCER> The error handling is the same in all command 

  catch(po::error& e){ // catch all other bad parameter errors

    errorUsage(av[0], e.what());
    
    return CLI_ERROR_INVALID_PARAMETER;
  }

  catch(VishnuException& e){// catch all Vishnu runtime error

    // handle the temporary password
    if(ERRCODE_TEMPORARY_PASSWORD==e.getMsgI()){
    
      errorUsage(av[0],"Your password is temporary, use vishnu_change_password command to change it",EXECERROR);
    }

    else{
    
      std::string  msg = e.getMsg()+" ["+e.getMsgComp()+"]";
    
      errorUsage(av[0],msg,EXECERROR);
    }

    return e.getMsgI() ;

  }

  catch(std::exception& e){ // catch all std runtime error

    errorUsage(av[0], e.what());
    
    return CLI_ERROR_RUNTIME;
  }
  
  return 0;

// }}RELAX<CODEREDUCER>

}// end of main


