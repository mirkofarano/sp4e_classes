#include "computearithmetic.hh"

ComputeArithmetic::ComputeArithmetic() : Series() {}

double ComputeArithmetic::compute(unsigned int N) {

  double summ = _current_value;

  for (unsigned int i = _current_index; i < N + 1; i++) {
    summ += i;
  }

  setCurrentValue(summ);
  setCurrentIndex(N + 1);
  return summ;
}
