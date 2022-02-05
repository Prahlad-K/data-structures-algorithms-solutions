#include <iostream>
using namespace std;

typedef struct gnode
{
char data;
int c;
struct gnode* *cptr;
}*GTPTR;
GTPTR G,root;
int p=0;
void create(GTPTR &G)
{
if(G==NULL)
{GTPTR N;
N=new gnode;
cout<<"Enter data:";
cin>>N->data;
cout<<"Enter count:(>1):0 means no child:";
cin>>N->c;
N->cptr=new GTPTR[N->c];
for(int i=0;i<N->c;i++)
    N->cptr[i]=NULL;
G=N;p++;
if(p==1)
    root=G;
}
for(int i=0;i<G->c;i++)
    create(G->cptr[i]);
}

void print(GTPTR &G)
{
  if(G!=NULL)
  {
  cout<<G->data<<" ";cout<<endl;
  for(int i=0;i<G->c;i++)
  {cout<<i<<" child:";
      print(G->cptr[i]);
  }
  }

}


int main()
{create(G);
G=root;
print(G);
}
