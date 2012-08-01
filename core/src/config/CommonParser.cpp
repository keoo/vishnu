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


#include "CommonParser.hpp"

#ifdef DEBUG
std::ostream debug(std::cerr.rdbuf());
#else
std::ostream debug(0);
#endif

bool StartsWith::operator() (const std::string& s2) const
{
    return (0 == s2.compare(0, s1.size(), s1)) ? true : false;
}


Splitter::Splitter()
    : delim_('='), hasNext_(false),
      previous_(0), current_(0)
{
}


Splitter::Splitter(const char c)
    : delim_(c), hasNext_(false),
      previous_(0), current_(0)
{
}


Splitter::Splitter(const std::string& str, const char c)
    : delim_(c), previous_(0), current_(0), str_(str)
{
    hasNext_ = (str_.empty() ? false : true);
}


void Splitter::reset(const std::string& str)
{
    reset(str, delim_);
}


void Splitter::reset(const std::string& str, const char c)
{
    if (str != str_) {
    	str_ = str;
    }

    hasNext_ = (str_.empty() ? false : true);
    delim_ = c;
    previous_ = 0;
    current_ = 0;
}


std::string& Splitter::operator() ()
{
    if (!hasNext_) {
	token_.clear();
	return token_;
    }

    std::string::size_type current_ = str_.find(delim_, previous_);

    std::string sub = str_.substr(previous_, current_);
    token_.swap(sub);
    previous_ = (std::string::npos == current_) ?
	(str_.length() + 1) : (current_ + 1);

    // can't generate tokens anymore :'(
    if (str_.length() < previous_) {
	hasNext_ = false;
    }

    return token_;
}
