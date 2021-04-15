#include <iostream>
#include<stdlib.h>
using namespace std;

class Nod {
    protected:
        int info;
        Nod *next;
        friend class Lista;


    public:
        //constructor de initializare
        Nod(): info(0),next(NULL){}

        //contructor parametrizat
        Nod(int INFO, Nod *urm)
        {
            info=INFO;
            *next=*urm;
        }

        //constructor de copiere
        Nod(const Nod &nod): info(nod.info){
            next= new Nod(*nod.next);
            }

        //destructor
        ~Nod()
        {
            info=0;
            next=NULL;
        }

        //operator de citire
        friend std::istream& operator >>(std::istream& in, Nod& nod);
        //operator afisare
        friend std::ostream& operator <<(std::ostream& out, const Nod& nod);
        //operator "="
        Nod& operator=(const Nod& nod)
        {
            info = nod.info;
            next = nod.next;
            return *this;
        }


};

class Nod_dublu: public Nod
{
        Nod *ante;

    public:

        //constructor de intializare
        Nod_dublu(): Nod(), ante(NULL){}

        //constructor parametrizat
        Nod_dublu(int INFO, Nod *urm, Nod *prev)
            :Nod(INFO, urm), ante(prev){}

        //constructor de copiere
        Nod_dublu(const Nod_dublu &nod_dublu)
        {
            Nod(nod_dublu.info, nod_dublu.next);
            ante=nod_dublu.ante;
        }


        //destructor
        ~Nod_dublu()
        {
            info=0;
            next=NULL;
            ante=NULL;
        }

        //operator de citire
        friend std::istream& operator >>(std::istream& in, Nod_dublu& nod_dublu);
        //operator afisare
        friend std::ostream& operator <<(std::ostream& out, const Nod_dublu& nod_dublu);
        //operator "="
        Nod_dublu& operator=(const Nod_dublu& nod_dublu)
        {
            info = nod_dublu.info;
            next = nod_dublu.next;
            ante = nod_dublu.ante;

            return *this;
        }



};

class Lista
{
    protected:
        Nod *next;


};

class Lista_Circulara: public Lista
{

    public:

        struct Circular_Nod
{
int info;
struct Circular_Nod *next;
};
public:
Circular_Nod *newNod(int info)
{
Circular_Nod *temp = new Circular_Nod;
temp->next = temp;
temp->info = info;
}
public:
void Josephus(int mth_nod, int number)
{
Circular_Nod *cap=newNod(1);
Circular_Nod *prev=cap;
for (int i=2;i<=number;i++)
{
prev->next=newNod(i);
prev=prev->next;
}
prev->next = cap;
Circular_Nod *ptr1 = cap, *ptr2 = cap;
while (ptr1->next != ptr1)
{
// Gaseste al m-lea nod
int count=1;
while(count!= mth_nod)
{
ptr2=ptr1;
ptr1=ptr1->next;
count++;
}
cout<<ptr1->info<<" ";
ptr2->next=ptr1->next;
ptr1=ptr2->next;
}
cout<<ptr1->info<<endl;
}
};
int main()
{
Lista_Circulara obj;
int number;
int mth_nod;
cout<<"n=";
cin>>number;
cout<<"mth_nod=";
cin>>mth_nod;
obj.Josephus(mth_nod, number);
return 0;
}
