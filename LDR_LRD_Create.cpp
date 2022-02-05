#include <iostream>
#include <string>
using namespace std;
typedef struct bnode
{
    struct bnode* lchild;
    string data;
    struct bnode* rchild;

}*BTPTR;
BTPTR T=NULL,root=NULL;
string pos;
int ctr,flag=0;

int giveind(int i,string in)
{char ch=pos[i];
for(int j=0;j<in.length();j++)
{if(ch==in[j])
return j;}}

void split(string in,int ctr,string &l,string &r)
{
l=in.substr(0,ctr);

r=in.substr(ctr+1,in.length()-(ctr+1));

}

void create(BTPTR &T,string in,int index)
{string l,r;
if(in.length()!=0)
{if(T==NULL)
{ctr=giveind(index,in);
BTPTR N=new bnode;
N->data=in.substr(ctr,1);
N->lchild=NULL;
N->rchild=NULL;
split(in,ctr,l,r);
flag++;
T=N;
if(flag==1)
root=T;
}
create(T->lchild,l,--index);
create(T->rchild,r,--index);
}
}


void preorder(BTPTR T)
{if(T!=NULL)
{cout<<T->data<<" ";
preorder(T->lchild);
preorder(T->rchild);
}
}

int main()
{string in;
    cout<<"Enter inorder:";
    cin>>in;
    cout<<"Enter postorder:";
    cin>>pos;
    create(T,in,pos.length()-1);
    cout<<"Tree has been created successfully!";
    cout<<"\nPreorder:";
    T=root;
    preorder(T);
}
