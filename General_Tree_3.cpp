#include <iostream>

using namespace std;

typedef struct lnode* LPTR;
typedef struct gnode
{int data;
LPTR child;
}*GTPTR;

struct lnode
{GTPTR cnode;
LPTR next;
};
char ch;
GTPTR G=NULL,root=NULL;LPTR head;
int p=0;
void create(GTPTR&);

void create_CLL(LPTR &C)
{
    if(C==NULL)
    {LPTR T;
    T=new lnode;
    T->cnode=NULL;
    T->next=NULL;
    create(T->cnode);
    C=T;
    head=C;
    }
    else
    {while(C->next!=NULL)
    {C=C->next;}
    LPTR T;
    T=new lnode;
    T->cnode=NULL;
    T->next=NULL;
    create(T->cnode);
    C->next=T;
    }

}


void create(GTPTR &G)
{
    if(G==NULL)
    {GTPTR N;
    N=new gnode;N->child=NULL;
    cout<<"Enter data:";
    cin>>N->data;
    cout<<"Enter child of "<<N->data<<"?:";
    cin>>ch;
    while(ch!='n')
    {
    create_CLL(N->child);
    N->child=head;
   cout<<"Enter next child of "<<N->data<<"?:";
    cin>>ch;}

    G=N;
    root=G;
    }

}


void print(GTPTR G)
{
    if(G!=NULL)
    {
        cout<<G->data<<" ";
        while(G->child!=NULL)
        {cout<<endl<<"Child of "<<G->data<<":";
        print(G->child->cnode);G->child=G->child->next;}
    }
}


int main()
{
    create(G);
    G=root;
    print(G);
}
