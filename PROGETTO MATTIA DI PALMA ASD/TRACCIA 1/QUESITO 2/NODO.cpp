#include <list>
#include "NODO.h"


NODO::NODO(int k)
{
    key = k ;
    colore = " WHITE ";
    padre = nullptr;
    adj = nullptr;

}
vector<int>* NODO::getpeso()
{
    vector<int>* v = &peso;

    return v ;
}

void NODO::add_adj(list<NODO*>* l , int x , NODO* v )
{
    if (l != nullptr) {
        l->push_back(v);
        adj = l;
        peso.push_back(x) ;
    }
    else {
        list<NODO *> *h = new list<NODO *>;
        h->push_back(v);
        adj = h;
        peso.push_back(x) ;
    }
}


