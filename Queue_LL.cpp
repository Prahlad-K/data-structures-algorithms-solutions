#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct lnode{
int data;
struct lnode *next;}*lptr;
lptr L,head,rear;
void addend(int k)
{lptr T;
    if(L==NULL)
    {L=new lnode;
    L->data=k;
    head=L;
    rear=L;
    L->next=NULL;
    }
    else
    {T=new lnode;
    T->data=k;
    rear->next=T;
    rear=T;
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
{int k;
    L=head;
    while((L->next)->next!=NULL)
    {L=L->next;}
k=(L->next)->data;
L->next=NULL;
L=head;
return k;
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
cout<<"Enqueue elements into queue?:";
cin>>ch;
while(ch!='n')
{cout<<"Enter number:";
cin>>x;
addend(x);//equivalent of enqueue
s++;
cout<<"Enter?:";
cin>>ch;
}
cout<<"There are "<<s<<" elements in queue.\n";
cout<<"Do you want to know front element?:";
cin>>ch;
while(ch!='n')
{cout<<front()<<"\n";
cout<<"Do you want to know front element?:";
cin>>ch;
}
cout<<"Do you want to dequeue?:";
cin>>ch;
while(ch!='n'&&s>0)
{cout<<deletefront()<<"\n";s--;//equivalent of dequeue
cout<<"Do you want to dequeue?:";
cin>>ch;
}
}







