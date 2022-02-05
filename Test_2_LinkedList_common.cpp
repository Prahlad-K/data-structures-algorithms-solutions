#include <iostream>
#include <cstddef>
using namespace std;
typedef struct lnode{
int data;
struct lnode *next;}*lptr;
lptr L1,L2,head1,head2;

struct stack
       {int top=-1;
       lptr elements[20];
       }s1,s2;
int stkmt(int t);
void push(lptr x,int t);
lptr pop(int t);
lptr peep(int t);

void make_common(lptr& L1,lptr& L2,int pos)
{L1=head1;L2=head2;
for(int i=1;i<pos;i++)
{L1=L1->next;}

while(L2->next!=NULL)
{L2=L2->next;}

L2->next=L1;

}

void addend(int k,lptr& L,int t)
{lptr T;
    if(L==NULL)
    {L=new lnode;
    L->data=k;
    if(t==1)
    head1=L;
    else
    head2=L;
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

void print(lptr& L,int t)
{if(t==1)
L=head1;
else
L=head2;
    while(L!=NULL)
    {cout<<L->data<<" ";
    L=L->next;}
}

int main()
{char ch; int x,s=0;
cout<<"Enter1?:";
cin>>ch;
while(ch!='n')
{cout<<"Enter number:";
cin>>x;
addend(x,L1,1);
s++;
cout<<"Enter?:";
cin>>ch;
}
cout<<"Enter2?:";
cin>>ch;
while(ch!='n')
{cout<<"Enter number:";
cin>>x;
addend(x,L2,2);
s++;
cout<<"Enter?:";
cin>>ch;
}
int pos;
cout<<"Enter the common element position:";
cin>>pos;

make_common(L1,L2,pos);
print(L1,1);cout<<"\n";
print(L2,2);
L1=head1;L2=head2;
while(L1!=NULL)
{push(L1,1);L1=L1->next;}
while(L2!=NULL)
{push(L2,2);L2=L2->next;}
L1=head1;L2=head2;
lptr temp1,temp2;
while(stkmt(1)!=1||stkmt(2)!=1)
{if(peep(1)==peep(2))
{pop(1);pop(2);}
if(peep(1)!=peep(2))
{temp1=pop(1);temp2=pop(2);
if(temp1->next==temp2->next)
{cout<<"Common element found!:";
cout<<temp1->next->data;break;}}
}

}

void push(lptr x,int t)
{   if(t==1)
    s1.elements[++s1.top]=x;
    if(t==2)
    s2.elements[++s2.top]=x;}

lptr pop(int t)
{if(t==1)
    return s1.elements[s1.top--];
if(t==2)
    return s2.elements[s2.top--];
}

lptr peep(int t)
{if(t==1)
    return s1.elements[s1.top];
if(t==2)
    return s2.elements[s2.top];
}

int stkmt(int t)
{if(t==1)
{if(s1.top==-1)
return 1;
else
return 0;}
else
{if(s2.top==-1)
return 1;
else
return 0;}
}


