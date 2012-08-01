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
 * \file configureOptionUtils.hpp
 * \brief This file declare useful functions and types for the VISHNU configure 
 * option command
 * \author Ibrahima Cissé (ibrahima.cisse@sysfera.com)
 */

#include "configureOptionUtils.hpp"
#include "Options.hpp"
#include "cliUtil.hpp"
#include "utils.hpp"
#include "utilVishnu.hpp"
#include <boost/bind.hpp>

using namespace vishnu;

/**
 * \brief To build options for the VISHNU configure option command
 * \param opt: Describes all allowed options for the VISHNU configure option
 * command
 * \param dietConfig: Represents the VISHNU config file
 * \param fOptionName : A callback for the option name
 * \param fValue      : A callback for the option value
 */


void makeConfigureOptions(boost::shared_ptr<Options> opt,std::string& dietConfig,
                          StringcallBackType& fOptionName,StringcallBackType& fValue){



  opt->add("dietConfig,c",
           "The diet config file",
           ENV,
           dietConfig);


  opt->add("optionName",
           "the name of an option",
           HIDDEN,
           fOptionName,
           1);

  opt->setPosition("optionName",1);


  opt->add("value",
           "The value of an option",
           HIDDEN,
           fValue,
           1);

  opt->setPosition("value",1);


}


/**
 * \brief A common function betwenn the VISHNU configure option command
 * and the VISHNU configure default option command
 * \param opt:  Describes all allowed options for the command
 * \param ac :  The number of parameters the command takes
 * \param av : The name of all of that parameters
 * \param conf_func: The VISHNU API function, configureOption or
 * ConfigureDefaultOption
 * \return 0 if the function succeeds, an error code otherwise
 */



int commonConfigure(boost::shared_ptr<Options> opt, int ac, char* av[], const ConfigureCallBackType& conf_func){


  /******* Parsed value containers ****************/

  std::string dietConfig;

  std::string sessionKey;


  /********** EMF data ************/


  UMS_Data::OptionValue optionValue;

  /******** Callback functions ******************/


  boost::function1<void,std::string> fOptionName( boost::bind(&UMS_Data::OptionValue::setOptionName,boost::ref(optionValue),_1));
  boost::function1<void,std::string> fValue( boost::bind(&UMS_Data::OptionValue::setValue,boost::ref(optionValue),_1));

  /**************** Describe options *************/

  makeConfigureOptions(opt,dietConfig,fOptionName, fValue);


  try{

  /**************  Parse to retrieve option values  ********************/

  opt->parse_cli(ac,av);

  opt->parse_env(env_name_mapper());

  opt->notify();


  /********  Process **************************/

  checkVishnuConfig(*opt);

  /************** Call UMS connect service *******************************/

  // initializing DIET

  if (vishnuInitialize(const_cast<char*>(const_cast<char*>(dietConfig.c_str())), ac, av)) {
   
    errorUsage(av[0],dietErrorMsg,EXECERROR);
    
    exit(CLI_ERROR_DIET);
  }


  // get the sessionKey


  /********************************************/


  sessionKey=getLastSessionKey(getppid());


    if(false==sessionKey.empty()){

      conf_func(sessionKey,optionValue);


    }

  }
  catch(po::required_option& e){// a required parameter is missing

    usage(*opt,"[options] optionName value ",requiredParamMsg);

    return CLI_ERROR_MISSING_PARAMETER;
  }

  catch(po::error& e){ // catch all other bad parameter errors

    errorUsage(av[0], e.what());

    return CLI_ERROR_INVALID_PARAMETER;
  }


  catch(VishnuException& e){// catch all Vishnu runtime error

    std::string  msg = e.getMsg()+" ["+e.getMsgComp()+"]";

    errorUsage(av[0], msg,EXECERROR);

    //check the bad session key

    if (checkBadSessionKeyError(e)){

      removeBadSessionKeyFromFile(getppid());
    }


    return e.getMsgI() ;
  }

  catch(std::exception& e){// catch all std runtime error

    errorUsage(av[0], e.what());

    return CLI_ERROR_RUNTIME;
  }

  return 0;


}// end of main








