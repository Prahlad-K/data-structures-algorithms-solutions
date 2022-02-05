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

struct queue{
int s=0;
int f=-1;
int r=-1;
BTPTR a[30];
}q;
int qempty();
BTPTR dequeue();
void enqueue(BTPTR);

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

void inorder(BTPTR T)
{if(T!=NULL)
{inorder(T->lchild);
cout<<T->data<<" ";
inorder(T->rchild);
}
}
void preorder(BTPTR T)
{if(T!=NULL)
{cout<<T->data<<" ";
preorder(T->lchild);
preorder(T->rchild);
}
}

void postorder(BTPTR T)
{if(T!=NULL)
{postorder(T->lchild);
postorder(T->rchild);
cout<<T->data<<" ";
}
}
BTPTR flag,T1;
void level_order(BTPTR T)
{flag=new bnode;
flag->data='-';flag->lchild=NULL;flag->rchild=NULL;
    enqueue(T);enqueue(flag);
   while(q.s!=1)
   {T1=dequeue();
   if(T1->data!='-')
   {cout<<T1->data<<" ";
   if(T1->lchild!=NULL)
    enqueue(T1->lchild);
   if(T1->rchild!=NULL)
    enqueue(T1->rchild);}
   else
   {enqueue(T1);cout<<"\n";}
   }

}


int main()
{int num;char ch;
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
    T=root;
    cout<<"\nPreorder:";
    preorder(T);
    T=root;
    cout<<"\nPostorder:";
    postorder(T);
    cout<<"\n";
    level_order(T);
}
int qempty()
{
    if(q.f==-1)
        return 1;
    else
        return 0;
}

void enqueue(BTPTR x)
{
    if(qempty()==1)
{q.f=0;q.r=0;}

if(qempty()!=1)
    {q.a[q.r]=x;
    q.r=(q.r+1)%30;q.s++;}
}

BTPTR dequeue()
{int k;BTPTR temp;temp=NULL;
    if(qempty()==1)
        return temp;
    else
    {k=q.f;
    q.f=(q.f+1)%30;q.s--;
    return q.a[k];}
}
