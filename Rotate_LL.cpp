#include <iostream>
#include <cstddef>
using namespace std;
typedef struct lnode{
int data;
struct lnode *next;}*lptr;
lptr L,head;

void addend(int k,lptr& L)
{lptr T;
    if(L==NULL)
    {L=new lnode;
    L->data=k;
    head=L;
    L->next=NULL;
    }
    else
    {while(L->next!=NULL)
    {L=L->next;}
    T=new lnode;
    T->data=k;
    L->next=T;
    T->next=NULL;}
}

void print(lptr L)
{  L=head;
    while(L!=NULL)
    {cout<<L->data<<" ";
    L=L->next;}
}

void rot_LL(lptr L,int k)
{lptr mark,tmark;
    int ctr=1;
    while(ctr<k)
    {ctr++;
    L=L->next;}
    mark=L->next;
    L->next=NULL;
    tmark=mark;
    while(tmark->next!=NULL)
        tmark=tmark->next;
    tmark->next=head;
    head=mark;
}

int main()
{char ch; int x,s=0,k;
cout<<"Enter?:";
cin>>ch;
while(ch!='n')
{cout<<"Enter number:";
cin>>x;
addend(x,L);
s++;
cout<<"Enter?:";
cin>>ch;
}
print(L);
cout<<"\nEnter k:";
cin>>k;
L=head;
rot_LL(L,k);
L=head;
cout<<"\n";
print(L);
}
