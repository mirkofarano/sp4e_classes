#include "computearithmetic.hh"

ComputeArithmetic::ComputeArithmetic():Series(){
}

double ComputeArithmetic::compute(unsigned int N){

 double summ = 0.0;

 for(unsigned int i =1; i< N+1; i++){
    summ +=i;
 }
 return summ;

}


