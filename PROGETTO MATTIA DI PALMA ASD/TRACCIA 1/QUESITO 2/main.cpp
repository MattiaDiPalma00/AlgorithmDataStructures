#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <stack>
#include "GRAFO.h"
#include "FILE.h"


using namespace std ;

int main() {


    list<NODO*> L,p,h;
    list<NODO*>::iterator it , iadj;
    vector<int>:: iterator  i ;
    stack<NODO*> *k = new stack<NODO*>;
    int inf = pow(2 , 64 -1 );
    int cont = 0;
    int j = 0 ;
    int scelta ;
    char c;
    INPUT F ;

    GRAFO G;


    F.LetturaFile(&G) ;
    cout<<"\t\t\tDI PALMA MATTIA  0124002448  TRACCIA 1."<<endl;
    cout<<"\nQUESITO 2 : "<<endl;
    cout<<"\nGRAPHA-NUI CON " << G.getV() <<" ISOLE E "<<G.getE()<<" PONTI CREATO DAL FILE 'GRAPHA-NUI.TXT'\n";
    cout<<"SCEGLIERE UN ISOLA DA 0 A " <<G.getV() -1<<" DA CUI PARTIRE PER CALCOLARE IL PERCORSO CON LA QUALITA' MASSIMA.\n\n";
    cout<<"DIGITARE SCELTA :";
    cin>>scelta;
    cout<<"PARTENDO DALL'ISOLA "<<scelta<<" CALCOLIAMO IL PERCORSO.\n\n" ;

    if (scelta < G.getV()) {

        it = G.getnodi()->begin();
        while (j < scelta) {
            ++it;
            j++;
        }

        NODO *temp = it.operator*();
        G.PercorsoMassimo(temp , scelta);

        for(it = G.getnodi()->begin() ; it != G.getnodi()->end() ; ++it)
        {
            cout << temp->getkey() << " -> " <<it.operator*()->getkey() << "  ";
            if (it.operator*()->getD() == inf)
                cout << "-INF \n";
            else
                cout << it.operator*()->getD() << "\n";
        }

    }
    else {
        cout << "\nPERCORSO INESISTENTE." ;
        cout << "\nSCELTA NON VALIDA.";
    }
    cout<<"\nPREMERE '0' PER USCIRE QUALSIASI ALTRO TASTO PER CONTINUARE : ";
    cin>>c ;

    if(c == '0')
        cout<<"\nARRIVEDERCI.";
    else
        return main();

    return 0;

}
