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
  sstr << argv[1] << " " << argv[2] << " " << argv[3] << " "  << argv[4] << " "  << argv[5];
  sstr >> PA;
  sstr >> N;
  sstr >> separator;
  sstr >> SF;
  sstr >> precision;

  if(!separator.compare(",") && !separator.compare("|") && !separator.compare(" ")){
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
