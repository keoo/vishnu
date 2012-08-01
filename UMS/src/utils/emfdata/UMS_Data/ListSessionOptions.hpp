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

// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * UMS_Data/ListSessionOptions.hpp
 * Copyright (C) Cátedra SAES-UMU 2010 <andres.senac@um.es>
 *
 * EMF4CPP is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EMF4CPP is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * \file ListSessionOptions.hpp
 * \brief The ListSessionOptions class
 * \author Generated file
 * \date 31/03/2011
 */

#ifndef UMS_DATA_LISTSESSIONOPTIONS_HPP
#define UMS_DATA_LISTSESSIONOPTIONS_HPP

#include <UMS_Data_forward.hpp>
#include <ecorecpp/mapping_forward.hpp>

#include <ecore_forward.hpp>
#include <ecore_forward.hpp>

#include <ecore/EObject.hpp>

/*PROTECTED REGION ID(ListSessionOptions_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace UMS_Data
{

    /**
     * \class ListSessionOptions
     * \brief Implementation of the ListSessionOptions class
     */
    class ListSessionOptions: public virtual ::ecore::EObject

    {
    public:
        /**
         * \brief The default constructor for ListSessionOptions
         */
        ListSessionOptions();
        /**
         * \brief The destructor for ListSessionOptions
         */
        virtual ~ListSessionOptions();

        /**
         * \brief Internal method
         */
        virtual void _initialize();

        // Operations


        // Attributes
        /**
         * \brief To get the status
         * \return The status attribute value
         **/
        ::UMS_Data::StatusType getStatus() const;
        /**
         * \brief To set the status
         * \param _status The status value
         **/
        void setStatus(::UMS_Data::StatusType _status);

        /**
         * \brief To get the sessionClosePolicy
         * \return The sessionClosePolicy attribute value
         **/
        ::UMS_Data::SessionCloseType getSessionClosePolicy() const;
        /**
         * \brief To set the sessionClosePolicy
         * \param _sessionClosePolicy The sessionClosePolicy value
         **/
        void setSessionClosePolicy(
                ::UMS_Data::SessionCloseType _sessionClosePolicy);

        /**
         * \brief To get the sessionInactivityDelay
         * \return The sessionInactivityDelay attribute value
         **/
        ::ecore::EInt getSessionInactivityDelay() const;
        /**
         * \brief To set the sessionInactivityDelay
         * \param _sessionInactivityDelay The sessionInactivityDelay value
         **/
        void setSessionInactivityDelay(::ecore::EInt _sessionInactivityDelay);

        /**
         * \brief To get the machineId
         * \return The machineId attribute value
         **/
        ::ecore::EString const& getMachineId() const;
        /**
         * \brief To set the machineId
         * \param _machineId The machineId value
         **/
        void setMachineId(::ecore::EString const& _machineId);

        /**
         * \brief To get the adminListOption
         * \return The adminListOption attribute value
         **/
        ::ecore::EBoolean isAdminListOption() const;
        /**
         * \brief To set the adminListOption
         * \param _adminListOption The adminListOption value
         **/
        void setAdminListOption(::ecore::EBoolean _adminListOption);

        /**
         * \brief To get the userId
         * \return The userId attribute value
         **/
        ::ecore::EString const& getUserId() const;
        /**
         * \brief To set the userId
         * \param _userId The userId value
         **/
        void setUserId(::ecore::EString const& _userId);

        /**
         * \brief To get the sessionId
         * \return The sessionId attribute value
         **/
        ::ecore::EString const& getSessionId() const;
        /**
         * \brief To set the sessionId
         * \param _sessionId The sessionId value
         **/
        void setSessionId(::ecore::EString const& _sessionId);

        /**
         * \brief To get the startDateOption
         * \return The startDateOption attribute value
         **/
        ::ecore::ELong getStartDateOption() const;
        /**
         * \brief To set the startDateOption
         * \param _startDateOption The startDateOption value
         **/
        void setStartDateOption(::ecore::ELong _startDateOption);

        /**
         * \brief To get the endDateOption
         * \return The endDateOption attribute value
         **/
        ::ecore::ELong getEndDateOption() const;
        /**
         * \brief To set the endDateOption
         * \param _endDateOption The endDateOption value
         **/
        void setEndDateOption(::ecore::ELong _endDateOption);

        // References


        /*PROTECTED REGION ID(ListSessionOptions) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl
        virtual ::ecore::EJavaObject eGet(::ecore::EInt _featureID,
                ::ecore::EBoolean _resolve);
        virtual void eSet(::ecore::EInt _featureID,
                ::ecore::EJavaObject const& _newValue);
        virtual ::ecore::EBoolean eIsSet(::ecore::EInt _featureID);
        virtual void eUnset(::ecore::EInt _featureID);
        virtual ::ecore::EClass_ptr _eClass();

        /*PROTECTED REGION ID(ListSessionOptionsImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        ::UMS_Data::StatusType m_status;

        ::UMS_Data::SessionCloseType m_sessionClosePolicy;

        ::ecore::EInt m_sessionInactivityDelay;

        ::ecore::EString m_machineId;

        ::ecore::EBoolean m_adminListOption;

        ::ecore::EString m_userId;

        ::ecore::EString m_sessionId;

        ::ecore::ELong m_startDateOption;

        ::ecore::ELong m_endDateOption;

        // References

    };

} // UMS_Data

#endif // UMS_DATA_LISTSESSIONOPTIONS_HPP
