#include "computearithmetic.hh"
#include "computepi.hh"
#include "printseries.hh"
#include "writeseries.hh"
#include <iostream>
#include <sstream>

int main(int argc, char *argv[]){

  if (argc!=4){
    std::cerr << "Usage : main P|A number separator"<< std::endl;
    return 1;
  }

  Series *s;
  std::string arg1(argv[1]);
  std::stringstream sstr;
  sstr << argv[2];
  std::string separator(argv[3]);
  if(!separator.compare(",") && !separator.compare("|") && !separator.compare(" ")){
     std::cerr << "Separator must be comma ',' space ' ' or pipe '|' " << std::endl;
     return 1;
  }

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
     
     PrintSeries P(1,N,*s);
     WriteSeries W(1,N,*s);
     W.setSeparator(separator);
     P.setSeparator(separator);
     
     P.dump();
     W.dump();
	 
return 0;

}
