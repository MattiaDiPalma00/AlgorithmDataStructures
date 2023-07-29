

#ifndef QUESITO_1_FUNZIONI_H
#define QUESITO_1_FUNZIONI_H

#include <fstream>
#include <string>
#include "RB.h"

class INPUT
{

private:
    fstream x ;
    string NomeFile;

public:
    void setNomeFile(string s) {NomeFile = s;}
    string getNomeFile() {return NomeFile;}
    vector<RB*> LetturaFile();


};
#endif //QUESITO_1_FUNZIONI_H
