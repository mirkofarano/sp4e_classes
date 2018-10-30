#include "writeseries.hh"
#include <fstream>

WriteSeries::WriteSeries(unsigned int freq, unsigned int maxit, Series &series):DumperSeries(series){
    _freq = freq;
    _maxit = maxit;
}


void WriteSeries::dump(){
    double summ=0;
    double sol=0;
    double err=0;
    sol = _series.getAnalyticPrediction();
    std::ofstream myfile;
    myfile.open ("series.txt");
    myfile << "Analytical Prediction is " << sol << "\n";
    myfile << "iter " << " series " << " error \n";
    unsigned int N = _maxit/_freq;
    for (unsigned int i =0; i<N; i++){
        summ = _series.compute(i*_freq);
        err = abs(summ - sol);
        myfile << i << " " << sol << " " << err << "\n";
    }
}
