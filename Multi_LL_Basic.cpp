#include <iostream>
using namespace std;
typedef struct mnode *lptr;
struct mnode{
    int tag;
    union u
    {int ch;
     struct mnode *mlink;
    }data;
struct mnode* next;};
int flag=0;
void add(lptr& L)
{lptr T,H,U;H=L;
    int t;
if(L==NULL)
{L=new mnode;
cout<<"Enter tag:";
cin>>t;
L->tag=t;
if(t==0)
{cout<<"Enter number:";
cin>>L->data.ch;L->next=NULL;}
else
{L->data.mlink=NULL;L->next=NULL;
add(L->data.mlink);}}
else
{
while(H->next!=NULL)
    H=H->next;
T=new mnode;
H->next=T;

cout<<"Enter tag:";
cin>>t;
T->tag=t;
if(t==0)
{cout<<"Enter number:";
cin>>T->data.ch;T->next=NULL;}
else if(t==1)
{U=T;U->next=NULL;
T->data.mlink=NULL;T->next=NULL;
add(T->data.mlink);}
else
{add(U->next);}
}
}

void print(lptr &L)
{lptr U;
    if(L==NULL)
{return;}
else if(L->tag==0)
{cout<<L->data.ch<<" ";
print(L->next);}
else if(L->tag==1)
{cout<<"(";flag=1;U=L;U->next=NULL;
print(L->data.mlink);}
else
{if(flag==1)
    cout<<")";
print(U->next);}
}

int main()
{lptr L;L=NULL;char p;int i=0;
do
  {add(L);
  cout<<"Continue?:";
  cin>>p;}while(p!='n');
    cout<<"(";
    print(L);
    cout<<")";
}


