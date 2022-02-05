#include <iostream>
#include <cstddef>
#include <cstdlib>
using namespace std;
typedef struct lnode{
int data;
struct lnode *next;}*lptr;
lptr L1,L2,L3,head1,head2,head3;
void addend(int k,int i)
{lptr T;
    if(i==1)
    {if(L1==NULL)
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
    T->next=NULL;}}

    if(i==2)
    {if(L2==NULL)
    {L2=new lnode;
    L2->data=k;
    head2=L2;
    L2->next=NULL;
    }
    else
    {while(L2->next!=NULL)
    {L2=L2->next;}
    T=new lnode;
    T->data=k;
    L2->next=T;
    T->next=NULL;}}

    if(i==3)
    {if(L3==NULL)
    {L3=new lnode;
    L3->data=k;
    head3=L3;
    L3->next=NULL;
    }
    else
    {while(L3->next!=NULL)
    {L3=L3->next;}
    T=new lnode;
    T->data=k;
    L3->next=T;
    T->next=NULL;}}

}

void print(int i)
{if(i==1)
    {L1=head1;
    while(L1->next!=NULL)
    {cout<<L1->data<<" ";
    L1=L1->next;}
    cout<<L1->data;}
if(i==2)
    {L2=head2;
    while(L2->next!=NULL)
    {cout<<L2->data<<" ";
    L2=L2->next;}
    cout<<L2->data;}
if(i==3)
    {L3=head3;
    while(L3->next!=NULL)
    {cout<<L3->data<<" ";
    L3=L3->next;}
    cout<<L3->data;}

}

int main()
{char ch; int x,s1=0,s2=0;
cout<<"Enter?1:";
cin>>ch;
while(ch!='n')
{cout<<"Enter number:";
cin>>x;
addend(x,1);
s1++;
cout<<"Enter?:";
cin>>ch;
}
print(1);
cout<<"\nEnter?2:";
cin>>ch;
while(ch!='n')
{cout<<"Enter number:";
cin>>x;
addend(x,2);
s2++;
cout<<"Enter?:";
cin>>ch;
}
print(2);cout<<"\n";

L1=head1;L2=head2;

int ctr=0;
while(L1!=NULL)
{while(L2!=NULL)
{ if(L1->data==L2->data)
{ctr++;L2->data=-1;}
L2=L2->next;
}L2=head2;
if(ctr>0)
{addend(L1->data,3);
L1->data=-1;}

L1=L1->next;ctr=0;
}L1=head1;//To print intersection
print(3);
cout<<" is the intersection of L1 and L2.\n";

while(L1!=NULL)
{if(L1->data!=-1)
addend(L1->data,3);
L1=L1->next;
}L1=head1;

while(L2!=NULL)
{if(L2->data!=-1)
addend(L2->data,3);
L2=L2->next;
}L2=head2;
lptr L;int temp;
L3=head3;L=L3;
while(L!=NULL)
{while(L3!=NULL)
{if(L->data<L3->data)
{temp=L->data;
L->data=L3->data;
L3->data=temp;}
L3=L3->next;}
L3=head3;
L=L->next;}
print(3);
cout<<" is the sorted union of L1 and L2.\n";

}
