#include <iostream>
#include <queue>
using namespace std;

typedef struct gnode
{
char data;
int c;
struct gnode* *cptr;
}*GTPTR;
GTPTR G,root;
int p=0;
queue <GTPTR> q;
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

void level_order(GTPTR G)
{
    GTPTR G1;
    q.push(G);
    GTPTR flag;
    flag =new gnode;
    flag->data='-';
    q.push(flag);
    while(q.size()!=1)
    {G1=q.front();q.pop();
    if(G1->data!='-')
    {cout<<G1->data<<" ";
    for(int i=0;i<G1->c;i++)
    {if(G1->cptr[i]!=NULL)
        q.push(G1->cptr[i]);}
    }
    else
    {cout<<endl;
    q.push(flag);
    }
    }
    q.pop();
}

void print_sub(GTPTR G)
{
    for(int i=0;i<G->c;i++)
    {if(G->cptr[i]!=NULL)
    {level_order(G->cptr[i]);
    cout<<endl<<endl;
    print_sub(G->cptr[i]);}}

}
int main()
{create(G);
G=root;
level_order(G);
cout<<endl<<endl;
print_sub(G);
}
