
#ifndef QUESITO_1_RB_H
#define QUESITO_1_RB_H

#include "NODO.h"
#include <string>

using namespace std ;

class RB
{
private:
    NODO* root ;
    NODO* nill = new NODO(0) ;


public :
    RB()
    {
        nill->setcolore(" BLACK ") ; nill->setleft(nill); nill->setright(nill);
        nill->setpadre(nill) ; root = nill ;
    }
    void setroot(NODO *r) { root = r ;}
    NODO* getroot() {return root ; }
    NODO* getnill() {return nill;}
    void preorder (NODO *x);
    void inorder( NODO *x);
    void left_rotate(NODO* x);
    void right_rotate(NODO* x);
    void inserimento(int key);
    void transplant_RB(NODO* u , NODO* v);
    void delete_fixup(NODO* x);
    void delete_RB(NODO* z);
    NODO* ricerca ( NODO * x ,int key);
    NODO* minimo(NODO *x);
    void UNIONE (RB* T , RB* X , NODO* A , NODO* B );
    void INTERSEZIONE (RB* T , RB* X , NODO* A , NODO* B );
    void DIFFERENZA (RB*D,RB* T, RB* X , NODO* A , NODO* B , NODO* k);
    void EliminaDuplicati(NODO* x);

};




#endif //QUESITO_1_RB_H
