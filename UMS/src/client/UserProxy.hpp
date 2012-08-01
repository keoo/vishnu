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
 * \file UserProxy.hpp
 * \brief This file contains the VISHNU UserProxy class.
 * \author Daouda Traore (daouda.traore@sysfera.com)
 * \date February 2011
 */
#ifndef _USER_PROXY_H_
#define _USER_PROXY_H_

#include <string>
#include <iostream>

#include "SessionProxy.hpp"
#include "User.hpp"
#include "user.pb.h"

class SessionProxy;

/**
 * \class UserProxy 
 * \brief UserProxy class implementation 
 */
class UserProxy
{

  public:

    /**
     * \fn  UserProxy(const std::string& userId, const std::string& password) 
     * \param userId the user identifier
     * \param password the user password 
     * \brief Constructor, raises an exception on error
     */	
    UserProxy(const std::string& userId, const std::string& password);
    /**
     * \fn explicit UserProxy(SessionProxy session) 
     * \param session The object which encapsulates the session information (ex: identifier of the session)
     * \brief Constructor, raises an exception on error
     */
    explicit UserProxy(SessionProxy session);
    /**
     * \fn explicit UserProxy(const UMS_Data::User& user) 
     * \param user The object which encapsulates the user information 
     * \brief Constructor, raises an exception on error
     */
    explicit UserProxy(const UMS_Data::User& user);
    /**
     * \brief Function to add new user 
     * \fn  int add(UMS_Data::User& user)
     * \param user The object which encapsulates the user information
     * \return raises an exception on error
     */
    int add(UMS_Data::User& newUser);
    int add(UMS_Data_Proto::User& newUser);
    /**
     * \brief Function to update user information 
     * \fn  int update(const UMS_Data::User& user)
     * \param user The object which encapsulates the user information
     * \return raises an exception on error
     */
    int update(const UMS_Data::User& user);
    /**
     * \brief Function to update user information 
     * \fn  int update(const UMS_Data::User& user)
     * \param user The object which encapsulates the user information
     * \return raises an exception on error
     */
    int update(const UMS_Data_Proto::User& user);
    /**
     * \brief Function to remove user information 
     * \fn  int deleteUser(const UMS_Data::User& user) 
     * \param user The object which encapsulates the user information
     * \return raises an exception on error
     */
    int deleteUser(const UMS_Data_Proto::User& user);
    /**
     * \brief Function to change user password 
     * \fn  int changePassword(const std::string& oldPassword, const std::string& newPassword) 
     * \param oldPassword the old password of the user
     * \param newPassword the new password of the user 
     * \return raises an exception on error
     */
    int changePassword(const std::string& oldPassword, const std::string& newPassword);
    /**
     * \brief Function to reset user password 
     * \fn  int resetPassword(UMS_Data::User& user)
     * \param user The object which encapsulates the user information 
     * \return raises an exception on error
     */
    int resetPassword(UMS_Data::User& user);
    /**
     * \brief Function get user information 
     * \fn  UMS_Data::User getData() const
     * \return User object encapsulates the information of the user 
     * \return raises an exception on error
     */
    UMS_Data::User getData() const;
    /**
     * \brief Function get SessionProxy object which contains the VISHNU session identifier 
     * \fn SessionProxy getSessionProxy() const
     * \return a SessionProy object which contains the VISHNU session information 
     * \return raises an exception on error
     */
    SessionProxy getSessionProxy() const;

    /**
     * \fn ~UserProxy()
     * \brief Destructor, raises an exception on error
     */	
    ~UserProxy();

  private:

    /////////////////////////////////
    // Attributes
    /////////////////////////////////

    /**
     * \brief The object which encapsulates the user information 
     */
    UMS_Data::User muser;
    UMS_Data_Proto::User guser;
    
    /**
     * \brief The pointer to the SessionProxy object containing the encrypted identifier of the session
     *  generated by VISHNU
     */
    SessionProxy* msessionProxy;

};
#endif
