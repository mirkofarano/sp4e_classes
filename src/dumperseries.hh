#pragma once
#include "series.hh"

class DumperSeries{
    public:
        DumperSeries(Series &series):_series(series){};
        virtual void dump() = 0;
        
    protected:
        Series  & _series;
    
};
