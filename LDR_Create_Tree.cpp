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
string pre;
int ctr,flag=0;

int giveind(int i,string in)
{char ch=pre[i];
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
create(T->lchild,l,++index);
create(T->rchild,r,++index);
}
}


void inorder(BTPTR T)
{if(T!=NULL)
{inorder(T->lchild);
cout<<T->data<<" ";
inorder(T->rchild);
}
}

int main()
{string in;
    cout<<"Enter inorder:";
    cin>>in;
    cout<<"Enter preorder:";
    cin>>pre;
    create(T,in,0);
    cout<<"Tree has been created successfully!";
    cout<<"\nInorder:";
    T=root;
    inorder(T);
}
