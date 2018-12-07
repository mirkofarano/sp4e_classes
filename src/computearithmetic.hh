#pragma one
#include "series.hh"

class ComputeArithmetic : public Series{
   public:
      ComputeArithmetic();
      virtual ~ComputeArithmetic(){};
      double compute(unsigned int N) override;
};
