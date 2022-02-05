#include <iostream>
using namespace std;

typedef struct gnode
{struct gnode* fc;
char data;
struct gnode* ns;
}*GTPTR;
GTPTR G,root;
int p=0;char ch,ch1;
void create(GTPTR &G,char k)
{
if(G==NULL)
{GTPTR N;
N=new gnode;
N->data=k;
N->fc=NULL;
N->ns=NULL;
p++;
G=N;
if(p==1)
   root=G;
}
else
{while(G->fc!=NULL)
G=G->fc;
GTPTR N;
N=new gnode;
N->data=k;
N->fc=NULL;
N->ns=NULL;
G->fc=N;
}
cout<<"Enter sibling of "<<G->data<<"?:";
cin>>ch1;
if(ch1!='n')
    {cout<<"Enter data:";
    cin>>k;
        create(G->ns,k);}

cout<<"Enter child of "<<G->data<<"?:";
    cin>>ch;
if(ch!='n')
{   cout<<"Enter data:";
    cin>>k;
    create(G->fc,k);}
}


GTPTR temp;
void print(GTPTR G)
{
  if(G!=NULL)
  {
  cout<<G->data<<endl;
  temp=G;
  if(temp->ns!=NULL)
    {cout<<"Sibling of "<<temp->data<<":";print(temp->ns);}
 if(G->fc!=NULL)
  cout<<"Child of "<<G->data<<":";
  print(G->fc);
  }

}


int main()
{
char d;
    cout<<"Enter data:";
    cin>>d;
    create(G,d);
G=root;
print(G);
}
