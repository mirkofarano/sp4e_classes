#pragma once
#include "series.hh"

class ComputePi : public Series{
  public:
    ComputePi();
    virtual ~ComputePi(){};
    double compute(unsigned int N) override;
    double getAnalyticPrediction() override;
};
