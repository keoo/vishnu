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
 * \file CLICmd.hpp
 * \brief This file defines the CLICmd class, that parses the CLI and fill options
 * \author Kevin Coulomb (kevin.coulomb@sysfera.com)
 */
#ifndef __CLICMD__
#define __CLICMD__

#include "Options.hpp"
#include "cliError.hpp"

using namespace std;

/**
 * \brief This class represents the class to parse the cli
 * \class CLICmd
 */
class CLICmd{
private :
  /**
   * \brief The argc value
   */
  int    		     margc;
  /**
   * \brief The argv value
   */
  char** 		     margv;
  /**
   * \brief The option of the call
   */
  boost::shared_ptr<Options> mop;
protected:
public:
  /**
   * \brief To get all the parameters for the C++ API call
   * \param s: The environment
   * \return An error code depending on the success of the call
   */
  int parse(const func1 & s);
  /**
   * \brief Constructor
   * \param argc: argc from C program
   * \param argv: argv from C program
   * \param op: Option to fill (OUT)
   */
  CLICmd(int argc, char** argv, boost::shared_ptr<Options> op);
  /**
   * \brief Default destructor
   * \fn ~CLICmd()
   */
  ~CLICmd();
};
#endif
