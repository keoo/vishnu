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
 * utils.hpp
 * 
 * Created on: 10 january 2010
 * Author: hguemar
 *
 * some utilities
 *
 */


#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <string>
#include <iosfwd>

#include <boost/array.hpp>
#include <boost/process/all.hpp>

namespace utils {
    namespace bp = boost::process;

    /* free function allowing us to build a boost::process::child 
       from an existing boost::process::child */
    bp::child *copy_child(const bp::child& c);

    /* encapsulate client arguments required for diet_initialize() */
    class ClientArgs
    {
	static const int nbArgs = 2;
	char *args[3];
	boost::scoped_array<char> configFile;
	boost::scoped_array<char> exec;

	public:
	ClientArgs(std::string progName,
		   std::string config=std::string(""));
	
	int argc() const { return nbArgs; }
	// fugly 
	char **argv() const { return const_cast< char **>(args); }
	char *config() const { return configFile.get(); }
	
	friend std::ostream& operator<<(std::ostream&, const ClientArgs&);
    };

    std::ostream& operator<<(std::ostream&, const ClientArgs&);
    
}


#endif /* UTILS_HPP_ */
