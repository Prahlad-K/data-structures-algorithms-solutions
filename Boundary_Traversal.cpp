#include <iostream>
#include <stack>
using namespace std;
typedef struct gnode
{
char data;
int c;
struct gnode* *cptr;
}*GTPTR;
GTPTR G,root;
stack <GTPTR> s;
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

int check_leafl(GTPTR G)
{
    if(G->c==0)
    return -1;
    int ctr=0;
    for(int i=0;i<G->c;i++)
    {
        if(G->cptr[i]==NULL)
           ctr++;
        else
        return ctr;
    }

}

int check_leafr(GTPTR G)
{
    if(G->c==0)
        return -1;
    int ctr=G->c-1;
    for(int i=G->c-1;i>=0;i--)
    {
        if(G->cptr[i]==NULL)
           ctr--;
        else
        return ctr;
    }

}

void print_leaves(GTPTR G)
{
    if(G!=NULL)
    {
      if(G->c==0)
        cout<<G->data<<" ";
      else
      {for(int i=0;i<G->c;i++)
          {if(G->cptr[i]!=NULL)
              print_leaves(G->cptr[i]);}}
    }

}

void boundary(GTPTR G)
{cout<<G->data<<" ";
int l=check_leafl(G);
GTPTR Gleft=G->cptr[l];
while(check_leafl(Gleft)!=-1)
{cout<<Gleft->data<<" ";
l=check_leafl(Gleft);
Gleft=Gleft->cptr[l];
}

print_leaves(G);

int r=check_leafr(G);
GTPTR Gright=G->cptr[r];
while(check_leafr(Gright)!=-1&&Gright!=NULL)
{s.push(Gright);
r=check_leafr(Gright);
Gright=Gright->cptr[r];
}

while(s.size()!=0)
{cout<<s.top()->data<<" ";
s.pop();}
}


int main()
{create(G);
G=root;
boundary(G);
}
