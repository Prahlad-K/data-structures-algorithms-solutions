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

void search(int k,int i)
{
    if(i==k)
        {cout<<"Match found!\n";exit(1);}
    else
    {L=L->next;
    if(L==NULL)
    {cout<<"Match not found!\n";exit(1);}
        search(k,L->data);}

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
print();
cout<<"\nEnter number to search:";
cin>>num;
L=head;
search(num,L->data);

}
