#pragma once
#include <cmath>

class Series{
   public:
      Series(){};
      virtual ~Series(){};      
      virtual double compute(unsigned int N) = 0; 
      virtual double getAnalyticPrediction(){return nan("1");};

};
