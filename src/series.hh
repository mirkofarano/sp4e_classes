#pragma once
#include <cmath>

class Series {
public:
  Series(){};
  virtual ~Series(){};
  virtual double compute(unsigned int N) = 0;
  virtual double getAnalyticPrediction() { return nan("1"); }
  void setCurrentIndex(unsigned int i) { _current_index = i; }
  void setCurrentValue(double v) { _current_value = v; }

protected:
  unsigned int _current_index = 1;
  double _current_value = 0;
};
