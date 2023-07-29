
#ifndef QUESITO_1_NODO_H
#define QUESITO_1_NODO_H

#include <string>
#include "RB.h"

using namespace  std ;


class NODO
{

private :
    int key ;
    string COLORE ;
    NODO *padre;
    NODO *left;
    NODO *right;


public :
    NODO(int k) {
        padre = nullptr;
        left = nullptr;
        right = nullptr;
        COLORE = "  ";
        key = k;
    }

    int getkey() {return key ; }
    void setcolore(string col) { COLORE = col ;}
    string getcolore() { return COLORE  ;}
    void setpadre(NODO *p) {padre = p ;}
    NODO *getpadre() {return padre ;}
    void setleft(NODO *l) {left = l ;}
    NODO *getleft() {return left;}
    void setright(NODO *r) {right = r ;}
    NODO *getright() {return right ;}



};

#endif //QUESITO_1_NODO_H
