#include "dumperseries.hh"

void DumperSeries::setSeparator(std::string& s)
{

    std::string filename = "series";
    if(s.compare(",")==0){
        std::string extension = ".cvs";
        filename.append(extension);
    }else if(s.compare("|")==0){
        std::string extension = ".psv";
        filename.append(extension);
    }else{
        std::string extension = ".txt";
        filename.append(extension);
    };

     _s =' ' + s + ' ';
    _filename = filename;
    
}
