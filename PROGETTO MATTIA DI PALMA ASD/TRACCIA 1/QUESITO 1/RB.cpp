#include <iostream>
#include "RB.h"
#include <string>

using namespace std ;

NODO* RB::ricerca(NODO *x, int key)
{
    if ( x == this->nill || key == x->getkey())
        return x;

    if (key < x->getkey())
    {
        return this->ricerca(x->getleft(), key);
    }
    else
    {
        return this->ricerca(x->getright(), key);

    }

}


NODO* RB::minimo(NODO *x)
{
    while( x->getleft() != this->nill)
        x = x->getleft();

    return x;
}


void RB::preorder (NODO *x)
{
    if (x != this->nill)
    {
        cout << x->getkey() << " ";
        preorder(x->getleft());
        preorder(x->getright());
    }
}

void RB::inorder( NODO *x){

    if(x!=this->nill){

        inorder(x->getleft());

        cout<<x->getkey()<<" ";

        inorder(x->getright());

    }
}
void RB::left_rotate( NODO *x)
{
    if (x != this->getnill()) {
        NODO *y = x->getright();
        x->setright(y->getleft());

            if (y->getleft() != this->nill)
                y->getleft()->setpadre(x);

            y->setpadre(x->getpadre());

            if (x->getpadre() == this->nill)
                this->root = y;
            else if (x == x->getpadre()->getright())

                x->getpadre()->setright(y);
            else
                x->getpadre()->setleft(y);

            y->setleft(x);
            x->setpadre(y);
        }
}


void RB::right_rotate(NODO* x)
{
    if ( x != this->getnill()) {
        NODO *y = x->getleft();
        x->setleft(y->getright());

        if (y->getright() != this->nill)
            y->getright()->setpadre(x);

        y->setpadre(x->getpadre());

        if (x->getpadre() == this->nill)
            this->root = y;
        else if (x == x->getpadre()->getleft())
            x->getpadre()->setleft(y);
        else
            x->getpadre()->setright(y);

        y->setright(x);
        x->setpadre(y);
    }
}

void RB::inserimento(int key ) {
    NODO *z = new NODO(key);
    NODO *y = this->nill;
    NODO *x = this->root;


    while (x != this->nill) {
        y = x;

        if (z->getkey() < x->getkey()) {
            x = x->getleft();
        } else {
            x = x->getright();
        }
    }

    z->setpadre(y);
    z->setright(this->nill);
    z->setleft(this->nill);

    if (y == this->nill)
        this->root = z;

    else if (z->getkey() < y->getkey())
        y->setleft(z);
    else
        y->setright(z);

    z->setcolore(" RED ");

    while (z != this->root && z->getpadre()->getcolore() == " RED ") {
        if (z->getpadre()->getpadre() != this->nill) {
            if (z->getpadre() == z->getpadre()->getpadre()->getleft()) {
                y = z->getpadre()->getpadre()->getright();

                if (y != this->nill && y->getcolore() == " RED ") {
                    z->getpadre()->setcolore(" BLACK ");
                    y->setcolore(" BLACK ");
                    z->getpadre()->getpadre()->setcolore(" RED ");
                    z = z->getpadre()->getpadre();
                }

                else if (z == z->getpadre()->getright()) {
                    z = z->getpadre();
                    this->left_rotate(z);
                }

                else if (z->getpadre() != this->nill && z->getpadre()->getpadre() != this->nill  ) {
                    z->getpadre()->setcolore(" BLACK ");
                    z->getpadre()->getpadre()->setcolore(" RED ");
                    this->right_rotate(z->getpadre()->getpadre());
                }

            } else if (z->getpadre() == z->getpadre()->getpadre()->getright()) {
                y = z->getpadre()->getpadre()->getleft();
                if (y != this->nill && y->getcolore() == " RED ") {
                    z->getpadre()->setcolore(" BLACK ");
                    y->setcolore(" BLACK ");
                    z->getpadre()->getpadre()->setcolore(" RED ");
                    z = z->getpadre()->getpadre();
                }
                else if (z == z->getpadre()->getleft()) {
                    z = z->getpadre();
                    this->right_rotate(z);
                }
                 else if (z->getpadre() != this->nill && z->getpadre()->getpadre() != this->nill ) {
                    z->getpadre()->setcolore(" BLACK ");
                    z->getpadre()->getpadre()->setcolore(" RED ");
                    this->left_rotate( z->getpadre()->getpadre());
                }
            }
        }
    }
    this->root->setcolore(" BLACK ");
}


void RB::delete_fixup ( NODO* x)
{
    NODO* w;

    while (x != this->root && x->getcolore()==" BLACK " && x!= this->getnill())
    {
        if( x == x->getpadre()->getleft()) {
            w = x->getpadre()->getright();

                if (w->getcolore() == " RED ") {
                    w->setcolore(" BLACK ");
                    w->getpadre()->setcolore(" RED ");
                    this->left_rotate(x->getpadre());
                }

                if (w->getleft()->getcolore() == " BLACK " && w->getright()->getcolore() == " BLACK ") {
                    w->setcolore(" RED ");
                    x = x->getpadre();
                } else if (w->getright()->getcolore() == " BLACK ") {
                    w->getleft()->setcolore(" BLACK ");
                    w->setcolore(" RED ");
                    this->right_rotate(w);
                    w = x->getpadre()->getright();
                }

                w->setcolore(x->getpadre()->getcolore());
                x->getpadre()->setcolore(" BLACK ");
                w->getright()->setcolore(" BLACK ");
                this->left_rotate(x->getpadre());
                x = this->root;
        }
        else if ( x == x->getpadre()->getright() ) {
            w = x->getpadre()->getleft();

                if (w->getcolore() == " RED ") {
                    w->setcolore(" BLACK ");
                    x->getpadre()->setcolore(" RED ");
                    this->right_rotate(x->getpadre());
                    w = x->getpadre()->getleft();
                }

                if (w->getleft()->getcolore() == " BLACK " && w->getright()->getcolore() == " BLACK ") {
                    w->setcolore(" RED ");
                    x = x->getpadre();
                } else if (w->getleft()->getcolore() == " BLACK ") {
                    w->getright()->setcolore(" BLACK ");
                    w->setcolore(" RED ");
                    this->left_rotate(w);
                    w = x->getpadre()->getright();

                }

                w->setcolore(x->getpadre()->getcolore());
                x->getpadre()->setcolore(" BLACK ");
                w->getleft()->setcolore(" BLACK ");
                this->right_rotate(x->getpadre());
                x = this->root;
        }
    }
    x->setcolore(" BLACK ");
}

void RB::transplant_RB( NODO* u , NODO* v)
{
    if(u->getpadre() == this->nill){
        this->root = v;
    }
    else if (u == u->getpadre()->getleft())
    {
        u->getpadre()->setleft(v);
    }
    else
        u->getpadre()->setright(v);

    v->setpadre(u->getpadre());
}

void RB::delete_RB( NODO* z)
{
    NODO* y = z ;
    NODO* x;
    string ycolore = y->getcolore();

    if(z->getleft() == this->nill ){
        x = z->getright();
       this->transplant_RB( z , z->getright());
    }
    else if ( z->getright() == this->nill)
    {
        x = z->getleft();
        this->transplant_RB(z, z->getleft());
    }
    else {
        y = this->minimo(z->getright());
        ycolore = y->getcolore();
        x = y->getright();
        if (y->getpadre() == z)
            x->setpadre(y);
        else {
            this->transplant_RB( y, y->getright());
            y->setright(z->getright());
            y->getright()->setpadre(y);
        }
        this->transplant_RB(z, y);
        y->setleft(z->getleft());
        y->getleft()->setpadre(y);
        y->setcolore(z->getcolore());
    }

    if (ycolore == " BLACK ") {
        this->delete_fixup(x);
    }
}

void RB::UNIONE(RB* T , RB* X , NODO* A , NODO* B )
{
    if(A != T->getnill() && B != X->getnill()){

                this->inserimento(A->getkey());
                this->inserimento(B->getkey());


        this->UNIONE(T , X , A->getleft() , B->getleft());
        this->UNIONE(T , X , A->getright() , B->getright());
    }
    else if (A != T->getnill()){

        this->inserimento(A->getkey());

        this->UNIONE(T , X , A->getleft() , B);
        this->UNIONE(T , X , A->getright() , B);
    }
    else if (B != X->getnill()) {

        this->inserimento(B->getkey());

        this->UNIONE(T, X, A ,B->getleft());
        this->UNIONE(T, X, A ,B->getright());
    }
}

void RB::INTERSEZIONE (RB* T , RB* X , NODO* A , NODO* B )
{
    if(A != T->getnill())
        if(X->ricerca(B , A->getkey()) != X->nill){
            this->inserimento(A->getkey()) ;
            this->INTERSEZIONE(T , X , A->getleft() , B);
            this->INTERSEZIONE(T , X , A->getright() , B);
        }
    else{
            this->INTERSEZIONE(T , X , A->getleft() , B);
            this->INTERSEZIONE(T , X , A->getright() , B);
    }
}

void RB::DIFFERENZA (RB*D,RB* T ,RB* X , NODO* A , NODO* B , NODO* k )
{

    if (A != T->nill)
    {
        k = X->ricerca(B,A->getkey());
        if(k == X->getnill())
        {
            D->inserimento(A->getkey());
            T->DIFFERENZA(D,T, X , A->getleft() , B , k);
            T->DIFFERENZA(D,T, X , A->getright(), B , k );
        }
        else
        {
            T->DIFFERENZA(D,T, X, A->getleft(), B ,k);
            T->DIFFERENZA(D,T, X, A->getright() , B , k);
        }
    }
}


void RB::EliminaDuplicati(NODO* y )
{
    if(y != this->getnill())
    {
        NODO* x = y ;
        int key = x->getkey();
        int i = 0;

        while( x != this->nill || key == x->getkey()) {

            if (key == x->getkey())
            {
                i++;
                if (x->getleft()->getkey() == key || x->getright()->getkey() == key)
                {
                    if (x->getright()->getkey() != key)
                        i++;

                }
            }

            if (key < x->getkey() )
                x = x->getleft();
            else
                x = x->getright();
        }

        if(i == 2) {
            this->delete_RB(y);
        }
        else if (i>2){

            while (i>2){
                int n = y->getkey();
                this->delete_RB(y);
                NODO* k = this->ricerca(this->getroot(),n);
                this->delete_RB(k);
                i--;
            }
        }

        EliminaDuplicati(y->getleft());

        EliminaDuplicati(y->getright());
    }
}
