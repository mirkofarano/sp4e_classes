#pragma once
#include "dumperseries.hh"
#include <fstream>

class WriteSeries : public DumperSeries{
    public:
        WriteSeries(unsigned int freq, unsigned int maxit, Series &series);
        void dump(std::ostream& so) override;

    private:
        unsigned int _freq;
        unsigned int _maxit;

};
