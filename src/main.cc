#include "computearithmetic.hh"
#include "computepi.hh"
#include "printseries.hh"
#include "writeseries.hh"
#include <iostream>
#include <sstream>

int main(int argc, char *argv[]){

  if (argc!=5){
    std::cerr << "Usage : main P(pi)|A(arithmetic) number separator S(screen)|F(file)"<< std::endl;
    return 1;
  }

  std::stringstream sstr;
  unsigned int N;
  std::string PA, separator, SF;
  sstr << argv[1] << " " << argv[2] << " " << argv[3] << " "  << argv[4];
  sstr >> PA;
  sstr >> N;
  sstr >> separator;
  sstr >> SF;

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

     DumperSeries *Ds;

     if(SF.compare("S") == 0){
         Ds = new PrintSeries(1,N,*s);
         std::cout << "Prrint on screen" << std::endl;
	 }
	 else if (SF.compare("F") == 0){
         Ds = new WriteSeries(1,N,*s);
         std::cout << "Write on flie" << std::endl;
	 }
	 else{
		 std::cerr << "Last argument should be S (Prrint on screen) or F (Write on flie) " << std::endl;
     return 1;
     }

     Ds->setSeparator(separator);
     Ds->dump();


return 0;

}
