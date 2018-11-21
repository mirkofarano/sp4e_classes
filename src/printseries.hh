#pragma once
#include "dumperseries.hh"

class PrintSeries : public DumperSeries{
    public:
        PrintSeries(unsigned int freq, unsigned int maxit, Series &series);
        void dump(std::ostream& so = std::cout) override;

    private:
        unsigned int _freq;
        unsigned int _maxit;

};
