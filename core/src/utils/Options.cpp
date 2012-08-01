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

#include "Options.hpp"

#include <string>
#include <list>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

using namespace std;
namespace po=boost::program_options;
/* Default constructor. */
Configuration::Configuration() {
  pgName = "unknown";
}

/* Standard constructor. Get the program name as parameter. */
Configuration::Configuration(const std::string& pgName) {
  this->pgName = pgName;
}

/* Generic program configuration accessors. */
const string& Configuration::getConfigFile() const {
  return configFile;
}

const std::string& Configuration::getPgName() const {
  return pgName;
}

void Configuration::setConfigFile(const string& configFile) {
  this->configFile = configFile;
}

// standard Options constructor. Get a string (command name)

Options:: Options(const std::string& pgName )   : conf(new Configuration(pgName)),
                                                  generic_options("Generic Options"),
                                                  config_options("Configuration"),
                                                  hidden_options("Hidden Options"),
                                                  env_options("Environment variables") {

  generic_options.add_options()
   ("help,h", "produce help message");


  }

/* Standard Options constructor. Get a pointer on a config object*/
Options::Options(boost::shared_ptr<Configuration> otherConf):conf(otherConf),
                                                             generic_options("Generic Options"),
                                                             config_options("Configuration"),
                                                             hidden_options("Hidden Options"),
                                                             env_options("Environment variables") {

  generic_options.add_options()
   ("help,h", "produce help message");



  }

boost::shared_ptr<Configuration>
Options::getConfiguration()const{

  return this->conf;



}

/**
 * \brief a private function used to set option group
 * \param tmp_options: the set of options to group
 * \param group      : the group to set
 */

void
Options::setGroup (const po::options_description& tmp_options,
                   const Group_type& group){


  switch(group){

    case GENERIC:// for options always allowed

      generic_options.add(tmp_options);
      break;

    case CONFIG: // for options use to configure the command

      config_options.add(tmp_options);
      break;

    case ENV: // for global options

      env_options.add(tmp_options);
      break;

    case HIDDEN: // for command parameters

      hidden_options.add(tmp_options);
      break;

    default:// for unknown option group

      break;

  }
}


/**
 * \brief function allowing to add a new non-typed option
 * \param name: the name of the option
 * \param desc: brief description of the option
 * \param group: a group which option belongs to
 */

void
Options::add(const std::string& name,
             const std::string& desc, const Group_type& group ){


  po::options_description tmp_options;

  tmp_options.add_options()(name.c_str(),desc.c_str());

  setGroup(tmp_options,group);

}

  /**
      *
      * \brief function provinding a way to add a boolean option
      * \param name: the name of the option
      * \param desc: brief description of the option
      * \param group: a group which option belongs to
      * \param value: the value of the option when option is provided in
      * command line
      * \param required: for required option
      */

      template<>
      void Options::add(const std::string& name,
              const std::string& desc,
              const Group_type& group,
              bool& value,
              int required){

          po::options_description tmp_options;

          po::typed_value<bool>* optionvalue=po::bool_switch(&value);


          if (required){

            optionvalue=optionvalue->required();
          }

            tmp_options.add_options()(name.c_str(),optionvalue,desc.c_str());


          // Set the group

          setGroup(tmp_options,group);

        }
     

/**
 *
 * \brief Function providing another way to add a typed option
 * \param name: the name of the option
 * \param desc: brief description of the option
 * \param group: a group which option belongs to
 * \param userFunc: The user defined function (callback)
 * command line
 * \param required: for required option
 */

template<>
void Options::add(const std::string& name,
    const std::string& desc,
    const Group_type& group,
    boost::function1<void, bool>& userFunc,
    int required){

  po::options_description tmp_options;

  po::typed_value<bool>* optionvalue=po::bool_switch()->notifier(userFunc);


  if (required){

    optionvalue=optionvalue->required();
  }

  tmp_options.add_options()(name.c_str(),optionvalue,desc.c_str());

  // Set the group

  setGroup(tmp_options,group);

}







/**
 * \brief To set position of options
 * \param name: the name of the option
 * \param pos :  the required position
 */

void
Options::setPosition(const std::string& name, int pos ){
  this->position.add(name.c_str(),pos);
}

/**
 * \brief To parse command line
 * \param ac: The number of parameters of the command
 * \param av: the names of all paramters
 */


void
Options::parse_cli(int ac, char* av[]) {

  po::options_description cmdline_options;

  cmdline_options.add(generic_options)
    .add(config_options)
    .add(env_options)
    .add(hidden_options);

  store(po::command_line_parser(ac, av)
      .options(cmdline_options).positional(position)
      .run(), vm);
}

/**
 * \brief To parse the configuration file
 */

void
Options::parse_cfile() {

  po::options_description cfile_options;

  cfile_options.add(config_options)
               .add(hidden_options)
               .add(env_options);

  ifstream ifs(conf->getConfigFile().c_str());

  store(parse_config_file(ifs,cfile_options), vm);

}

/**
 * \brief To parse environement variable
 * \param name_mapper: a functor providing a simple name from the conventional
 * name of the environment variable
 * Ex: for VISHNU_CONFIG_FILE, it returns dietConfig
 */

void
Options::parse_env(const func1& name_mapper) {

  store(parse_environment(env_options,name_mapper), vm);
}




/**
 * \brief To notify all  user-defined functionsi (callbacks)
 */

void
Options::notify (){

  po::notify(vm);

}

/**
 * \brief To check if an option is provided after parsing the command
 * line
 * \param key: the name of the option
 */

int
Options::count(const std::string& key)const{

  return (vm.count(key));
}


/**
 * \brief to print the set of options allowed by a command
 * \param os: Where options wiil be printed.
 * \param opt: the options to print.
 * \return the stream where the options are printed.
 */


std::ostream&
operator<< (std::ostream & os, const Options & opt){


  po::options_description visible("Allowed options");

  visible.add(opt.generic_options)
         .add(opt.config_options)
         .add(opt.env_options);

  os << visible << endl;

  return os;
}

/**
 * \brief  The default destructor
 */

Options::~Options(){}
