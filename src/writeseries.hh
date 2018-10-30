#pragma once
#include "dumperseries.hh"

class WriteSeries : public DumperSeries{
    public:
        WriteSeries(unsigned int freq, unsigned int maxit, Series &series);
        void dump() override;
        
    private:
        unsigned int _freq;
        unsigned int _maxit;

};
