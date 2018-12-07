#include "computearithmetic.hh"
#include "computepi.hh"
#include "printseries.hh"
#include "writeseries.hh"
#include <iostream>
#include <sstream>

int main(int argc, char *argv[]){

  if (argc!=6){
    std::cerr << "Usage : main P(pi)|A(arithmetic) number separator S(screen)|F(file) precision"<< std::endl;
    return 1;
  }

  std::stringstream sstr;
  unsigned int N;
  unsigned int precision;
  std::string PA, separator, SF;
  sstr << argv[1];
  sstr >> PA;
  sstr.clear();
  sstr << argv[2];
  sstr >> N;
  sstr.clear();
  sstr << argv[3];
  sstr >> separator;
  sstr.clear();
  sstr << argv[4];
  sstr >> SF;
  sstr.clear();
  sstr << argv[5];
  sstr >> precision;

  if(separator.compare(",") && separator.compare("|") && separator.compare("")){
     std::cerr << "Separator must be comma ',' space ' ' or pipe '|' " << std::endl;
     return 1;
  }

    Series *s;

	if(PA.compare("P") == 0){
	  s = new ComputePi();
	  std::cout << "Pi" << std::endl;
	 }
	 else if (PA.compare("A") == 0){
	  s = new ComputeArithmetic();
	  std::cout << "Arithmetic" << std::endl;
	 }
	 else{
		 std::cerr << "First argument should be P(compute pi) or A(compute arithmetic) " << std::endl;
     return 1;
     }


     if(SF.compare("S") == 0){
         PrintSeries PS(1,N,*s);
         PS.setSeparator(separator);
         PS.setPrecision(precision);
         std::cout << "Prrint on screen" << std::endl;
         std::cout << PS;
	 }
	 else if (SF.compare("F") == 0){
         std::ofstream myfile;
         WriteSeries WS(1,N,*s);
         WS.setSeparator(separator);
         WS.setPrecision(precision);
         std::cout << "Write on flie" << std::endl;
         myfile << WS;
	 }
	 else{
		 std::cerr << "Last argument should be S (Prrint on screen) or F (Write on flie) " << std::endl;
     return 1;
     }

return 0;

}
