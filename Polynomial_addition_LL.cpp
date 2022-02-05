#include <iostream>
#include <cstddef>
#include <cstdlib>
using namespace std;
typedef struct lnode{
int coeff;
int exp;
struct lnode *next;}*lptr;
lptr L1,L2,L3,head1,head2,head3;
void addend(int k,int m,int i)
{lptr T;
    if(i==1)
    {if(L1==NULL)
    {L1=new lnode;
    L1->coeff=k;
    L1->exp=m;
    head1=L1;
    L1->next=NULL;
    }
    else
    {while(L1->next!=NULL)
    {L1=L1->next;}
    T=new lnode;
    T->coeff=k;
    T->exp=m;
    L1->next=T;
    T->next=NULL;}}

    if(i==2)
    {if(L2==NULL)
    {L2=new lnode;
    L2->coeff=k;
    L2->exp=m;
    head2=L2;
    L2->next=NULL;
    }
    else
    {while(L2->next!=NULL)
    {L2=L2->next;}
    T=new lnode;
    T->coeff=k;
    T->exp=m;
    L2->next=T;
    T->next=NULL;}}

    if(i==3)
    {if(L3==NULL)
    {L3=new lnode;
    L3->coeff=k;
    L3->exp=m;
    head3=L3;
    L3->next=NULL;
    }
    else
    {while(L3->next!=NULL)
    {L3=L3->next;}
    T=new lnode;
    T->coeff=k;
    T->exp=m;
    L3->next=T;
    T->next=NULL;}}

}

void print(int i)
{if(i==1)
    {L1=head1;
    while(L1!=NULL)
    {if(L1->next!=NULL)
        cout<<L1->coeff<<"x^"<<L1->exp<<"+";
    else
        cout<<L1->coeff<<"x^"<<L1->exp;
    L1=L1->next;}}
if(i==2)
    {L2=head2;
    while(L2!=NULL)
    {if(L2->next!=NULL)
        cout<<L2->coeff<<"x^"<<L2->exp<<"+";
    else
        cout<<L2->coeff<<"x^"<<L2->exp;
    L2=L2->next;}}
if(i==3)
    {L3=head3;
    while(L3!=NULL)
    {if(L3->next!=NULL)
        cout<<L3->coeff<<"x^"<<L3->exp<<"+";
    else
        cout<<L3->coeff<<"x^"<<L3->exp;
    L3=L3->next;}}
}

int main()
{char ch; int x,y,s1=0,s2=0;
cout<<"Enter?1:";
cin>>ch;
while(ch!='n')
{cout<<"Enter coeff:";
cin>>x;
cout<<"Enter exp:";
cin>>y;
addend(x,y,1);
s1++;
cout<<"Enter?:";
cin>>ch;
}
print(1);
cout<<"\nEnter?2:";
cin>>ch;
while(ch!='n')
{cout<<"Enter coeff:";
cin>>x;
cout<<"Enter exp:";
cin>>y;
addend(x,y,2);
s2++;
cout<<"Enter?:";
cin>>ch;
}
print(2);cout<<"\n";
int c=0;
L1=head1;L2=head2;
while(L1!=NULL)
{while(L2!=NULL)
{if(L1->exp==L2->exp)
{addend(L1->coeff+L2->coeff,L1->exp,3);c++;L2->exp=-1;break;}
L2=L2->next;}
L2=head2;
if(c==0)
addend(L1->coeff,L1->exp,3);
c=0;
L1=L1->next;}


while(L2!=NULL)
{if(L2->exp!=-1)
addend(L2->coeff,L2->exp,3);L2=L2->next;
}

print(3);
}
