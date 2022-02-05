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
void addfront(int k)
{L=head;
lptr T;
T=new lnode;
T->data=k;
T->next=L;
head=T;
L=head;
}

int deleteend()
{L=head;
    while((L->next)->next!=NULL)
    {L=L->next;}
return (L->next)->data;
L->next=NULL;
L=head;
}

int deletefront()
{int k;
L=head;
if(L!=NULL)
{k=L->data;
head=L->next;
L=head;
return k;}
}
int front()
{L=head;
return L->data;
}

void print()
{L=head;
while(L!=NULL)
{cout<<L->data<<" ";
L=L->next;}
}

int main()
{char ch; int x,s=0;
cout<<"Push elements into stack?:";
cin>>ch;
while(ch!='n')
{cout<<"Enter number:";
cin>>x;
addfront(x);//equivalent of push
s++;
cout<<"Enter?:";
cin>>ch;
}
cout<<"There are "<<s<<" elements in stack.\n";
cout<<"Do you want to know top element?:";
cin>>ch;
while(ch!='n')
{cout<<front()<<"\n";
cout<<"Do you want to know top element?:";
cin>>ch;
}

cout<<"Do you want to pop?:";
cin>>ch;
while(ch!='n'&&s>0)
{cout<<deletefront()<<"\n";s--;//equivalent of pop
cout<<"Do you want to pop?:";
cin>>ch;
}


}







