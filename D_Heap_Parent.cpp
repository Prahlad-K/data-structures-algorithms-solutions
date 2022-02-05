#include <iostream>
#include <queue>
using namespace std;

typedef struct dhnode
{int data;
struct dhnode* *cptr;
struct dhnode* parent;
}*DHPTR;
DHPTR T=NULL,root=NULL,P=NULL;int d;
int p=0;queue <DHPTR> q;
void create(DHPTR &T)
{int temp;
if(T==NULL)
{DHPTR N;
N=new dhnode;
cout<<"Enter number:";
cin>>N->data;
N->cptr=new DHPTR[d];
for(int j=0;j<d;j++)
    N->cptr[j]=NULL;
    N->parent=NULL;
T=N;
p++;
if(p==1)
    root=T;
q.push(T);
}
else
{P=q.front();q.pop();
if(P!=NULL)
{for(int i=0;i<d;i++)
{T=new dhnode;
cout<<"Enter number:";
cin>>T->data;

P=T->parent;
P->cptr[i]=T;
while(P!=NULL)
{
if(T->data<P->data)
{temp=T->data;
T->data=P->data;
P->data=temp;
}
else
q.push(T);
P=P->parent;}
}
}
}
}

void inorder(DHPTR D)
{
    if(D!=NULL)
    {
      for(int i=0;i<d;i++)
      {inorder(D->cptr[i]);
      cout<<D->data<<" ";}
    }

}

int main()
{int n;char ch;DHPTR heap=NULL;
cout<<"Enter d value:";
cin>>d;
cout<<"Enter?:";
cin>>ch;
while(ch!='n')
{create(heap);
cout<<"Enter?:";
cin>>ch;
heap=root;}
inorder(heap);
}
