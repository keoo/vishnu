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
 * \file SystemException.hpp
 * \brief This file defines the super class for the Vishnu exceptions.
 * \author Kevin Coulomb (kevin.coulomb@sysfera.com)
 */
#ifndef __SYSTEMEXCEPTION__
#define __SYSTEMEXCEPTION__

#include "VishnuException.hpp"

// RESERVED CODES FROM 1 TO 9
static const int ERRCODE_DIET = 1;
static const int ERRCODE_DBERR = 2;
static const int ERRCODE_DBCONN = 3;
static const int ERRCODE_SYSTEM = 4;
static const int ERRCODE_INVCOMP = 5;
static const int ERRCODE_INVMAPPER = 6;
static const int ERRCODE_INVEXCEP = 7;
static const int ERRCODE_INVDATA = 8;
static const int ERRCODE_SSH = 9;

/**
 * \brief This class represents the exception that are due to the system
 * \class SystemException
 */
class SystemException : public VishnuException {

public:

  /**
   * \brief Default constructor
   * \fn SystemException()
   */
  SystemException();
  /**
   * \brief Copy constructor
   * \fn SystemException(const SystemException& e)
   */
  SystemException(const SystemException& e);
  /**
   * \brief Constructor
   * \fn SystemException(int msg, std::string msgComp = "")
   */
  SystemException(int msg, std::string msgComp = "");
  /**
   * \brief Default destructor
   * \fn ~SystemException()
   */
  virtual ~SystemException() throw(){};
  /**
   * \brief To get the generic message
   * \fn std::string getMsg() const
   * \return Returns the message
   */
  std::string
  getMsg() const;
  /**
   * \brief Function to get the exception type in string
   * \fn std::string getTypeS() const
   * \return Returns the type of the exception
   */
  std::string
  getTypeS() const;
  /**
   * \brief Function to initialize all the generic messages
   * \fn void initMsg()
   */
  void
  initMsg();
};

#endif // VISHNUEXCEPTION
