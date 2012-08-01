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
 * FMS_Data/LsTransferOptions.hpp
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
 * \file LsTransferOptions.hpp
 * \brief The LsTransferOptions class
 * \author Generated file
 * \date 31/03/2011
 */

#ifndef FMS_DATA_LSTRANSFEROPTIONS_HPP
#define FMS_DATA_LSTRANSFEROPTIONS_HPP

#include <FMS_Data_forward.hpp>
#include <ecorecpp/mapping_forward.hpp>

#include <ecore_forward.hpp>

#include <ecore/EObject.hpp>

/*PROTECTED REGION ID(LsTransferOptions_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace FMS_Data
{

    /**
     * \class LsTransferOptions
     * \brief Implementation of the LsTransferOptions class
     */
    class LsTransferOptions: public virtual ::ecore::EObject

    {
    public:
        /**
         * \brief The default constructor for LsTransferOptions
         */
        LsTransferOptions();
        /**
         * \brief The destructor for LsTransferOptions
         */
        virtual ~LsTransferOptions();

        /**
         * \brief Internal method
         */
        virtual void _initialize();

        // Operations


        // Attributes
        /**
         * \brief To get the transferId
         * \return The transferId attribute value
         **/
        ::ecore::EString const& getTransferId() const;
        /**
         * \brief To set the transferId
         * \param _transferId The transferId value
         **/
        void setTransferId(::ecore::EString const& _transferId);

        /**
         * \brief To get the fromMachineId
         * \return The fromMachineId attribute value
         **/
        ::ecore::EString const& getFromMachineId() const;
        /**
         * \brief To set the fromMachineId
         * \param _fromMachineId The fromMachineId value
         **/
        void setFromMachineId(::ecore::EString const& _fromMachineId);

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
         * \brief To get the status
         * \return The status attribute value
         **/
        ::FMS_Data::Status getStatus() const;
        /**
         * \brief To set the status
         * \param _status The status value
         **/
        void setStatus(::FMS_Data::Status _status);

        // References


        /*PROTECTED REGION ID(LsTransferOptions) START*/
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

        /*PROTECTED REGION ID(LsTransferOptionsImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        ::ecore::EString m_transferId;

        ::ecore::EString m_fromMachineId;

        ::ecore::EString m_userId;

        ::FMS_Data::Status m_status;

        // References

    };

} // FMS_Data

#endif // FMS_DATA_LSTRANSFEROPTIONS_HPP
