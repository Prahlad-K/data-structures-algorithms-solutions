#include <iostream>
#include <string>
using namespace std;
typedef struct bnode
{
    struct bnode* lchild;
    int data;
    struct bnode* rchild;

}*BTPTR;
BTPTR T=NULL,root=NULL;int i=0;

int k;
void create(BTPTR &T,int k)
{
    if(T==NULL)
    {BTPTR N;
    N=new bnode;
    N->lchild=NULL;
    N->rchild=NULL;
    N->data=k;
    i++;
    T=N;
    if(i==1)
    root=T;
    }
    else
    {
    if(k<T->data)
    {create(T->lchild,k);}
    if(k>T->data)
    {create(T->rchild,k);}}
}

int *elem,ctr=0;

void inorder(BTPTR T)
{if(T!=NULL)
{inorder(T->lchild);
elem[ctr++]=T->data;
cout<<T->data<<" ";
inorder(T->rchild);
}
}

int sum(int index)
{int ans=0;
for(int i=index;i<ctr;i++)
    ans=ans+elem[i];
return ans;
}

int ctr1=0;
void modify(BTPTR T)
{
    if(T!=NULL)
    {modify(T->lchild);
    T->data=sum(ctr1++);
    modify(T->rchild);
    }
}


int main()
{elem=new int;int num;char ch;
    do
    {
    cout<<"Enter number:";
    cin>>num;
    create(T,num);
     T=root;
    cout<<"Continue?:";
    cin>>ch;
    }while(ch!='n');

    T=root;
    cout<<"\nInorder:";
    inorder(T);

    cout<<"\n";

    T=root;
    modify(T);
    ctr=0;ctr1=0;
    cout<<"\nInorder after modifying:";
    T=root;
    inorder(T);
}
