#include <iostream>
#include <string>
#include "FILE.h"

using namespace std;

void INPUT::LetturaFile(GRAFO* G) {

    list<NODO *>::iterator it ;
    list<NODO *>::iterator it2;
    list<NODO *> *l = new list<NODO *>;
    list<NODO *> *a = new list<NODO *>;

    char c;
    int n , p ,j;
    int i = 0 ;
    NODO* temp ;
    NODO* tempU ;
    NODO* tempV ;
    NODO* u;
    NODO* v;
    INPUT f ;

    f.setNomeFile("Grapha-Nui.txt");

    x.open(f.getNomeFile(), ifstream::in);

    if (!x.is_open())
        cout << " ERRORE APERTURA FILE ";
    else {

        while (x >> n && c != '\n') {

            x.get(c);
            if (c == ' ')
                G->setV(n);
            else
                G->setE(n);
        }


        if (c == '\n')
        {
            do{

                if (i >0 ) {
                    it = G->getnodi()->begin();
                    while (it != G->getnodi()->end() && it.operator*()->getkey() != n) {

                        it++;
                    }


                    if (it != G->getnodi()->end()) {
                        x >> n;
                        tempU = it.operator*();
                        it = G->getnodi()->begin();
                        while (it != G->getnodi()->end() && it.operator*()->getkey() != n) {
                            it++;
                        }
                        if (it != G->getnodi()->end()) {
                            x >> p;
                            tempV = it.operator*();
                            tempU->add_adj(tempU->getadj(), p, tempV);

                        }
                        else
                        {
                            v = G->Addnode(l, n);
                            x >> p;
                            tempU->add_adj(tempU->getadj(),p, v);

                        }
                    } else {

                        u = G->Addnode(l, n);
                        x >> n;
                        it = G->getnodi()->begin();
                        while (it != G->getnodi()->end() && it.operator*()->getkey() != n) {

                            it++;
                        }

                        if (it != G->getnodi()->end()) {
                            x >> p;
                            temp = it.operator*();
                            u->add_adj(u->getadj(), p , temp);
                        }
                        else {
                            v = G->Addnode(l, n);
                            if (temp->getkey() == u->getkey()) {
                                x >> p;
                                temp->add_adj(temp->getadj(), p, v);
                            } else {
                                x >> p;
                                u->add_adj(u->getadj(), p, v);
                            }
                        }

                    }
                }
                else {

                    v = G->Addnode(l, n);
                    temp = v;

                    x >> n;


                    u = G->Addnode(l, n);
                    x >> p;

                    v->add_adj(a, p, u);

                    it = G->getnodi()->begin();

                    i++;
                }

            }while( x >> n );

        }
    }

    for ( it = G->getnodi()->begin() ; it != G->getnodi()->end() ; it++)
    {
        for (it2 = G->getnodi()->begin() ; it != G->getnodi()->end() ;++it2 )
        {
            if( (++it2) != G->getnodi()->end()) {
                --it2;
                if (it2.operator*()->getkey() > (++it2).operator*()->getkey()) {
                    --it2;
                    temp = it2.operator*();
                    it2.operator*() = (++it2).operator*();
                    --it2;
                    (++it2).operator*() = temp;
                    --it2;

                } else {
                    --it2;
                }
            }
            else{
                break;
            }

        }
    }

    x.close();

}


