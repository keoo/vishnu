// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * FMS_Data/DirEntryList.cpp
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

#include "DirEntryList.hpp"
#include <FMS_Data/DirEntry.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "FMS_Data/FMS_DataPackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::FMS_Data;

// Default constructor
DirEntryList::DirEntryList()
{

    m_dirEntries.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::FMS_Data::DirEntry, -1, true, false >(this, NULL));

    /*PROTECTED REGION ID(DirEntryListImpl__DirEntryListImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

DirEntryList::~DirEntryList()
{
}

/*PROTECTED REGION ID(DirEntryList.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::ecorecpp::mapping::EList< ::FMS_Data::DirEntry >& DirEntryList::getDirEntries()
{
    return *m_dirEntries;
}

