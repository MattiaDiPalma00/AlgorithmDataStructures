
#ifndef QUESITO_2_FILE_H
#define QUESITO_2_FILE_H

#include <fstream>
#include <string>
#include "GRAFO.h"
#include "NODO.h"

class INPUT
{

private:

    ifstream x ;
    string NomeFile;

public:
    void setNomeFile(string n) { NomeFile = n ;}
    string getNomeFile() { return NomeFile ;}
    void LetturaFile(GRAFO* G) ;

};

void ordinamento(list<NODO*>* s , NODO* t);

#endif //QUESITO_2_FILE_H
