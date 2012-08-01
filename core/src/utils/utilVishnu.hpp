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
* \file utilVishnu.hpp
* \brief This file presents the utils functions of the vishnu system
* \author Eugène PAMBA CAPO-CHICHI (eugene.capochichi@sysfera.com)
* \date 15/02/2011
*/

#ifndef _UTILVISHNU_H_
#define _UTILVISHNU_H_

#include <iostream>
#include <sstream>

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"
#include "FMSVishnuException.hpp"
#include <boost/filesystem.hpp>
#include "user.pb.h"
using namespace boost::posix_time;
using namespace boost::gregorian;
namespace bfs=boost::filesystem;


/**
* \enum BatchType
* \brief The type of the Batch
*/
typedef enum {
  TORQUE = 0,/*!< For TORQUE batch type */
  LOADLEVELER = 1,/*!< For LOADLEVELER batch type */
  SLURM = 2, /*!< For SLURM batch type */
  UNDEFINED = 3 /*!< IF batch type is not defined*/
} BatchType;


std::istream& operator >> (std::istream& in, UMS_Data_Proto::User::PrivilegeType& value) ;
std::istream& operator >> (std::istream& in, UMS_Data_Proto::User::StatusType& value) ;


std::ostream& operator << (std::ostream& out, UMS_Data_Proto::User::PrivilegeType& value);
std::ostream& operator << (std::ostream& out, UMS_Data_Proto::User::StatusType& value);

/**
* \brief Function to encrypt data and password
* \param clef is the data to be encrypted
* \param salt This string is used to perturb the algorithm
* \return the string encrypted
*/
char* crypt(const char* clef, const char* salt);
/**
 * \namespace vishnu
 * \brief This naspace contains utils functions of the vishnu system
 */
namespace vishnu {

  static const std::string ROOTUSERNAME = "root";
  static const std::string UMSMAPPERNAME = "UMS";
  static const std::string TMSMAPPERNAME = "TMS";
  static const std::string IMSMAPPERNAME = "IMS";
  static const std::string FMSMAPPERNAME = "FMS";

  static const int PASSWORD_MAX_SIZE = 8;

  /**
  * \brief Generic function to convert an object to string
  * \param val is a generic data to be transformed to string
  * \return the string version of val
  */
  template <class T>
  std::string convertToString(T val) {
    std::ostringstream out;
    out << val;
    return out.str();
  }

  /**
   * \brief Function to convert a given date into correspondant long value
   * \fn long long convertToTimeType(std::string date)
   * \param date The date to convert
   * \return The converted value
   */
  long long convertToTimeType(std::string date);

  /**
  * \brief Function to convert a string to int
  * \param  val a value to convert to int
  * \return int value of the corresponding string
  */
  int
  convertToInt(std::string val);

  /**
   * \brief To crypt a password
   * \fn std::string cryptPassword(const std::string& salt, const std::string password)
   * \param salt The salt to use to crypt
   * \param password The password to crypt
   * \return The crypted password
   */
  std::string
  cryptPassword(const std::string& salt, const std::string password) ;

  /**
  * \brief Function to get a random number
  * \fn    int generateNumbers()
  * \return the number generated
  */
  int
  generateNumbers();

  /**
   * \brief To retrieve the password
   * \param prompt: The message inviting the user to enter his/her password
   * \return The password entered.
   */
  std::string
  takePassword(const std::string& prompt);

  /**
   * \brief Simple function to convert time
   * from string format (YYYY-MM-DD H:mm:ss) to
   * long integer format in seconds
   * \param ts: the time in string format
   * \return the time in long integer format in seconds
   */
  std::time_t
  string_to_time_t(const std::string& ts);

  /**
   * \brief Simple function to read the content of a regular file
   * \param filePath: the path to the file
   * \return The content of the file
   */
  std::string
  get_file_content(const std::string& filePath);

  /**
  * \brief Function to move file
  * \param src: the path of the file to move
  * \param dest: the destination where the file will be moved
  * \param filename: the name of the file in dest
  * \return raises an exception on error
  */
  int
  boostMoveFile(const std::string& src, const std::string& dest,  const std::string& filename="");

  /**
   * \brief Function to check a numerical value
   * \param value The value to check
   * \return raises an exception on error
   */
  bool isNumericalValue(const std::string value);

  /**
   * \brief Function a given walltime into string
   * \param walltime The walltime to convert
   * \return the walltime converted to string
   */
   std::string convertWallTimeToString(const long& walltime);

   /**
    * \brief Function a given walltime into seconds
    * \param walltime The walltime to convert
    * \return the walltime converted to seconds
    */
   long convertStringToWallTime(const std::string& walltime);

   /**
    * \brief Function to check the job status
    * \param status the status of the job
    * \return raises an exception on error
    */
   void
   checkJobStatus(const int& status);

   /**
    * \brief Function to check the job priority
    * \param priority the priority of the job
    * \return raises an exception on error
    */
   void
   checkJobPriority(const int& priority);

   /**
    * \brief Function to check the job nbNodesAndCpuPerNode
    * \param nbNodesAndCpuPerNode the number of nodes and cpu per node
    * \return raises an exception on error
    */
   void
   checkJobNbNodesAndNbCpuPerNode(const std::string& nbNodesAndCpuPerNode);

   /**
    * \brief Function to get current time in seconds (UTC)
    * \return the time as the number of seconds since the Epoch, 1970-01-01 00:00:00 +0000 (UTC)
    */
   time_t getCurrentTimeInUTC();

   /**
    * \brief Function to convert UTC time into localtime (seconds)
    * \param localtime the local time
    * \return the correspondant localtime (seconds)
    */
   time_t convertUTCtimeINLocaltime(const time_t& localtime);

   /**
    * \brief Function to localtime into UTC (seconds)
    * \param localtime the local time
    * \return the diffence time (seconds)
    */
   time_t convertLocaltimeINUTCtime(const time_t& localtime);

   /**
    * \brief Function to return the difference between localtime and UTC time (seconds)
    * \return the difference time (seconds)
    */
    long diffLocaltimeUTCtime();

   /**
    * \brief Function to create temporary file
    * \param fileName The name of the file to create
    * \param file_content The content of the file
    */
   void createTmpFile(char* fileName, const std::string& file_content);

   /**
    * \brief Function to create temporary file
    * \param fileName The name of the file to create
    */
   void createTmpFile(char* fileName);

   /**
    * \brief Function to delete file
    * \param fileName The name of the file to create
    * \return 0 in case of success, another value otherwise
    */
   int deleteFile(const char* fileName);

   /**
    * \brief Function to print success message
    */
   inline void printSuccessMessage() {
     // can be used to display a message when vishnu service was performed successfully
     ;
   }

   /**
    * \brief Function to display the session key
    */
   inline void printSessionKeyMessage() {
     // can be used to display a message containing the current session key
     ;
   }

  /**
    * \brief Function to check the metric value
    * \param metric: the metric value
    * \return raises an exception on error
    */
   void
   checkMetricHistoryValue(const int& metric);

   /**
    * \brief Function to check the remote file path
    * \param path the remote file path
    * \return raises an exception on error
    */
   void
   checkRemotePath(const std::string& path);

   /**
    * \brief Check if the pid exists
    * \param pid The given pid
    * \param proc_dir The given process info directory
    * \return True if the pid exists
    */

   bool
     process_exists(const std::string& pid, const bfs::path& proc_dir="/proc");

/**
 * \brief Get the fully qualified name for the current system
 * \param port the port
 * \return the fully qualified name for the current system
 */


std::string getLocalMachineName(const std::string& port );


}
#endif // _UTILVISHNU_H_
