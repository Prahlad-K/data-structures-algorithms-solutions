#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct lnode{
int data;
struct lnode *next;}*lptr;
lptr L,head;
void addend(int k)
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

void print()
{L=head;
    while(L!=NULL)
    {cout<<L->data<<" ";
    L=L->next;}
}

int main()
{char ch; int x,s=0;
cout<<"Enter?:";
cin>>ch;
while(ch!='n')
{cout<<"Enter number:";
cin>>x;
addend(x);
s++;
cout<<"Enter?:";
cin>>ch;
}
int num;
cout<<"Enter subsequent sum:";
cin>>num;
lptr L1=head;int sum=0,ctr=0;L=head;
while(L!=NULL)
{
    for(int i=0;i<ctr;i++)
        L1=L1->next;

    while(L1!=NULL)
{sum=sum+L1->data;L1=L1->next;
if(sum==num)
{cout<<"Found.";exit(1);}}

ctr++;
sum=0;
L=L->next;
L1=head;}



}

