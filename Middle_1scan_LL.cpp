#include <iostream>
#include <cstddef>
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
L=head;
int ctr=0;
if(s%2!=0)
{while(ctr!=(s-1)/2)
{L=L->next;ctr++;}
cout<<L->data<<" is the middle element.";}
else
{while(ctr!=s/2-1)
{L=L->next;ctr++;}
cout<<L->data<<" and "<<L->next->data<<" are the middle elements.";}
}//single scan
