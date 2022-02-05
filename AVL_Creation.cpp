#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;
typedef struct bnode
{    struct bnode* lchild;
    int data,x;
    struct bnode* rchild;
}*BTPTR;
BTPTR T=NULL,root=NULL;int i=0,j=0;BTPTR k1,kp1=NULL,k2,k3;
queue <BTPTR> q;stack <BTPTR> s;
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
    k2=T;
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
int ctr=0;
void inorder(BTPTR T)
{
    if(T!=NULL)
    {inorder(T->lchild);
    T->x=ctr++;
    inorder(T->rchild);}
}

BTPTR flag,T1;
void level_order(BTPTR T)
{flag=new bnode;
flag->data='-';flag->lchild=NULL;flag->rchild=NULL;
    q.push(T);q.push(flag);
   while(q.size()!=1)
   {T1=q.front();
   q.pop();
   if(T1->data!='-')
   {
    while(j<T1->x)
    {cout<<" ";j++;}
    cout<<T1->data<<" ";j++;
   if(T1->lchild!=NULL)
     q.push(T1->lchild);
   if(T1->rchild!=NULL)
    q.push(T1->rchild);}
   else
   {q.push(T1);cout<<"\n";j=0;}
   }
}

int height(BTPTR T)
{
    if(T==NULL)
        return -1;
    else
    {
        return(max(height(T->lchild),height(T->rchild))+1);
    }

}


bool balance_check(BTPTR T)
{
if(T!=NULL)
{
if(abs(height(T->lchild)-height(T->rchild))>=2)
    {if(height(T)==2)
        {k1=T;
    return false;}
    else if(height(T)>2)
        kp1=T;
        return(balance_check(T->lchild)&&balance_check(T->rchild));}
else
{return(balance_check(T->lchild)&&balance_check(T->rchild));}
}
else
return true;
}
int f=0;
void balance()
{
    if(k1->lchild!=NULL)
    {if(k1->lchild->lchild!=NULL)
    {if(k2->data==k1->lchild->lchild->data)
    {k3=k1->lchild;
    k1->lchild=k3->rchild;
    k3->rchild=k1;
    }}
    else
    {if(k2->data==k1->lchild->rchild->data)
    {k3=k1->lchild;
    k3->rchild=k2->lchild;
    k1->lchild=k2->rchild;
    k2->lchild=k3;
    k2->rchild=k1;f=1;
    }}}

    if(k1->rchild!=NULL)
    {if(k1->rchild->rchild!=NULL)
    {if(k2->data==k1->rchild->rchild->data)
    {k3=k1->rchild;
    k1->rchild=k3->lchild;
    k3->lchild=k1;
    }}
    else
    {if(k2->data==k1->rchild->lchild->data)
    {k3=k1->rchild;
    k1->rchild=k2->lchild;
    k3->lchild=k2->rchild;
    k2->lchild=k1;
    k2->rchild=k3;f=1;
    }}}

    if(kp1!=NULL)
    {if(kp1->lchild!=NULL&&kp1->lchild==k1)
        {if(f==0)
        kp1->lchild=k3;
        else if(f==1)
        kp1->lchild=k2;}
     else if(kp1->rchild!=NULL&&kp1->rchild==k1)
        {if(f==0)
        kp1->rchild=k3;
        else if(f==1)
        kp1->rchild=k2;}}
    else
        {if(f==0)
            root=k3;
        else if(f==1)
            root=k2;}
}

int main()
{int num;char ch;
    do
    {
    cout<<"Enter number:";
    cin>>num;
    T=root;
    create(T,num);
    if(!balance_check(T))
     {balance();}
    cout<<"Continue?:";
    cin>>ch;
    }while(ch!='n');
    T=root;
    inorder(T);
    T=root;
    level_order(T);
    cout<<"\n";
}
