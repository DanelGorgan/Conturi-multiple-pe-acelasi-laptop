#include <iostream>
#define tipDate int

using namespace std;

struct nod
{
    int info;
    nod *urm;
};

nod *L;


void citesteListaSimpla(nod *&L)
{
    nod *p;
    unsigned int nrElemente;
    cout<<"Dati numarul de elemente: ";
    cin>>nrElemente;

    tipDate element;
    L=NULL;
    for (unsigned int i=1; i<=nrElemente; i++)
    {
        cout<<"Dati elementul al "<<i<<"-lea: ";
        cin>>element;
        p=new nod;
        p->info=element;
        p->urm=L;
        L=p;
    }
}

void afiseazaListaSimpla(nod* L)
{
    nod *p;
    cout<<'\n';
    p=L;
    while (p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->urm;
    }
}
int main()
{
    citesteListaSimpla(L);

    afiseazaListaSimpla(L);
    return 0;
}
