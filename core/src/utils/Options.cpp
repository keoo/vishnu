#include "Options.hpp"

#include <boost/program_options/detail/parsers.hpp>
#include <boost/program_options/parsers.hpp>
#include <limits>                       // for numeric_limits
#include <string>
#include <fstream>


using namespace std;
namespace po=boost::program_options;
/* Default constructor. */
Configuration::Configuration() : pgName("unknown") {
}

/* Standard constructor. Get the program name as parameter. */
Configuration::Configuration(const std::string& pgName) : pgName(pgName) {}

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
Options::getConfiguration() const {
  return this->conf;
}

/**
 * \brief a private function used to set option group
 * \param tmp_options: the set of options to group
 * \param group      : the group to set
 */

void
Options::setGroup (const po::options_description& tmp_options,
                   const Group_type& group) {
  switch(group) {
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
             const std::string& desc, const Group_type& group ) {
  po::options_description tmp_options;

  tmp_options.add_options()(name.c_str(), desc.c_str());
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
                  int required) {
  po::options_description tmp_options;
  po::typed_value<bool>* optionvalue=po::bool_switch(&value);

  if (required) {
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
                  int required) {
  po::options_description tmp_options;
  po::typed_value<bool>* optionvalue=po::bool_switch()->notifier(userFunc);


  if (required) {
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
Options::setPosition(const std::string& name, int pos ) {
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
 * Ex: for VISHNU_CONFIG_FILE, it returns configFile
 */

void
Options::parse_env(const func1& name_mapper) {
  store(parse_environment(env_options,name_mapper), vm);
}




/**
 * \brief To notify all  user-defined functionsi (callbacks)
 */

void
Options::notify () {
  po::notify(vm);
}

/**
 * \brief To check if an option is provided after parsing the command
 * line
 * \param key: the name of the option
 */

int
Options::count(const std::string& key) const {
  return (vm.count(key));
}

  /**
   * \brief prints the name and description of a parameter
   * \param name the name of the parameter
   * \param desc the description of the parameter
   * \param nameMaxSize the maximum number of character the name can
   *  be printed on (used to add the correct number of spaces to align
   *  descriptions of several parameters)
   * \param os the stream where the parameter will be printed on
   */
void
Options::printParams(const std::string &name, const std::string &desc,
                     unsigned int nameMaxSize, std::ostream &os) const {
  static const unsigned int default_line_length(80);
  static const unsigned int foffset = 2;
  static const unsigned int moffset = 3;
  std::string ret = "";
  std::string tmp = desc;
  unsigned int posfirstchar = nameMaxSize + foffset + moffset;
  unsigned int maxLen = default_line_length - posfirstchar;

  size_t pos = tmp.rfind(" ", maxLen);
  while (pos != std::string::npos && (tmp.size() > maxLen)) {
    ret += tmp.substr(0, pos) + "\n" + std::string(posfirstchar, ' ');
    tmp = tmp.substr(pos + 1);
    pos = tmp.rfind(" ", maxLen);
  }
  ret += tmp;

  os << std::string(foffset, ' ') << name
     << std::string(nameMaxSize - name.size() + moffset, ' ')
     << ret << "\n\n";
}


/**
 * \brief to print the set of options allowed by a command
 * \param os: Where options will be printed.
 * \param opt: the options to print.
 * \return the stream where the options are printed.
 */
std::ostream&
operator<< (std::ostream & os, const Options & opt) {
  po::option_description param;
  std::string name;
  unsigned int maxSize(0);

  // First print parameters
  os << "Parameters:\n";

  if (numeric_limits<unsigned>::max() == opt.position.max_total_count()) {
    name = opt.position.name_for_position(0);
    param = opt.hidden_options.find(name, true);
    opt.printParams(name, param.description(), maxSize, os);
  } else {
    unsigned int i;
    for (i = 0; i < opt.position.max_total_count(); i++) {
      if (maxSize < opt.position.name_for_position(i).size()) {
        maxSize = opt.position.name_for_position(i).size();
      }
    }

    for (i = 0; i < opt.position.max_total_count(); i++) {
      name = opt.position.name_for_position(i);
      param = opt.hidden_options.find(name, true);
      opt.printParams(name, param.description(), maxSize, os);
    }
  }

  // Now Print options
  po::options_description visible("Allowed options");
  visible.add(opt.generic_options)
         .add(opt.config_options)
         .add(opt.env_options);

  os << visible << "\n";

  return os;
}

std::string
Options::getPositionalOptString() const {
  std::string optS = "";

  if (numeric_limits<unsigned>::max() == position.max_total_count()) {
    optS += position.name_for_position(0) + "... ";
  } else {
    for (unsigned int i = 0; i < position.max_total_count(); i++) {
      optS += position.name_for_position(i) + " ";
    }
  }

  return optS;
}


/**
 * \brief  The default destructor
 */

Options::~Options() {}
