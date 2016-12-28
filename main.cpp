#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod* stg;
    nod* dr;
};

void adaugare(nod *&a, int el)
{
    if (a==NULL)
    {
        a=new nod;
        a->info=el;
        a->stg=NULL;
        a->dr=NULL;
    }
    else if (el<=a->info)
        adaugare(a->stg,el);
    else adaugare(a->dr,el);
}

void creare (nod*&a)
{
    unsigned int i;
    unsigned int n;
    int x;
    a=NULL;
    cout<<"Dati nr de elemente: ";
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cout<<"Dati elementul al "<<i<<" lea: ";
        cin>>x;
        adaugare(a,x);
    }
}

bool cautare(nod *a,int el)
{
    if (a==NULL) return false;
    else if (a->info==el)
        return true;
    else if (el<a->info) return cautare(a->stg,el);
    return cautare(a->dr,el);
}

void postordine (nod*a)
{
    if (a)
    {
        postordine(a->stg);
        postordine(a->dr);
        cout<<a->info<<" ";
    }
}
void inordine (nod*a)
{
    if (a)
    {
        inordine(a->stg);
        cout<<a->info<<" ";
        inordine(a->dr);
    }
}

void preordine (nod*a)
{
    if (a)
    {
        cout<<a->info<<" ";
        preordine(a->stg);
        preordine(a->dr);
    }
}
int inaltime (nod*a)
{
    if (a==NULL)
        return -1;
    else
    {
        int h1=inaltime(a->stg);
        int h2=inaltime(a->dr);
        return 1+(h1>h2?h1:h2);
    }
}

int CoadaVida()
{
    return NULL;
}

void parcurgereLatime(nod *a)
{
    nod *Q[100];
    int prim=0,ultim=0;
    if (a==NULL) return;
    else
    {
        Q[prim]=a;
        while (prim<=ultim)
        {
            cout<<Q[prim]->info<<" ";
            if (Q[prim]->stg!=NULL)
            {
                Q[++ultim]=Q[prim]->stg;
            }
            if (Q[prim]->dr!=NULL)
            {
                Q[++ultim]=Q[prim]->dr;
            }
            prim++;
        }
    }
}

void parcurgereAdancime(nod *a)
{
    nod *Q[100];
    int prim=0,ultim=0;
    if (a==NULL) return;
    else
    {
        Q[prim]=a;
        while (prim<=ultim)
        {
            cout<<Q[prim]->info<<" ";
            if (Q[prim]->stg!=NULL)
            {
                Q[++ultim]=Q[prim]->stg;
            }
            else
            {
                if (Q[prim]->dr!=NULL)
                {
                    Q[++ultim]=Q[prim]->dr;
                }


            }
            prim++;
        }
    }
}
int main()
{
    nod* a;
    int x;
    creare(a);
    cout<<" \n Preordine: ";
    preordine(a);
    cout<<" \n Inordine: ";
    inordine(a);
    cout<<" \n Postordine: ";
    postordine(a);
    cout<<" \n In latime: ";
    parcurgereLatime (a);
    cout<<" \n In adancime: ";
    parcurgereAdancime (a);
    do
    {
        cout<<"\n Dati elementul cautat: ";
        cin>>x;
        if (cautare(a,x))
            cout<<x<<" se gaseste \n";
        else
            cout<<" nu se gaseste \n";
    }
    while (x!=0);

    return 0;
}
