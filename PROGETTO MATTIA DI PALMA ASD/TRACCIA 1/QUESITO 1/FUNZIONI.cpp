#include <iostream>
#include <vector>
#include "FUNZIONI.h"


using namespace std;

vector<RB*> INPUT::LetturaFile()
{

    INPUT f ;
    char c = ' ';
    int n ;
    int i = 1;
    vector<vector<int>*>:: iterator it;
    vector<int> :: iterator j;
    vector<vector<int>*> z ;
    f.setNomeFile("insieme.txt");
    vector<RB*> v ;




    x.open(f.getNomeFile(), fstream::in ) ;

    if (!x.is_open())
        cout << " ERRORE APERTURA FILE ";

    else {

        while( !x.eof() || x.peek() != EOF) {

            RB* P = new RB ;
            vector<int>* l = new vector<int>;
            do {
                x >> n;
                P->inserimento(n);
                l->push_back(n);
                x.get(c);
            } while (x.peek()!= '\n' && x.peek() != EOF) ;

            v.push_back(P);
            z.push_back(l);
            x.get(c);

            if (c == '\n' && x.peek() != EOF) {
                RB *P = new RB;
                vector<int>* l = new vector<int>;


                do {
                    x >> n;
                    P->inserimento(n);
                    l->push_back(n);
                    x.get(c);
                }while(x.peek() != '\n' && x.peek() != EOF);
                x.get(c);
                v.push_back(P);
                z.push_back(l);

            }
        }
        for( it = z.begin() ; it != z.end() ; it++)
        {
            cout << " \t\t\t\tINSIEME : "<< i << endl;
            for (j = it.operator*()->begin()  ; j != it.operator*()->end() ; j++) {
                cout << j.operator*() << " ";

            }
            cout<< "\n\n";
            i++;
        }
        x.close();
        return v;
    }

}