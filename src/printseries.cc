#include "printseries.hh"
#include <iostream>

PrintSeries::PrintSeries(unsigned int freq, unsigned int maxit, Series &series)
    : DumperSeries(series) {
  _freq = freq;
  _maxit = maxit;
}

void PrintSeries::dump(std::ostream &so) {
  double summ = 0;
  double sol = 0;
  double err = 0;
  sol = _series.getAnalyticPrediction();
  so << "Analytical Prediction is " << sol << std::endl;
  so << "iter "
     << " series "
     << " error " << std::endl;
  unsigned int N = _maxit / _freq;
  for (unsigned int i = 0; i < N; i++) {
    summ = _series.compute(i * _freq);
    err = std::abs(summ - sol);
    so << std::setprecision(_precision) << i << _s << summ << _s << err
       << std::endl;
  }
}
