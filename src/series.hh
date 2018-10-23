#pragma once

class Series{
   public:
      Series(){};
      virtual ~Series(){};      
      virtual double compute(unsigned int N) = 0; 

};
