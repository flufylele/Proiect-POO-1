#include <iostream>
using namespace std;

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class nod
{
public:
    int value;
    nod *next;

};

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class lista
{
public:
    nod *Head;
    lista ();
    void InserareInceputLista(int);
    void InserareSfarsitLista (int);
    void AfisareLista();

};

lista::lista()
{
    Head = NULL;
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lista::InserareInceputLista(int valoare)
{
  nod* nou= new nod;
  nou->value=valoare;
  nou->next=NULL;

    if(Head==NULL)
    {
     Head=nou;
    }
    else
    {
        nou->next=Head;
        Head=nou;
    }

}

void lista::InserareSfarsitLista(int valoare)
{
  nod* nou= new nod;
  nou->value=valoare;
  nou->next=NULL;

    if(Head==NULL)
    {
     Head=nou;
    }
    else
    {   nod *temp=Head;
         while(temp->next!=NULL)
            {
                temp=temp->next;
            }

        temp->next=nou;
    }

}

void lista::AfisareLista ()
{
     nod* temp = Head;

  if(Head==NULL)  cout<<"Lista este vida!";
else
{
   while(temp!=NULL)
  {
      cout<<temp->value<<" ";
      temp=temp->next;
  }

}
cout<<'\n';
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class multime
{
public:
    lista list;
    multime();
    multime (const multime &);
    multime operator = (const multime&);
    multime operator + (const multime&);
    multime operator *(const multime&);
    multime operator -(const multime&);
    friend istream& operator >>(istream &in,multime &);
    friend ofstream& operator <<(ostream &out, const multime &);
    friend bool operator ==(const multime &, const multime &);
    friend bool operator !=(const multime &,const multime &);
    friend bool operator < (const multime &,const multime &);
    friend bool operator <= (const multime &,const multime &);
    friend bool operator > (const multime &,const multime &);
    friend bool operator >= (const multime &,const multime &);
    void EliminareDuplicate();
};

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

multime::multime()
    {
        list.Head=NULL;
    }

multime::multime(const multime &a)
{
   nod *temp=a.list.Head;
   while(temp)
   {
       list.InserareSfarsitLista(temp->value);
       temp=temp->next;
   }
}

multime multime::operator=(const multime &a)
{
 list.Head=a.list.Head;
}


bool operator == (const multime &a, const multime&b)
{
    int suma1=0,suma2=0;
    nod *temp1=a.list.Head;
    nod *temp2=b.list.Head;
    while(temp1)
    {
        suma1+=temp1->value;
        temp1=temp1->next;
    }
    while (temp2)
    {
     suma2+=temp2->value;
     temp2=temp2->next;
    }

    if(suma1==suma2)
    {
        return true;
    }
    else return false;
}

bool operator !=(const multime &a,const multime &b)
{
    return !(a== b);
}

bool operator < (const multime &a,const multime &b)
{
     int suma1=0,suma2=0;
    nod *temp1=a.list.Head;
    nod *temp2=b.list.Head;
    while(temp1)
    {
        suma1+=temp1->value;
        temp1=temp1->next;
    }
    while (temp2)
    {
     suma2+=temp2->value;
     temp2=temp2->next;
    }

    if(suma1<suma2)
    {
        return true;
    }
    else return false;
}


bool operator <= (const multime &a,const multime &b)
{
     int suma1=0,suma2=0;
    nod *temp1=a.list.Head;
    nod *temp2=b.list.Head;
    while(temp1)
    {
        suma1+=temp1->value;
        temp1=temp1->next;
    }
    while (temp2)
    {
     suma2+=temp2->value;
     temp2=temp2->next;
    }

    if(suma1<=suma2)
    {
        return true;
    }
    else return false;
}

bool operator > (const multime &a,const multime &b)
{
     int suma1=0,suma2=0;
    nod *temp1=a.list.Head;
    nod *temp2=b.list.Head;
    while(temp1)
    {
        suma1+=temp1->value;
        temp1=temp1->next;
    }
    while (temp2)
    {
     suma2+=temp2->value;
     temp2=temp2->next;
    }

    if(suma1>suma2)
    {
        return true;
    }
    else return false;
}

bool operator >= (const multime &a,const multime &b)
{
     int suma1=0,suma2=0;
    nod *temp1=a.list.Head;
    nod *temp2=b.list.Head;
    while(temp1)
    {
        suma1+=temp1->value;
        temp1=temp1->next;
    }
    while (temp2)
    {
     suma2+=temp2->value;
     temp2=temp2->next;
    }

    if(suma1>=suma2)
    {
        return true;
    }
    else return false;
}




istream& operator >>(istream&in,multime &a)
{
    int n;
    cout<<"Cate elemente introduceti in multime?"<<'\n';
    in>>n;
    cout<<"Introduceti valorile"<<'\n';
    for(int i=1;i<=n;i++)
    {
        int valoare;
        in>>valoare;
        a.list.InserareSfarsitLista(valoare);
    }


    return in;
}


ofstream& operator <<(ostream &out, multime &a)
{
    a.list.AfisareLista();
}


multime multime::operator +(const multime &a)
{
    multime aux;
    multime aux1=a;
    multime aux2;
    aux2.list.Head=this->list.Head;

        while(aux2.list.Head)
        {
            aux.list.InserareSfarsitLista(aux2.list.Head->value);
            aux2.list.Head=aux2.list.Head->next;
        }


        while(aux1.list.Head)
        {
            aux.list.InserareSfarsitLista(aux1.list.Head->value);
            aux1.list.Head=aux1.list.Head->next;
        }

aux.EliminareDuplicate();
return aux;

}


multime multime::operator*(const multime &a)
{

    multime aux;
    multime aux1=a;
    multime aux2;
    aux2.list.Head=this->list.Head;


        while(aux1.list.Head)
        {
             while(aux2.list.Head)
                {
                    if (aux1.list.Head->value==aux2.list.Head->value)
                    {
                        aux.list.InserareSfarsitLista(aux1.list.Head->value);
                        aux2.list.Head=aux2.list.Head->next;
                    }
                    else
                    {
                        aux2.list.Head=aux2.list.Head->next;
                    }
                }
            aux2.list.Head=this->list.Head;
            aux1.list.Head=aux1.list.Head->next;
        }

        aux.EliminareDuplicate();

        return aux;


}

multime multime::operator- (const multime &a)
{
    multime aux;
    multime aux1;
    aux1.list.Head=this->list.Head;
    multime aux2=a;
    int counter=0;

        while(aux1.list.Head)
        {
             while(aux2.list.Head)
                {
                    if (aux1.list.Head->value!=aux2.list.Head->value)
                    {
                        aux2.list.Head=aux2.list.Head->next;
                    }
                    else
                    {
                    counter++;
                    aux2.list.Head=aux2.list.Head->next;
                    }

                }
                    if(counter==0)
                    {
                        aux.list.InserareSfarsitLista(aux1.list.Head->value);
                    }



            aux1.list.Head=aux1.list.Head->next;
            aux2.list.Head=a.list.Head;
            counter=0;

        }



        return aux;

}


void multime::EliminareDuplicate()
{
    nod *temp1=list.Head;
    nod *temp2;
    nod *sters;

    while(temp1 !=NULL && temp1->next !=NULL)
    {
        temp2=temp1;
        while(temp2->next!=NULL)
        {
            if(temp1->value ==temp2->next->value)
            {
                sters=temp2->next;
                temp2->next = temp2->next->next;
                delete(sters);
            }
            else
            {
                temp2=temp2->next;
            }
        }
        temp1=temp1->next;
    }
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class pereche
{
public:

    int x,y;
    pereche();
    pereche(int,int);
    pereche(const pereche &);
    pereche operator = (const pereche &);
    friend istream &operator >> (istream &in,const pereche &);
    friend ofstream &operator << (ostream &out,const pereche &);
    friend bool operator == (const pereche &, const pereche &);
    friend bool operator != (const pereche &, const pereche &);
    friend bool operator < (const pereche &, const pereche &);
    friend bool operator <= (const pereche &, const pereche &);
    friend bool operator > (const pereche &, const pereche &);
    friend bool operator >= (const pereche &, const pereche &);

};

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

pereche::pereche()
{
    x=0;
    y=0;
}

pereche::pereche(int i,int j)
{
    x=i;
    y=j;
}

pereche::pereche(const pereche &a)
{
    x=a.x;
    y=a.y;
}

pereche pereche::operator=(const pereche &a)
{
    x=a.x;
    y=a.y;

    return *this;
}


bool operator ==(const pereche &a, const pereche &b)
{
    int suma1=0,suma2=0;
    suma1=a.x+a.y;
    suma2=b.x+b.y;

    if(suma1==suma2)
    {
        return true;
    }

    else return false;
}

bool operator !=(const pereche &a, const pereche &b)
{
    return !(a==b);
}

bool operator <(const pereche &a, const pereche &b)
{
    int suma1=0,suma2=0;
    suma1=a.x+a.y;
    suma2=b.x+b.y;

    if(suma1<suma2)
    {
        return true;
    }

    else return false;
}

bool operator <=(const pereche &a, const pereche &b)
{
    int suma1=0,suma2=0;
    suma1=a.x+a.y;
    suma2=b.x+b.y;

    if(suma1<=suma2)
    {
        return true;
    }

    else return false;
}

bool operator >(const pereche &a, const pereche &b)
{
    int suma1=0,suma2=0;
    suma1=a.x+a.y;
    suma2=b.x+b.y;

    if(suma1>suma2)
    {
        return true;
    }

    else return false;
}

bool operator >=(const pereche &a, const pereche &b)
{
    int suma1=0,suma2=0;
    suma1=a.x+a.y;
    suma2=b.x+b.y;

    if(suma1>=suma2)
    {
        return true;
    }

    else return false;
}


istream &operator >>(istream &in,pereche &a)
{
    cout <<"Introduceti perechea"<<'\n';
    in>>a.x;
    in>>a.y;

    return in;
}

ofstream &operator <<(ostream &out, pereche &a)
{
    cout <<"("<<a.x<<" ; "<<a.y<<")";
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class nod_pereche
{
public:

    pereche pair;
    nod_pereche *next;
};

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class lista_pereche
{   public:

    nod_pereche *Head;
    lista_pereche ();
    void InserareInceputLista(pereche a);
    void InserareInceputLista(int,int);
    void InserareSfarsitLista (pereche a);
    void InserareSfarsitLista(int ,int);
    void AfisareLista();
    friend class multime_perechi;

};

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

lista_pereche::lista_pereche()
{
    Head=NULL;
}

void lista_pereche::InserareInceputLista(pereche a)
{
  nod_pereche* nou= new nod_pereche;
  nou->pair.x=a.x;
  nou->pair.y=a.y;
  nou->next=NULL;

    if(Head==NULL)
    {
     Head=nou;
    }
    else
    {
        nou->next=Head;
        Head=nou;
    }

}

void lista_pereche::InserareInceputLista(int x, int y)
{
  nod_pereche* nou= new nod_pereche;
  nou->pair.x=x;
  nou->pair.y=y;
  nou->next=NULL;

    if(Head==NULL)
    {
     Head=nou;
    }
    else
    {
        nou->next=Head;
        Head=nou;
    }

}

void lista_pereche::InserareSfarsitLista(pereche a)
{
  nod_pereche* nou= new nod_pereche;
  nou->pair.x=a.x;
  nou->pair.y=a.y;
  nou->next=NULL;

    if(Head==NULL)
    {
     Head=nou;
    }
    else
    {   nod_pereche *temp=Head;
         while(temp->next!=NULL)
            {
                temp=temp->next;
            }

        temp->next=nou;
    }

}

void lista_pereche::InserareSfarsitLista(int x, int y)
{
  nod_pereche* nou= new nod_pereche;
  nou->pair.x=x;
  nou->pair.y=y;
  nou->next=NULL;

    if(Head==NULL)
    {
     Head=nou;
    }
    else
    {   nod_pereche *temp=Head;
         while(temp->next!=NULL)
            {
                temp=temp->next;
            }

        temp->next=nou;
    }

}

void lista_pereche::AfisareLista ()
{
    nod_pereche* temp = Head;

  if(Head==NULL)  cout<<"Lista este vida!";
else
{
   while(temp!=NULL)
  {
      cout<<temp->pair;
      cout<<" , ";
      temp=temp->next;
  }

}

}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class multime_perechi
{   public:
    friend class multime;
    lista_pereche list;
    multime_perechi();
    multime_perechi (const multime_perechi &);
    multime_perechi operator = (const multime_perechi&);
    friend istream& operator >>(istream &in,multime_perechi &);
    friend ofstream& operator <<(ostream &out, multime_perechi &);
    friend bool operator == (const multime_perechi &, const multime_perechi &);
    friend bool operator != (const multime_perechi &, const multime_perechi &);
    friend bool operator < (const multime_perechi &, const multime_perechi &);
    friend bool operator <= (const multime_perechi &, const multime_perechi &);
    friend bool operator > (const multime_perechi &, const multime_perechi &);
    friend bool operator >= (const multime_perechi &, const multime_perechi &);
    void ProdusCartezian(multime,multime);
};

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


multime_perechi::multime_perechi()
    {
        list.Head=NULL;
    }

multime_perechi::multime_perechi(const multime_perechi &a)
{
   nod_pereche *temp=a.list.Head;
   while(temp)
   {
       list.InserareSfarsitLista(temp->pair.x, temp->pair.y);
       temp=temp->next;
   }
}

multime_perechi multime_perechi::operator= (const multime_perechi&a)
{
    nod_pereche *temp=a.list.Head;
   while(temp)
   {
       list.InserareSfarsitLista(temp->pair.x, temp->pair.y);
       temp=temp->next;
   }
}

bool operator ==(const multime_perechi &a, const multime_perechi &b)
{
    int suma1=0,suma2=0;
    nod_pereche *temp1=a.list.Head;
    nod_pereche *temp2=b.list.Head;
    while(temp1)
    {
        suma1+=temp1->pair.x+temp1->pair.y;
        temp1=temp1->next;
    }
    while (temp2)
    {
     suma2+=temp2->pair.x+temp2->pair.y;
     temp2=temp2->next;
    }

    if(suma1==suma2)
    {
        return true;
    }
    else return false;
}

bool operator !=(const multime_perechi &a, const multime_perechi &b)
{
    return !(a==b);
}

bool operator <(const multime_perechi &a, const multime_perechi &b)
{
    int suma1=0,suma2=0;
    nod_pereche *temp1=a.list.Head;
    nod_pereche *temp2=b.list.Head;
    while(temp1)
    {
        suma1+=temp1->pair.x+temp1->pair.y;
        temp1=temp1->next;
    }
    while (temp2)
    {
     suma2+=temp2->pair.x+temp2->pair.y;
     temp2=temp2->next;
    }

    if(suma1<suma2)
    {
        return true;
    }
    else return false;
}

bool operator <=(const multime_perechi &a, const multime_perechi &b)
{
    int suma1=0,suma2=0;
    nod_pereche *temp1=a.list.Head;
    nod_pereche *temp2=b.list.Head;
    while(temp1)
    {
        suma1+=temp1->pair.x+temp1->pair.y;
        temp1=temp1->next;
    }
    while (temp2)
    {
     suma2+=temp2->pair.x+temp2->pair.y;
     temp2=temp2->next;
    }

    if(suma1<=suma2)
    {
        return true;
    }
    else return false;
}

bool operator >(const multime_perechi &a, const multime_perechi &b)
{
    int suma1=0,suma2=0;
    nod_pereche *temp1=a.list.Head;
    nod_pereche *temp2=b.list.Head;
    while(temp1)
    {
        suma1+=temp1->pair.x+temp1->pair.y;
        temp1=temp1->next;
    }
    while (temp2)
    {
     suma2+=temp2->pair.x+temp2->pair.y;
     temp2=temp2->next;
    }

    if(suma1>suma2)
    {
        return true;
    }
    else return false;
}

bool operator >=(const multime_perechi &a, const multime_perechi &b)
{
    int suma1=0,suma2=0;
    nod_pereche *temp1=a.list.Head;
    nod_pereche *temp2=b.list.Head;
    while(temp1)
    {
        suma1+=temp1->pair.x+temp1->pair.y;
        temp1=temp1->next;
    }
    while (temp2)
    {
     suma2+=temp2->pair.x+temp2->pair.y;
     temp2=temp2->next;
    }

    if(suma1>=suma2)
    {
        return true;
    }
    else return false;
}

istream& operator >>(istream &in,multime_perechi &a)
{   int n;
    cout<<"Cate perechi introduceti?"<<'\n';
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        pereche b;
        cin>>b;
        a.list.InserareSfarsitLista(b.x , b.y);
    }
}

 ofstream& operator <<(ostream &out, multime_perechi &a)
 {
     a.list.AfisareLista();
 }

void multime_perechi::ProdusCartezian (multime a, multime b)
{
    a.EliminareDuplicate();
    b.EliminareDuplicate();
    multime temp1=a;
    multime temp2=b;
    while (temp1.list.Head)
    {
        while (temp2.list.Head)
        {
            list.InserareSfarsitLista(temp1.list.Head->value,temp2.list.Head->value);
            temp2.list.Head=temp2.list.Head->next;
        }
        temp1.list.Head=temp1.list.Head->next;
        temp2.list.Head=b.list.Head;
    }

}

void sort (multime *a,int n)
{int ok,i;
multime aux;
    do
    {  ok=1;
            for(i=1;i<=n-1;i++)
            {
                if(a[i]>a[i+1])
                    {ok=0;
                    aux=a[i];
                    a[i]=a[i+1];
                    a[i+1]=aux;
                    }
            }
    }
 while(ok!=1);
 }

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{ int n;
cout<<"Cate multimi doriti sa introduceti?\n";
cin>>n;
cout<<'\n';
multime * ceva=new multime [n+1];
for(int i=1;i<=n;i++) cin>> ceva[i];

cout<<"-----------------------------------------------------------Sortare-----------------------------------------------------------\nMultimile nesortate:\n";

for(int i=1;i<=n;i++) cout<<ceva[i];
cout<<'\n';
sort(ceva,n);
cout<<"Multimile sortate:\n";
for(int i=1;i<=n;i++) cout<<ceva[i];

cout<<"\n-------------------------------------------------------------------------------------------------\n\n";

    multime multimea1,multimea2;
    cout<<"\nIntroduceti doua multimi. Introduceti si duplicate in prima multime pentru evidentierea functiei de eliminare a duplicatelor ^.^\n";
    cin>>multimea1;
    cout<<"\nMultimea este: ";
    cout<<multimea1;
    multimea1.EliminareDuplicate();
    cout<<"\nDupa eliminarea duplicatelor, multimea este:\n";
    cout<<multimea1;
    cin>>multimea2;
    cout<<"\nReuniunea celor 2 multimi este: ";
    multime multimea3;
    multimea3=multimea1+multimea2;
    cout<<multimea3;
    cout<<"\nIntersectia celor 2 multimi este: ";
    multime multimea4;
    multimea4=multimea1*multimea2;
    cout<<multimea4;
    cout<<"\nDiferenta celor 2 multimi este: ";
    multime multimea5;
    multimea5=multimea1-multimea2;
    cout<<multimea5;
    multime_perechi produs;
    cout<<"\nProdusul cartezian al celor 2 multimi este: \n";
    produs.ProdusCartezian(multimea1,multimea2);
    cout<<produs;
    cout<<'\n';
    pereche perechea1;
    cout<<'\n';
    cin>>perechea1;
    cout<<perechea1;
    multime_perechi multime_perechi1;
    cout<<'\n';
    cin>>multime_perechi1;
    cout<<'\n';
    cout<<multime_perechi1;

    return 0;
}
