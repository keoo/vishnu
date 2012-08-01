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
 * \file listHistoryCmdUtils.cpp
 * \brief This file defines useful functions and types for the VISHNU list history
 *  command
 * \author Ibrahima Cisse (ibrahima.cisse@sysfera.com)
 */



#include "Options.hpp"

#include "listHistoryCmdUtils.hpp"
#include<iostream>
using namespace std;

/**
 * \brief To build options for the VISHNU list history command
 * \param pgName : The name of the command
 * \param fUserId: The user identifier option callback
 * \param dietConfig: Represents the VISHNU config file
 * \param fSessionId : The callback for the session identifier
 * \param startDateOption: The start date option
 * \param endDateOption: The end date option
 * \return The description of all options allowed by the command
 */
boost::shared_ptr<Options> 
makeListHistoryCmdOptions(std::string pgName,StringcallBackType& fUserId,std::string & dietConfig,
                          StringcallBackType& fSessionId,
                          std::string& startDateOption,
                          std::string& endDateOption){


  boost::shared_ptr<Options> opt(new Options(pgName));


  opt->add("dietConfig,c",
           "The diet config file",
           ENV,
           dietConfig);

  opt->add("adminListOption,a",
           "is an admin option to list with respect to all users ",
           CONFIG);

  opt->add("userId,u",
           "an admin option to precise the list\n"
           "with respect to a specific user identified by his/her userId",
           CONFIG,
           fUserId);

  opt->add("sessionId,i",
           "lists with respect to a specific session",
           CONFIG,
           fSessionId);

  opt->add("startDateOption,s",
           "allows the user to organize the list\n"
           "by providing the start date\n"
           "(in the format ""YYYY-MM-DD H:mm:ss "")",
           CONFIG,
           startDateOption);

  opt->add("endDateOption,e",
           "allows the user to organize the list\n"
           "by providing the end date \n"
           "(in the format ""YYYY-MM-DD H:mm:ss "")"
           "By default, the end date is the current day",
           CONFIG,
           endDateOption);

  return opt;

}





