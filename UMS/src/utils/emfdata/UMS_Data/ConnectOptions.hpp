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
 * UMS_Data/ConnectOptions.hpp
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
 * \file ConnectOptions.hpp
 * \brief The ConnectOptions class
 * \author Generated file
 * \date 31/03/2011
 */

#ifndef UMS_DATA_CONNECTOPTIONS_HPP
#define UMS_DATA_CONNECTOPTIONS_HPP

#include <UMS_Data_forward.hpp>
#include <ecorecpp/mapping_forward.hpp>

#include <ecore_forward.hpp>

#include <ecore/EObject.hpp>

/*PROTECTED REGION ID(ConnectOptions_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace UMS_Data
{

    /**
     * \class ConnectOptions
     * \brief Implementation of the ConnectOptions class
     */
    class ConnectOptions: public virtual ::ecore::EObject

    {
    public:
        /**
         * \brief The default constructor for ConnectOptions
         */
        ConnectOptions();
        /**
         * \brief The destructor for ConnectOptions
         */
        virtual ~ConnectOptions();

        /**
         * \brief Internal method
         */
        virtual void _initialize();

        // Operations


        // Attributes
        /**
         * \brief To get the closePolicy
         * \return The closePolicy attribute value
         **/
        ::UMS_Data::SessionCloseType getClosePolicy() const;
        /**
         * \brief To set the closePolicy
         * \param _closePolicy The closePolicy value
         **/
        void setClosePolicy(::UMS_Data::SessionCloseType _closePolicy);

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
         * \brief To get the substituteUserId
         * \return The substituteUserId attribute value
         **/
        ::ecore::EString const& getSubstituteUserId() const;
        /**
         * \brief To set the substituteUserId
         * \param _substituteUserId The substituteUserId value
         **/
        void setSubstituteUserId(::ecore::EString const& _substituteUserId);

        // References


        /*PROTECTED REGION ID(ConnectOptions) START*/
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

        /*PROTECTED REGION ID(ConnectOptionsImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        ::UMS_Data::SessionCloseType m_closePolicy;

        ::ecore::EInt m_sessionInactivityDelay;

        ::ecore::EString m_substituteUserId;

        // References

    };

} // UMS_Data

#endif // UMS_DATA_CONNECTOPTIONS_HPP
