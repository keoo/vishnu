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

/*
 * fixtures.hpp
 *
 * Author: hguemar
 * 
 */

#ifndef FIXTURES_HPP_
#define FIXTURES_HPP_

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stdexcept>

#include <boost/assign/list_inserter.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/assign/std/vector.hpp>
#include <boost/filesystem.hpp>
#include "boost/process/all.hpp"
#include <boost/scoped_ptr.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include "config.h"
//#include "utils.hpp"

namespace ba = boost::assign;
namespace bf = boost::filesystem;
namespace bp = boost::process;
namespace bs = boost::system;

/* Diet test fixture (aka test context)
 * basically setup omniNames before starting our test 
 * and then cleanup after test has been executed
 */
class OmniNamesFixture {
    boost::scoped_ptr<bp::child> processNamingService;

    public:
    OmniNamesFixture() : processNamingService(0) {
        BOOST_TEST_MESSAGE( "== Test setup [BEGIN]: Launching OmniNames ==" );
	
	std::string exec;
	try {
	    exec = bp::find_executable_in_path("omniNames");
	} catch (bs::system_error& e) {
	    BOOST_TEST_MESSAGE( "can't find omniNames: " << e.what() );
	    return;
	}

	BOOST_TEST_MESSAGE( "omniNames found: " << exec );

	// setup omniNames environment
	bp::context ctx;
	ctx.process_name = "omniNames";
	ba::insert(ctx.env)
	    ("OMNINAMES_LOGDIR", OMNINAMES_LOGDIR)
	    ("OMNIORB_CONFIG", OMNIORB_CONFIG)
	    ("ORBsupportBooststrapAgent", "1")
	    ("ORBInitRef", ORB_INIT_REF);
	
	// redirect output to /dev/null
	ctx.streams[bp::stdout_id] = bp::behavior::null();
	ctx.streams[bp::stderr_id] = bp::behavior::null();

	// setup omniNames arguments
	std::vector<std::string> args = ba::list_of("-always")
	    ("-start")("2815")
	    ("-ignoreport")
	    ("-ORBendPoint")(OMNINAMES_ENDPOINT);
	// launch Naming Service
	bp::child c = bp::create_child(exec, args, ctx);
	processNamingService.reset(utils::copy_child(c));
	boost::this_thread::sleep(boost::posix_time::milliseconds(50));
    	BOOST_TEST_MESSAGE( "== Test setup [END]:  Launching OmniNames ==" );
    }

    ~OmniNamesFixture() {
    	BOOST_TEST_MESSAGE( "== Test teardown [BEGIN]: Stopping OmniNames ==" );
	if (processNamingService) {
	    processNamingService->terminate();
	    processNamingService->wait();
	}
	boost::this_thread::sleep(boost::posix_time::milliseconds(50));
    	BOOST_TEST_MESSAGE( "== Test teardown [END]: Stopping OmniNames ==" );
    }
};


class DietAgentFixture : public OmniNamesFixture
{
    boost::scoped_ptr<bp::child> processAgent;

public:
     DietAgentFixture() {
    	BOOST_TEST_MESSAGE( "== Test setup [BEGIN]:  Launching DIET Agent ==" );
	
	std::string exec;
	try {
	    exec = bp::find_executable_in_path("dietAgent");
	} catch (bs::system_error& e) {
	    BOOST_TEST_MESSAGE( "can't find dietAgent: " << e.what() );
	    return;
	}

	BOOST_TEST_MESSAGE( "dietAgent found: " << exec );
	
	// setup dietAgent environment
	bp::context ctx;
	ctx.process_name = "dietAgent";
	ctx.streams[bp::stdout_id] = bp::behavior::null();
	ctx.streams[bp::stderr_id] = bp::behavior::null();

	// setup dietAGent arguments
	std::vector<std::string> args = ba::list_of(AGENT_CONFIG);

	// launch diet Agent
	const bp::child c = bp::create_child(exec, args, ctx);
	processAgent.reset(utils::copy_child(c));
	boost::this_thread::sleep(boost::posix_time::milliseconds(50));
    	BOOST_TEST_MESSAGE( "== Test setup [END]: Launching DIET Agent ==" );
    }	
    
    ~DietAgentFixture() {
    	BOOST_TEST_MESSAGE( "== Test teardown [BEGIN]: Stopping DIET Agent ==" );
	if (processAgent) {
	    processAgent->terminate();
	    processAgent->wait();
	}
	boost::this_thread::sleep(boost::posix_time::milliseconds(50));
    	BOOST_TEST_MESSAGE( "== Test teardown [END]: Stopping DIET Agent ==" );
    }
};


// generic SeD fixture
template <const char *name, const char *config>
class DietSeDFixture : public DietAgentFixture
{
    boost::scoped_ptr<bp::child> processSeD;

public:
    DietSeDFixture()
    {
	BOOST_TEST_MESSAGE( "== Test setup [BEGIN]: Launching "
			    <<  name << " ==");

	std::string exec;
	try {
	    exec = bp::find_executable_in_path(name, BIN_DIR);
	} catch (bs::system_error& e) {
	    BOOST_TEST_MESSAGE( "can't find " << name << ": "
				<< e.what() );
	    BOOST_TEST_MESSAGE( "search path: " << BIN_DIR );
	    return;
	}
	
	BOOST_TEST_MESSAGE( "SeD found: " << exec );
	
	// setup SeD environment
	bp::context ctx;
	ctx.process_name = name;
 	ctx.streams[bp::stdout_id] = bp::behavior::null();
	ctx.streams[bp::stderr_id] = bp::behavior::null();
	
	// setup SeD arguments
	std::vector<std::string> args = ba::list_of(std::string(config));

	// launch SeD
	const bp::child c = bp::create_child(exec, args, ctx);
	processSeD.reset(utils::copy_child(c));
	boost::this_thread::sleep(boost::posix_time::milliseconds(50));
	BOOST_TEST_MESSAGE( "== Test setup [END]: launching "
			    << name << " ==" );
    }
    

    ~DietSeDFixture()
    {
	BOOST_TEST_MESSAGE( "== Test teardown [BEGIN]: Stopping "
			    << name << " ==" );
	if( processSeD ) {
	    processSeD->terminate();
	    processSeD->wait();
	}
	boost::this_thread::sleep(boost::posix_time::milliseconds(50));
	BOOST_TEST_MESSAGE( "== Test teardown [BEGIN]: Stopping "
			    << name << " ==" );
    }
};

// must not be static 
// should be a primitive type with an identifier name
char UMSSeD[] = "umssed";
char ConfigUMSSeD[] = UMSSEDCONF;
//typedef DietSeDFixture<SimpleAddSeD, ConfigSimpleAddSeD> SimpleAddSeDFixture;
typedef DietSeDFixture<UMSSeD, ConfigUMSSeD> UMSSeDFixture;

#endif /* FIXTURES_HPP_ */
