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

#ifndef GENERIC_CLI_HPP
#define GENERIC_CLI_HPP


#include "CLICmd.hpp"
#include "utilVishnu.hpp"
#include "cliError.hpp"
#include "cliUtil.hpp"
#include "sessionUtils.hpp"
#include <boost/bind.hpp>

namespace po = boost::program_options;

using namespace std;
using namespace vishnu;

/**
 * \brief A generic class to handle some command line operations like run a
 * function
 * \param function the api function
 * \param dietConfig the VISHNU client config file
 * \param ac The number of command line arguments
 * \param av The command line arguments
 * \return 0 if it succeeds or an error code otherwise
 */


class GenericCli {

  public:

    /**
     * \brief A generic class to handle some command line operations like run a
     * function
     * \param function the api function
     * \param dietConfig the VISHNU client config file
     * \param ac The number of command line arguments
     * \param av The command line arguments
     * \return 0 if it succeeds or an error code otherwise
     */


    template <class ApiFunc>
      int run(ApiFunc function, std::string dietConfig, int ac, char*  av[]) {

        try{

          // initializing DIET

          if (vishnuInitialize(const_cast<char*>(dietConfig.c_str()), ac, av)) {

            errorUsage(av[0],dietErrorMsg,EXECERROR);

            return  CLI_ERROR_DIET ;
          }

          // get the sessionKey
          std::string sessionKey=getLastSessionKey(getppid());

          // DIET call 
          if(false==sessionKey.empty()){
            printSessionKeyMessage();
            //call of the api fuction
            function(sessionKey);

            printSuccessMessage(); 

          }
        } catch(VishnuException& e){// catch all Vishnu runtime error
          std::string  msg = e.getMsg()+" ["+e.getMsgComp()+"]";
          errorUsage(av[0], msg,EXECERROR);
          //check the bad session key
          if (checkBadSessionKeyError(e)){
            removeBadSessionKeyFromFile(getppid());
          }
          return e.getMsgI() ;
        } catch(std::exception& e){// catch all std runtime error
          errorUsage(av[0],e.what());
          return CLI_ERROR_RUNTIME;
        }

      }

    /**
     * \brief A generic class to handle some command line operations like run a
     * functioni without managing the session
     * \param function the api function
     * \param dietConfig the VISHNU client config file
     * \param ac The number of command line arguments
     * \param av The command line arguments
     * \return 0 if it succeeds or an error code otherwise
     */


    template <class ApiFunc>
      int runWithoutSessionKey(ApiFunc function, std::string dietConfig, int ac, char*  av[]) {

        try{

          // initializing DIET

          if (vishnuInitialize(const_cast<char*>(dietConfig.c_str()), ac, av)) {

            errorUsage(av[0],dietErrorMsg,EXECERROR);

            return  CLI_ERROR_DIET ;
          }

          //call of the api fuction
          function();

          printSuccessMessage(); 

        } catch(VishnuException& e){// catch all Vishnu runtime error
          std::string  msg = e.getMsg()+" ["+e.getMsgComp()+"]";
          errorUsage(av[0], msg,EXECERROR);
          return e.getMsgI() ;
        } catch(std::exception& e){// catch all std runtime error
          errorUsage(av[0],e.what());
          return CLI_ERROR_RUNTIME;
        }

      }


    /**
     * \brief To parse command line options 
     * \param opt the description of the command line options
     * \param isEmpty To check if command line does not contain option
     * \param ac The number of command line arguments
     * \param av The command line arguments 
     * \param signature The signature of the command
     */
    void processListOpt(const boost::shared_ptr<Options>& opt, bool& isEmpty, int ac, char*  av[], 
        const std::string& signature=std::string()) {

      CLICmd cmd = CLICmd (ac, av, opt);
      try {
        opt->parse_cli(ac,av);

        isEmpty=opt->empty();//if no value was given in the command line
        // Parse the cli and setting the options found
        int ret = cmd.parse(env_name_mapper());

        if (ret != CLI_SUCCESS){
          helpUsage(*opt,"[option] "+signature);
          exit(ret);
        }

        // PreProcess (adapt some parameters if necessary)
        checkVishnuConfig(*opt);
        if ( opt->count("help")){
          helpUsage(*opt,"[option] "+signature);
          exit(0);
        }

      }
      catch(po::error& e){ // catch all other bad parameter errors
        helpUsage(*opt,"[option] "+signature);
        exit(CLI_ERROR_INVALID_PARAMETER);
      }
      catch(std::exception& e){// catch all std runtime error
        errorUsage(av[0],e.what());
        exit(CLI_ERROR_INVALID_PARAMETER);
      }

    }
};

#endif 
