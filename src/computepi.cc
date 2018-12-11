#include "computepi.hh"
#include <cmath>

ComputePi::ComputePi() : Series() {}

double ComputePi::compute(unsigned int N) {
  double summ = _current_value;
  for (unsigned int i = _current_index; i < N + 1; i++) {
    summ += 1 / double(i * i);
  }

  setCurrentValue(summ);
  setCurrentIndex(N + 1);
  summ = sqrt(6 * summ);
  return summ;
}

double ComputePi::getAnalyticPrediction() { return M_PI; }
