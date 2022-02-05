#include <iostream>
using namespace std;
typedef struct mlnode *mptr;
union u
{int data;
mptr link;
};

typedef struct mlnode{
int tag;
union u d;
}*mptr;
int p,t,ctr=0;mptr root;char ch;
void create(mptr& M)
{cout<<"Enter?:";
cin>>ch;
if(ch!='n')
    {if(M==NULL)
    {cout<<"Enter tag:";
    cin>>t;
    mptr N;
    N=new mlnode;

    if(t==0)
    {cout<<"Enter data:";
    cin>>p;
    N->d.data=p;
    N->tag=0;
    M=N;
    N->d.link=NULL;
        ctr++;
        if(ctr==1)
        root=M;
    create(M->d.link);}
    else
    {N->d.link=NULL;
    N->tag=1;
        ctr++;
        if(ctr==1)
        root=M;
        M=N;create(M->d.link);}

    }}
}

void print(mptr M)
{
    if(M!=NULL)
        {if(M->tag==0)
            cout<<M->d.data<<" ";
    print(M->d.link);}

}

int main()
{mptr M=NULL;
create(M);
print(M);
}
