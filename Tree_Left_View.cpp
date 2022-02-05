#include <iostream>
#include <string>
using namespace std;
typedef struct bnode
{
    struct bnode* lchild;
    char data;
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


string s;
void create(BTPTR &T)
{char ch;
    if(T==NULL)
    {BTPTR N;
    N=new bnode;
    N->lchild=NULL;
    N->rchild=NULL;
    N->data=s[i];
    i++;
    T=N;
    if(i==1)
    root=T;
    }

    ch=s[i];
    if(ch!='.')
    {create(T->lchild);}
    else
        i++;

    ch=s[i];
    if(ch!='.')
    {create(T->rchild);}
    else
        i++;
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

void leftview(BTPTR T)
{flag=new bnode;
flag->data='-';flag->lchild=NULL;flag->rchild=NULL;
    enqueue(T);enqueue(flag);
   while(q.s!=1)
   {T1=dequeue();
   if(T1->data!='-')
   {cout<<T1->data<<" ";
   if(T1->lchild!=NULL)
    enqueue(T1->lchild);
   else if(T1->rchild!=NULL)
    enqueue(T1->rchild);}
   else
   {enqueue(T1);}
   }

}

int main()
{
    cout<<"Enter tree standard string:";
    cin>>s;
    cout<<"The tree is successfully created!\n";
    create(T);
    T=root;
    cout<<"In-order:";
    inorder(T);

    cout<<"\nPre-order:";
    preorder(T);

    cout<<"\nPost-order:";
    postorder(T);

    cout<<"\n\nLeft view:";
    leftview(T);

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
