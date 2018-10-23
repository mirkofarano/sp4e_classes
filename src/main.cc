#include "computearithmetic.hh"
#include "computepi.hh"
#include <iostream>
#include <sstream>

int main(int argc, char *argv[]){

  if (argc!=3){
    std::cerr << "Usage : main P|A number "<< std::endl;
    return 1;
  }

  Series *s;
  std::string arg1(argv[1]);
	std::stringstream sstr;
  sstr << argv[2];

  unsigned int N;
	sstr >> N;

	if(arg1.compare("P") == 0){
	  s = new ComputePi();
	  std::cout << "Pi" << std::endl;
	 }
	 else if (arg1.compare("A") == 0){
	  s = new ComputeArithmetic();
	  std::cout << "Arithmetic" << std::endl;
	 }
	 else{
		 std::cerr << "First argument should be P(compute pi) or A(compute arithmetic) " << std::endl;
     return 1;
   }		 

	 double m = (*s).compute(N);

	 std::cout << "sum is : " << m << std::endl;
	 
return 0;

}
