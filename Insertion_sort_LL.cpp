#include <iostream>
#include <cstddef>
using namespace std;
typedef struct lnode{
int data;
struct lnode *next;}*lptr;
lptr L,head,S,headS;
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
void addsorted(int k)
{lptr T;
T=new lnode;
T->data=k;
if(headS==NULL||headS->data>=k)
{T->next=headS;
headS=T;
}
else
{S=headS;
while(S->next!=NULL&&S->next->data<k)
    S=S->next;
T->next=S->next;
S->next=T;
}
}


void print()
{S=headS;
    while(S!=NULL)
    {cout<<S->data<<" ";
    S=S->next;}
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
while(L!=NULL)
{addsorted(L->data);
L=L->next;
}
print();
cout<<"is the sorted order.";
}

