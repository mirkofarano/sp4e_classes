#pragma once
#include "series.hh"
#include <iomanip>
#include <iostream>
#include <string>

class DumperSeries {
public:
  DumperSeries(Series &series) : _series(series){};
  virtual void dump(std::ostream &so) = 0;
  virtual void setPrecision(unsigned int precision) { _precision = precision; };
  void setSeparator(std::string &s);

protected:
  Series &_series;
  std::string _s; // Separator
  std::string _filename;
  unsigned int _precision;
};

inline std::ostream &operator<<(std::ostream &stream, DumperSeries &_this) {
  _this.dump(stream);
  return stream;
}
