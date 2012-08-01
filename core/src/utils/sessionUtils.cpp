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

#include "sessionUtils.hpp"
#include "cliError.hpp"
#include <boost/archive/archive_exception.hpp>
#include <stdexcept>
#include <cstdlib>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include "UMSVishnuException.hpp"
namespace bfs = boost::filesystem;
namespace bs = boost::serialization;

/**
 * \brief A default constructor
 * \param closePolicy: the close session type with default value equal to 0
 */

SessionEntry::SessionEntry( int closePolicy_):closePolicy(closePolicy_){}


/**
 * \brief Another constructor taking parameters
 * \param sessionKey_: the key of the session
 * \param closePolicy_: the session close type with 0 as default value
 */


SessionEntry::SessionEntry(const std::string& sessionKey_, int closePolicy_)
  : closePolicy(closePolicy_), sessionKey(sessionKey_) {}


/**
 * \brief To get the key of the session
 * \return The key of the session
 */


std::string
SessionEntry::getSessionKey()const{
  return sessionKey;
}

/**
 * \brief To get the session close type
 * \return The session close type
 */


int
SessionEntry::getClosePolicy()const{
  return closePolicy;
}

/**
 * \brief The serializer function
 * \param ar: An archive type which can be text type or xml type
 * \param version: The version of serialized class
 */


template<class Archive>
void
SessionEntry::serialize(Archive& ar, const unsigned int version){
 // ar & sessionKey & closePolicy ;
  ar & bs::make_nvp("sessionKey", sessionKey) & bs::make_nvp("closePolicy",closePolicy) ;
}


/**
 * \brief A helper to display a session parameters
 * \param os: A stream where the session parameters will be printed
 * \param session:The session to print
 * \return The stream where the session parameters have been printed
 */
std::ostream&
operator <<(std::ostream& os, const SessionEntry& session){
  std::cout << "sessionKey: " << session.sessionKey << "  closePolicy: "<< session.closePolicy << std::endl;
  return os;
}



/**
 * \brief To record  sessions in a file
 * \param allSessions: A set of sessions which will be stored in the file
 * \param file       : the path of the file
 * \exception        : raises a Boost archive exception
 */

template <class T>
void
saveIntoFile(SessionContainer& allSessions, const char* file){

  std::ofstream ofile (file);

  T ar(ofile);

//  ar << allSessions;

  ar << bs::make_nvp("sessions",allSessions);

  ofile.close();
}


/**
 * \brief  To load all sessions stored in a file
 * \param allSessions: The sessions stored in the file
 * \param file       : The file storing the sessions
 * \exception        : raises a Boost archive exception
 */


template <class T>
void
getFromFile(SessionContainer& allSessions, const char* file){

  std::ifstream ifile(file);

  T ar(ifile);

 // ar >> allSessions;
 ar >> bs::make_nvp("sessions",allSessions);

  ifile.close();
}


/**
 * \brief To store a the current session running in a terminal in the file
 * \param session : the current session
 * \param terminal: The terminal in which the session is running
 */

void
storeLastSession(const SessionEntry& session,const std::string& terminal){

  SessionContainer allSessions;


  allSessions=getAllSessions(terminal);


  allSessions.push_back(session);

  saveIntoFile<binary_oarchive>(allSessions, terminal.c_str());

}


/**
 * \brief helper function which which wrappes getFromFile function
 * and ensures that all error exception is catched .
 * \param terminal: the file corresponding to the terminal which launched the
 * serialization process
 * \return all sessions stored into the file or an empty container
 */


SessionContainer
getAllSessions(const std::string& terminal){

  SessionContainer allSessions;

  bfs::path pid_file(terminal);

  if( bfs::exists(pid_file) && !bfs::is_empty(pid_file)){

    getFromFile<binary_iarchive>(allSessions, terminal.c_str());

  }
  return allSessions;

}


/**
 * To get the last open session corrseponding to the last session stored in the
 * file
 * \param terminal : The terminal in which the session was running
 * \return The last stored session
 */


SessionEntry
getLastSession(const std::string& terminal){

  SessionContainer allSessions;


  allSessions=getAllSessions(terminal);

  if(allSessions.empty()){

    std::cerr <<"There is no open session in this terminal\n";

    exit (CLI_ERROR_NO_SESSION);

  }


  return allSessions.back();


}


/**
 * \brief To remove the last entry of session from the file
 * \param terminal : The terminal in which the session was running
 */

void
removeLastSession(const std::string & terminal){

  SessionContainer allSessions;


  allSessions=getAllSessions(terminal);



  if (!allSessions.empty()){


    allSessions.pop_back();


    saveIntoFile<binary_oarchive>(allSessions, terminal.c_str());

  }
  else{// all session have been closed

    std::ofstream file(terminal.c_str(), std::ios::out | std::ios::trunc);

    if (file){

      file.close();
    }
    throw std::runtime_error( "all sessions in this terminal have been closed");
  }

}


/**
 * \brief To get the path of the file in which the sessions open from a terminal
 * had been stored
 * \param tpid : the identifier of the terminal as process
 * \return the path of the file in which the sessions open from the terminal had
 * been stored
 */



std::string
getSessionLocation(int tpid){

  // change current directory
  bfs::path home_dir = getenv("HOME");
  bfs::path  session_dir = home_dir;
  bfs::path  session_file ;
  session_dir /= ".vishnu";

  session_dir /= "sessions";

  std::ostringstream ss;
  ss<<tpid;
  session_file=session_dir;
  session_file/=ss.str();

  if(!bfs::exists(session_dir)){
    bfs::create_directories(session_dir);
  }


  return session_file.string();


}

/**
 * \brief Another function to store last session open
 * \param sessionKey: The key of the session which will be stored
 * \param closePolicy: The session close type
 * \param ppid: The identifier of the terminal as process
 */


void
storeLastSession(const std::string& sessionKey ,int closePolicy,int ppid){

  std::string sessionFile=getSessionLocation(ppid);

  SessionEntry session(sessionKey,closePolicy);

  storeLastSession(session,sessionFile.c_str());


}



/**
 * \brief To get the last session key
 * \param ppid: The identifier of the terminal as process in which the session
 * had been open
 * \return The key of the last session open from the terminal
 */

std::string
getLastSessionKey(int ppid){

  std::string sessionFile=getSessionLocation(ppid);


  SessionEntry session=getLastSession(sessionFile);


  return(session.getSessionKey());


}

/**
 * \brief To remove the bad session keys stored in the session file
 * \param ppid : The process identifier of the terminal in which the session had
 * been open.
 */ 
void
removeBadSessionKeyFromFile(int ppid){

    std::string sessionFile=getSessionLocation(ppid); // get the path of the session file

    removeLastSession(sessionFile);// remove from the file

}



/**
 * \brief A helper function which check if an given exception represents a bad
 * sessionKey
 *\param e: a given VishnuException
 *\return   : true if it's a bad session key or false otherwhise
 */
bool
checkBadSessionKeyError(const VishnuException& e){

return( (e.getMsgI()==ERRCODE_SESSIONKEY_NOT_FOUND) || e.getMsgI()==ERRCODE_SESSIONKEY_EXPIRED   );

}

