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

#include <sys/time.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>

/*To get the time in second*/
inline double gettime()
{
   struct timeval tmp ;
   gettimeofday (&tmp, 0) ;

   // real time 
   return (double) tmp.tv_sec + ((double) tmp.tv_usec) * 1e-6;
}

/*To print the execution of the program*/
void print_ssh_time(double t, std::string prog)
{
  std::cout << ":-----------------------------------------" << std::endl;
  std::cout << "Execution of " << prog << std::endl;
  std::cout << ": ssh_time = " << t << " s" << std::endl;
  std::cout << ":-----------------------------------------" << std::endl;
}

int main(int argc, char* argv[]) {

   if(argc < 2) {
     std::cout << "usage : " << argv[0] << "<host_name> <ssh_progname>" << std::endl;
     return 1;
   }
   char* host_name = argv[1];
   char* ssh_progname = argv[2];
   double t0;
   double t1;
   std::ostringstream os;
   os << "ssh " << host_name << " "; 
   os << ssh_progname;

   t0 = gettime();
     //Test ssh 
     system(os.str().c_str());
   t1 = gettime(); 
    print_ssh_time(t1-t0, os.str());

 return 0;
}
