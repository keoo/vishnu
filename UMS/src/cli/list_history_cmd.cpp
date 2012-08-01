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
 * \file list_histoty_cmd.cpp
 * This file defines the VISHNU list history command 
 * \author Ibrahima Cisse (ibrahima.cisse@sysfera.com)
 */


#include "common.hpp"
#include "listHistoryCmdUtils.hpp"
#include "sessionUtils.hpp"
#include "cliUtil.hpp"
#include "utils.hpp"
#include "utilVishnu.hpp"
#include<boost/bind.hpp>
#include "GenericCli.hpp"
namespace po = boost::program_options;

using namespace std;
using namespace vishnu;

struct ListCommandsFunc {

  UMS_Data::ListCommands mlistCmd;

  UMS_Data::ListCmdOptions mlistOptions;
  bool mfull;

  ListCommandsFunc(const UMS_Data::ListCommands& listCmd,const UMS_Data::ListCmdOptions& listOptions, bool full):
    mlistCmd(listCmd), mlistOptions(listOptions), mfull(full)
  {};

  int operator()(std::string sessionKey) {
    int res = listHistoryCmd(sessionKey,mlistCmd,mlistOptions);
    // Display the list
    if(mfull) {
      cout << mlistCmd << endl;
    }
    else {
      for(unsigned int i = 0; i <mlistCmd.getCommands().size(); i++) {
        cout << mlistCmd.getCommands().get(i) << endl;
      }
    }

    return res;
  }
};


int main (int ac, char* av[]){

  /******* Parsed value containers ****************/

  string dietConfig;

  string startDateOption;
  string endDateOption;

  /********** EMF data ************/

  UMS_Data::ListCommands listCmd;

  UMS_Data::ListCmdOptions listOptions;

  /******** Callback functions ******************/

  boost::function1<void,string> fUserId( boost::bind(&UMS_Data::ListCmdOptions::setUserId,boost::ref(listOptions),_1));
  boost::function1<void,string> fSessionId( boost::bind(&UMS_Data::ListCmdOptions::setSessionId,boost::ref(listOptions),_1));

  /**************** Describe options *************/

  boost::shared_ptr<Options> opt= makeListHistoryCmdOptions(av[0],fUserId, dietConfig, fSessionId, startDateOption, endDateOption);

  bool isEmpty;
  //To process list options
  GenericCli().processListOpt(opt, isEmpty, ac, av);

  if ( opt->count("help")){
    helpUsage(*opt,"[option]");
    return 0;
  }

  /********  Process **************************/

  bool full = false;
  // Display the list
  if(isEmpty || opt->count("adminListOption")) {
    full = true;
  }

  /********  Process **************************/

    if (opt->count("adminListOption")){

      listOptions.setAdminListOption(true);
    }

    checkVishnuConfig(*opt);

    if ( opt->count("help")){

      helpUsage (*opt," [options]  ");

      return 0;
    }

    //convert the date in long format 

    if(opt->count("startDateOption")){
      listOptions.setStartDateOption(string_to_time_t(startDateOption));
    }

    if(opt->count("endDateOption")){
      listOptions.setEndDateOption(string_to_time_t(endDateOption));
    }


  ListCommandsFunc listFunc(listCmd,listOptions, full);
  return GenericCli().run(listFunc, dietConfig, ac, av);
}// end of main


  
