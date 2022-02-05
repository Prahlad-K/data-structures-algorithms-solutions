#include <iostream>
#include <cstddef>
using namespace std;
typedef struct lnode{
int data;
struct lnode *next;}*lptr;
lptr L1,L2,head1,head2;
void addend(int k)
{lptr T;
    if(L1==NULL)
    {L1=new lnode;
    L1->data=k;
    head1=L1;
    L1->next=NULL;
    }
    else
    {while(L1->next!=NULL)
    {L1=L1->next;}
    T=new lnode;
    T->data=k;
    L1->next=T;
    T->next=NULL;}
}

void print()
{L1=head1;
    while(L1!=NULL)
    {cout<<L1->data<<" ";
    L1=L1->next;}
}

int main()
{char ch; int x,s=0;
cout<<"Enter?:";
cin>>ch;
while(ch!='n')
{cout<<"Enter numbers:";
cin>>x;
addend(x);
s++;
cout<<"Enter?:";
cin>>ch;
}

L1=head1;
lptr L=head1;
int temp;
while(L1!=NULL)
{
    while(L!=NULL)
    {if(L1->data<L->data)
    {temp=L1->data;
    L1->data=L->data;
    L->data=temp;}
    L=L->next;}
    L=head1;
L1=L1->next;}

print();
}
