
#ifndef QUESITO_2_GRAFO_H
#define QUESITO_2_GRAFO_H

#include <list>
#include <stack>
#include "NODO.h"

class GRAFO{

private:
    int V;
    int E;
    list<NODO*>* nodi;

public:
    GRAFO () ;
    void setV(int v ) {V = v;}
    int getV() {return V;}
    void setE(int e) {E = e ;}
    int getE() {return E ;}
    NODO* Addnode(list<NODO*>* l ,int n);
    list<NODO*>* getnodi() {return nodi;}
    void DFS_VISIT(NODO *u ,stack<NODO*> *S);
    stack<NODO*>* DFS(list<NODO*> *V ,stack<NODO*> *S );
    void inizialized_single_source(list<NODO*> *V , NODO* v);
    void Relax(NODO* v , NODO* u ,int x);
    void PercorsoMassimo(NODO* temp ,int scelta) ;

};

#endif //QUESITO_2_GRAFO_H
