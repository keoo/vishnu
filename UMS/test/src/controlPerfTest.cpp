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
#include <cmath>
#include <fstream>

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


/*To print the execution of the program*/
void print_vishnu_time(double t, std::string prog)
{
  std::cout << ":-----------------------------------------" << std::endl;
  std::cout << "Execution of " << prog << std::endl;
  std::cout << ": vishnu_time = " << t << " s" << std::endl;
  std::cout << ":-----------------------------------------" << std::endl;
}

int main(int argc, char* argv[]) {

   if(argc < 7) {
     std::cout << "usage : " << argv[0] << "<vishnu_connet pathToBin> <vishnu_progname> <ssh_host_name> <ssh_progname_name> <nbIter> <outputFile>" << std::endl;
     return 1;
   }
   char* vishnu_connect_bin_path = argv[1];
   char* vishnu_progname = argv[2];
   char* host_name = argv[3];
   char* ssh_progname = argv[4];
   int nbIter = atoi(argv[5]);
   char* outputFile = argv[6];

   double t0;
   double t1;
   std::ofstream of(outputFile);
   std::ostringstream os1;
   os1 << vishnu_connect_bin_path << " root -w vishnu_user;";
   os1 << vishnu_progname;
  
   for(int i=0; i < nbIter; i++) { 
     t0 = gettime();  
     //To execute vishnu programm 
     system(os1.str().c_str());
     t1 = gettime();
     //print_vishnu_time(t1-t0, os1.str());

     double vishnu_wall_time = t1-t0; 
     std::ostringstream os2;
     os2 << vishnu_connect_bin_path << " root -w vishnu_user;"; 
     t0 = gettime();
     //To get vishnu_connect time
     system(os2.str().c_str());
     t1 = gettime(); 
     print_vishnu_time(t1-t0, "vishnu_connect");
     double vishnu_time = (vishnu_wall_time-(t1-t0));
     print_vishnu_time(vishnu_wall_time-(t1-t0), vishnu_progname);

     std::ostringstream os_ssh;
     os_ssh << "ssh " << host_name << " ";
     os_ssh << ssh_progname;

     t0 = gettime();
     //Test ssh 
     system(os_ssh.str().c_str());
     t1 = gettime();
     print_ssh_time(t1-t0, os_ssh.str());
     double ssh_time = t1-t0;

     of << (i+1) << "\t" << ssh_time << "\t" << vishnu_time;
     double diff = fabs(ssh_time-vishnu_time);
     of << "\t" << diff << std::endl;

     of.close();
   }
 return 0;
}
