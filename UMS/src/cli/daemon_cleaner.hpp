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

#ifndef DAEMON_CLEANER_HPP
#define DAEMON_CLEANER_HPP
/**
 * \file daemon_cleaner.hpp
 * \brief This file defines a few functions to close properly session
 * and clean the corresponding file.
 * \author Ibrahima Cisse (ibrahima.cisse@sysfera.com)
 * \author Haikel Guemar (haikel.guemar@sysfera.com)
 */

/* Posix headers */
#include <cerrno>
#include <fcntl.h>
#include <cstdio>
#include <cstring>
#include <csignal>
#include <syslog.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
/* C standard library */
#include <cstdlib>
/* C++ standard library */
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
/* Boost headers */
#include <boost/scoped_ptr.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/interprocess/sync/file_lock.hpp>
#include <boost/thread/thread.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
namespace bfs = boost::filesystem;
namespace bi = boost::interprocess;
namespace btt = boost::this_thread;
namespace bpt = boost::posix_time;
/**
 * \brief Check if the pid exists
 * \fn bool pid_exists(const std::string& pid)
 * \param pid The given pid
 * \return True if the pid exists
 */
bool 
pid_exists(const std::string& pid);

/**
 * \brief Deletes the file corresponding to the terminal closed
 * \param dietConfig: The VISHNU configuration file
 * \param ac: The number of command parameters
 * \param av: The names of parameters
 */
void 
deleter(char* dietConfig,int ac,char* av[]);

/**
 * \brief Creates a child process and call the deleter() function
 * \param dietConfig: The VISHNU configuration file
 * \param ac: The number of command parameters
 * \param av: The names of parameters
 */

void 
cleaner(char* dietConfig,int ac,char* av[]);

#endif
