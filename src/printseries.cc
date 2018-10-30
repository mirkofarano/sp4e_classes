#include "printseries.hh"
#include <iostream>

PrintSeries::PrintSeries(unsigned int freq, unsigned int maxit, Series &series):DumperSeries(series){
    _freq = freq;
    _maxit = maxit;
}


void PrintSeries::dump(){
    double summ=0;
    double sol=0;
    double err=0;
    sol = _series.getAnalyticPrediction();
    std::cout << "Analytical Prediction is " << sol << std::endl;
    std::cout << "iter " << " series " << " error " << std::endl;
    unsigned int N = _maxit/_freq;
    for (unsigned int i =0; i<N; i++){
        summ = _series.compute(i*_freq);
        err = std::abs(summ - sol);
        std::cout << i << _s << summ << _s << err << std::endl;
    }
}
