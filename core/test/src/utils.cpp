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

#include "utils.hpp"

#include <map>
#include <ostream>
#include <iostream>

#include <boost/assign/list_inserter.hpp>
#include <boost/filesystem.hpp>
#include <boost/format.hpp>
#include <boost/scoped_array.hpp>
#include <boost/test/unit_test.hpp>

#include "diet_config_tests.h"

namespace utils {
    namespace ba = boost::assign;
    namespace bf = boost::filesystem;

    bp::child *copy_child(const bp::child& c)
    {
	std::map<bp::stream_id, bp::handle> handles;
	ba::insert(handles)
	    (bp::stdin_id, c.get_handle(bp::stdin_id))
	    (bp::stdout_id, c.get_handle(bp::stdout_id))
	    (bp::stderr_id, c.get_handle(bp::stderr_id));

	return new bp::child(c.get_id(), handles);
    }


    ClientArgs::ClientArgs(std::string progName,
			   std::string config)
    {
	size_t len = progName.length();
	exec.reset(new char[len + 1]);
	std::strncpy(exec.get(), progName.c_str(), len + 1);
	args[0] = exec.get();

	/* config file path */
	bf::path config_path(CONFIG_DIR);
	config_path /= config;

	const char *tmp = config_path.c_str();
	len = std::strlen(tmp);
	configFile.reset(new char[len + 1]);
	std::strncpy(configFile.get(), tmp, len+1);
	args[1] = configFile.get();
	args[2] = 0;

        std::cout << std::endl; // hack for having clean xml outputs
	BOOST_TEST_MESSAGE( "config file path : " << args[1] );
        std::cout << std::endl; // hack for having clean xml outputs
    }

    // for debugging purpose only
    std::ostream& operator<<(std::ostream& s, const ClientArgs& c)
    {
	s << boost::format("Configuration file: %1%\n"
	    		   "argc: %2%\n"
	    		   "argv[0]: %3%\n"
	    		   "argv[1]: %4%\n"
			   "argv[2]: %5%\n")
	    % c.configFile.get()
	    % c.argc()
	    % c.args[0]
	    % c.args[1]
	    % (c.args[2] == 0);
    }


}
