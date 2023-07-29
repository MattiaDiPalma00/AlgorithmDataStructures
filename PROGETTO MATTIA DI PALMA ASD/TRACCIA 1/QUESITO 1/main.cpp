#include <iostream>
#include <vector>
#include "RB.h"
#include "FUNZIONI.h"

using namespace std;


int main()
{

    vector<RB*> v;
    vector<RB*>:: iterator  it ;
    int i = 0;
    int j;
    RB U ;
    RB* A, *B;
    RB I;
    RB D;
    NODO* k;
    char c;
    int scelta1;
    int scelta2;
    INPUT F;

    cout<<"\t\t\tDI PALMA MATTIA  0124002448  TRACCIA 1."<<endl;
    cout<<"\nQUESITO 1 : "<<endl;



    cout << "\nLEGGIAMO GLI INTERI DAL FILE.\n";

    v = F.LetturaFile();

    for( it = v.begin() ; it != v.end() ; it++)
    {
        it.operator*()->EliminaDuplicati(it.operator*()->getroot());
        i++;
    }
    if( i == 1 ){
        cout<<"\nOPERAZIONI SU UN SOLO INSIEME NON SUPPORTATE \n";
        return -1;
    }

    cout << "\n\nSCEGLIERE SU QUALI INSIEMI ESEGUIRE LE OPERAZIONI : " ; cin >> scelta1 ; cin >> scelta2;
    if (scelta1 > i || scelta2 > i )
    {
        cout<< "SCELTA NON VALIDA.\n\n";
        return main();
    }
    else {
        it = v.begin();
        i = 1;
        j = 1;
        while (scelta1 != i) {
            it++;
            i++;
        }
        A = it.operator*();
        it = v.begin();
        while (scelta2 != j) {
            it++;
            j++;
        }
        B = it.operator*();


        cout << "\n\nSCEGLIERE L'OPERAZIONE DA ESEGUIRE\n";
        cout << "\nUNIONE(TASTO 'U') ,INTERSEZIONE(TASTO 'I') ,DIFFERENZA(TASTO 'D')\n";
        cout << "(TASTO 'T') ESEGUIAMO TUTTE LE OPERAZIONI : ";
        cin >> c;

        if (c >= 'a' && c <= 'z')
            c = c - 32;

        switch (c) {
            case 'U' :
                cout << "\n\n\n\t\t\t\tINSIEME " << scelta1 << " UNITO" << " INSIEME" << scelta2 << endl;
                U.UNIONE(A, B, A->getroot(), B->getroot());
                U.EliminaDuplicati(U.getroot());
                if (U.getroot() == U.getnill())
                    cout << "INSIEME VUOTO \n\n";
                else
                    U.inorder(U.getroot());
                cout << "\n\n";

                break;

            case 'I' :
                cout << "\n\n\t\t\t\tINSIEME " <<scelta1 << "  INTERSECATO " << " INSIEME " << scelta2 << endl;
                I.INTERSEZIONE(A, B, A->getroot(), B->getroot());
                if (I.getroot() == I.getnill())
                    cout << "INSIEME VUOTO \n\n";
                else
                    I.inorder(I.getroot());
                cout << "\n\n";
                break;

            case 'D' :
                cout << "\n\n\t\t\t\tINSIEME " <<scelta1 << " - " << "INSIEME " << scelta2 << endl;
                D.DIFFERENZA(&D,A, B, A->getroot(), B->getroot(), k);
                if (D.getroot() == D.getnill())
                    cout << "INSIEME VUOTO \n\n";
                else
                    D.inorder((D.getroot()));
                cout << "\n\n";

                break;

            case 'T' :
                cout << "\n\t\t\t\tINSIEME " <<scelta1 << " UNITO " << "INSIEME " << scelta2 << endl;
                U.UNIONE(A, B, A->getroot(), B->getroot());
                U.EliminaDuplicati(U.getroot());

                if (U.getroot() == U.getnill())
                    cout << "INSIEME VUOTO \n";
                else
                    U.inorder(U.getroot());

                cout << "\n\n\t\t\t\tINSIEME " <<scelta1 << " INTERSECATO " << "INSIEME " << scelta2 << endl;
                I.INTERSEZIONE(A, B, A->getroot(), B->getroot());
                if (I.getroot() == I.getnill())
                    cout << "INSIEME VUOTO \n";
                else
                    I.inorder(I.getroot());

                cout << "\n\n\t\t\t\t  INSIEME " << scelta1 << " - " << "INSIEME " << scelta2 << endl;
                D.DIFFERENZA(&D,A ,B, A->getroot(), B->getroot(), k);
                if (D.getroot() == D.getnill())
                    cout << "INSIEME VUOTO \n";
                else
                    D.inorder((D.getroot()));
                cout << "\n\n";

                break;
        }
    }

    cout<<"PREMERE '0' PER USCIRE QUALSIASI ALTRO TASTO PER CONTINUARE : ";
    cin>>c ;

    if(c == '0')
        cout<<"\nARRIVEDERCI.";
    else
        return main();

}

