#include <iostream>
#include <cmath>
#include <list>
#include <stack>
#include "GRAFO.h"


using namespace std;

GRAFO::GRAFO()
{
    nodi = nullptr;
    V = 0 ;
    E = 0 ;
}


NODO* GRAFO::Addnode( list<NODO*>* l , int n )
{
    NODO* v = new NODO(n);
    l->push_back(v);
    nodi = l ;

    return v;

}



void GRAFO::DFS_VISIT(NODO *u ,stack<NODO*> *S)
{
    list<NODO*>::iterator it;
    NODO* l;
    u->setcolore(" GRAY ");


    if(u->getadj() != nullptr) {
        for (it = u->getadj()->begin(); it != u->getadj()->end(); ++it) {

            if (it.operator*()->getcolore() == " WHITE ") {

                l = it.operator*()->getnode();
                DFS_VISIT(l, S);
            }

           if (it.operator*()->getcolore() != " BLACK ") {
               it.operator*()->setcolore(" BLACK ");
               S->push(it.operator*()->getnode());
           }
        }

    }

}



stack<NODO*> * GRAFO::DFS(list<NODO*> *V ,stack<NODO*> *S )
{
    list<NODO*>::iterator it;
    NODO* l ;

    for(it = V->begin() ; it != V->end() ; it++)
    {
        if(it.operator*()->getcolore() == " WHITE ") {

            l = it.operator*()->getnode();
            DFS_VISIT(l, S);
            l->setcolore( " BLACK ");
            S->push(l);
        }
    }
    return S;

}



void GRAFO::inizialized_single_source(list<NODO*> *V , NODO* v)
{
    list<NODO*>::iterator it ;
    int inf = pow(2 , 64 -1 );


    for(it = V->begin() ; it != V->end() ; ++it) {

        if (it.operator*()->getnode() == v) {

            it.operator*()->setD(0);
            it.operator*()->setpadre(nullptr);
        }
        else {

            it.operator*()->setD(inf);
            it.operator*()->setpadre(nullptr);
        }
    }
}

void GRAFO::Relax(NODO* v , NODO* u , int x )
{
    if( v->getD() < u->getD() + x)
    {
        v->setD(u->getD() + x);
        v->setpadre(u);
    }

}

void GRAFO::PercorsoMassimo( NODO* temp , int scelta )
{

    list<NODO*>::iterator it , iadj;
    vector<int>:: iterator  i ;
    stack<NODO*> *k = new stack<NODO*>;
    int cont = 0;
    this->inizialized_single_source(this->getnodi(), temp);
    k = this->DFS(this->getnodi(), k);

    while( k->top()->getkey() != scelta) {
        k->pop();
    }

    while (!k->empty()) {
        i = k->top()->getpeso()->begin();

            if (k->top()->getadj() != nullptr) {
                for (iadj = k->top()->getadj()->begin(); iadj != k->top()->getadj()->end(); ++iadj) {
                    NODO *P = iadj.operator*();
                    this->Relax(P, k->top(), i.operator*());
                    ++i;
                }
            }
            k->pop();
        }
}


