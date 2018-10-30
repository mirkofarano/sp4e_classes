#pragma once
#include "series.hh"
#include <string>
#include <iostream>

class DumperSeries{
    public:
        DumperSeries(Series &series):_series(series){};
        virtual void dump() = 0;
        void setSeparator(std::string& s);


    protected:
        Series  & _series;
        std::string _s; // Separator
        std::string _filename;


};
