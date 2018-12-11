#include "writeseries.hh"

WriteSeries::WriteSeries(unsigned int freq, unsigned int maxit, Series &series)
    : DumperSeries(series) {
  _freq = freq;
  _maxit = maxit;
}

void WriteSeries::dump(std::ostream &so) {
  double summ = 0;
  double sol = 0;
  double err = 0;
  sol = _series.getAnalyticPrediction();
  std::ofstream myfile; // FIXME cast ostream in ofstream
  myfile.open(_filename);
  myfile << "Analytical Prediction is " << sol << "\n";
  myfile << "iter "
         << " series "
         << " error \n";
  unsigned int N = _maxit / _freq;
  for (unsigned int i = 0; i < N; i++) {
    summ = _series.compute(i * _freq);
    err = std::abs(summ - sol);
    myfile << std::setprecision(_precision) << i << _s << summ << _s << err
           << "\n";
  }
}
