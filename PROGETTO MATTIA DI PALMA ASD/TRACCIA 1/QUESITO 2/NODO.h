#ifndef QUESITO_2_NODO_H
#define QUESITO_2_NODO_H

#include <string>
#include <list>
#include <vector>

using namespace std;

class NODO{

private:
    int key ;
    string colore ;
    NODO* padre ;
    int D;
    list<NODO*>* adj ;
    vector<int> peso ;

public:
    NODO(int k );
    int getkey() {return key; }
    void Addnode(int x , list<NODO*>* l);
    NODO* getnode() {return this; }
    void setpadre(NODO* p) { padre = p ;}
    NODO* getpadre() {return padre ;}
    void setcolore (string s ) { colore = s ;}
    string getcolore() {return colore ;}
    void add_adj(list<NODO*>* l , int x , NODO* v);
    vector<int>* getpeso();
    list<NODO*>* getadj() {return adj ; }
    void setD(int k ) { D = k ; }
    int getD() {return D ; }

};

#endif //QUESITO_2_NODO_H
