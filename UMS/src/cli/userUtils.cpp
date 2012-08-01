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
 * \file userUtils.cpp
 * \brief This file defines useful functions and types for the VISHNU user commands 
 *  command
 * \author Ibrahima Cisse (ibrahima.cisse@sysfera.com)
 */


#include "Options.hpp"

#include "connectUtils.hpp"
#include "userUtils.hpp"
#include "utilVishnu.hpp"
#include<iostream>
using namespace std;

/**
 * \brief To build options for the VISHNU user commands
 * \param pgName : The name of the command
 * \param dietConfig: Represents the VISHNU config file
 * \param fPrivilege: The privilege option callback
 * \param ffirstname: The user first name option callback
 * \param fLastName: The user last name option callback
 * \param fEmail: The user email option callback
 * \param type: Indicates if it is an add or an update command, 0 means update, and 1 means add
 * \return The description of all options allowed by the command
 */


boost::shared_ptr<Options>
makeUserOptions(std::string pgName,std::string & dietConfig,
                privilegeCallBackType & fPrivilege, StringcallBackType& fFirstname,
                StringcallBackType& fLastname, StringcallBackType& fEmail, int type){


  boost::shared_ptr<Options> opt(new Options(pgName));

  opt->add("dietConfig,c",
           "The diet config file",
           ENV,
           dietConfig);

  Group_type group=CONFIG;

  if(type){// type =0 for "update function" and type=1 for "add function"

    group=HIDDEN;
  }


  opt->add("firstname,f",
           "The firstname of the user",
           group,
           fFirstname,
           type);



  if(type){

    opt->setPosition("firstname",1);

  }


  opt->add("lastname,l",
           "The lastname of the user",
           group,
           fLastname,
           type);

  if(type){
    opt->setPosition("lastname",1);

  }


  opt->add("privilege,p",
           "the privilege of the user (admin or simple user)",
           group,
           fPrivilege,
           type);


  if(type){
    opt->setPosition("privilege",1);
  }


  opt->add("email,m",
           "The email of the user",
           group,
           fEmail,
           type);

  if(type){
    opt->setPosition("email",1);

  }

  
  return opt;



}



boost::shared_ptr<Options>
makeUserOptions2(std::string pgName,std::string & dietConfig,
                privilegeCallBackType2 & fPrivilege, StringcallBackType& fFirstname,
                StringcallBackType& fLastname, StringcallBackType& fEmail, int type){


  boost::shared_ptr<Options> opt(new Options(pgName));

  opt->add("dietConfig,c",
           "The diet config file",
           ENV,
           dietConfig);

  Group_type group=CONFIG;

  if(type){// type =0 for "update function" and type=1 for "add function"

    group=HIDDEN;
  }


  opt->add("firstname,f",
           "The firstname of the user",
           group,
           fFirstname,
           type);



  if(type){

    opt->setPosition("firstname",1);

  }


  opt->add("lastname,l",
           "The lastname of the user",
           group,
           fLastname,
           type);

  if(type){
    opt->setPosition("lastname",1);

  }


  opt->add("privilege,p",
           "the privilege of the user (admin or simple user)",
           group,
           fPrivilege,
           type);


  if(type){
    opt->setPosition("privilege",1);
  }

  opt->add("email,m",
           "The email of the user",
           group,
           fEmail,
           type);

  if(type){
    opt->setPosition("email",1);

  }

  
  return opt;

}
