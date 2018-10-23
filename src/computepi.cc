#include "computepi.hh"
#include <cmath>

ComputePi::ComputePi():Series(){}

double ComputePi::compute(unsigned int N){
  double summ =0.0;
  for(unsigned int i=1; i<N; i++){
    summ += 1/double(i*i);
  }
  summ = sqrt(6*summ);
  return summ;
}
