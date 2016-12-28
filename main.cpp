#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod* succ;
    nod* pred;
};

struct lista
{
    unsigned int lungime;
    nod* prim;
    nod* ultim;
    nod* stg;
    nod* drp;
};

void initializeaza (lista& L)
{
    L.stg=new nod;
    L.drp=new nod;
    L.stg->succ=L.drp;
    L.stg->pred=NULL;
    L.drp->pred=L.stg;
    L.drp->succ=NULL;
    L.ultim=NULL;
    L.prim=NULL;
    L.lungime=0;
}

void adauga (lista& L, int e)
{
    if (L.lungime==0)
    {
        L.ultim=new nod;
        L.ultim->info=e;
        L.ultim->succ=L.drp;
        L.ultim->pred=L.stg;
        L.drp->pred=L.ultim;
        L.stg->succ=L.ultim;
        L.prim=L.ultim;
    }
    else
    {
        nod* p;
        p=new nod;
        p->info=e;
        p->succ=L.drp;
        p->pred=L.ultim;
        L.ultim->succ=p;
        L.drp->pred=p;
        L.ultim=p;
    }
    L.lungime++;
}

void sterge(nod* p)
{
    nod *q, *r;
    q=p->pred;
    r=p->succ;
    q->succ=r;
    r->pred=q;
    delete p;
}

void citeste (lista& L)
    {
        unsigned int n;
        int x;
        unsigned int i;
        cout<<"Dati nr. de elemente: ";
        cin>>n;
        initializeaza(L);
        for (i=1; i<=n; i++)
        {
            cout<<"Dati elememtul al "<<i<<" lea ";
            cin>>x;
            adauga(L,x);
        }
    }

void afiseaza (lista L)
{
    nod*p;
    p=L.prim;
    while (p!=L.drp)
    {
        cout<<p->info<<",";
        p=p->succ;
    }
    cout<<endl;
}

void eliminaNegative (lista &L)
{
    nod *p, *q, *r;;
    p=L.prim;
    while (p!=L.drp)
    {
        q=p->succ;;
        if (p->info<0)
        {
            sterge(p);
            L.lungime--;
        }
        p=q->succ;
    }
    L.prim=L.stg->succ;
    L.ultim=L.drp->pred;
}

int main()
{
    lista L;
    citeste(L);
    cout<<"Lista inlantuita: ";
    afiseaza(L);
    eliminaNegative(L);
    cout<<"Lista finala: ";
    afiseaza(L);

        return 0;
}
