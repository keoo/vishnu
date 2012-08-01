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
 * \file UserException.hpp
 * \brief This file defines class for the Vishnu exceptions coming from the user.
 * \author Kevin Coulomb (kevin.coulomb@sysfera.com)
 */
#ifndef __USEREXCEPTION__
#define __USEREXCEPTION__

#include "VishnuException.hpp"

// RESERVED CODES FROM 10 TO 19
static const int ERRCODE_INVALID_PARAM = 10;
static const int ERRCODE_FILENOTFOUND = 11;
static const int ERRCODE_CONFIGNOTFOUND = 12;

/**
 * \brief This class represents the exception due to a user misuse
 * \class UserException
 */
class UserException :
  public VishnuException {
public:

private :
protected :
  /**
   * \brief Function to initialize all the generic messages
   * \fn void initMsg()
   */
  void
  initMsg();

public :

  /**
   * \brief Default constructor
   * \fn UserException()
   */
  UserException();
  /**
   * \brief Copy constructor
   * \fn UserException(const UserException& e)
   */
  UserException(const UserException& e);
  /**
   * \brief Constructor
   * \fn UserException(int msg, std::string msgComp = "")
   */
  UserException(int msg, std::string msgComp = "");
  /**
   * \brief Default destructor
   * \fn ~UserException() throw()
   */
  virtual ~UserException() throw(){};
  /**
   * \brief Function to get the exception type in string
   * \fn std::string getTypeS() const
   * \return Returns the type of the exception
   */
  std::string
  getTypeS() const;
  /**
   * \brief To get the generic message
   * \fn std::string getMsg() const
   * \return Returns the message
   */
  std::string
  getMsg() const;
};

#endif // VISHNUEXCEPTION
