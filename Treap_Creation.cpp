#include <iostream>
#include <queue>
using namespace std;
typedef struct thnode
{struct thnode* lchild;
char b;
int h;
int x;
struct thnode* rchild;
}*THPTR;
queue <THPTR> q;
THPTR T=NULL,root=NULL,k1=NULL,k2=NULL,k3=NULL,temp;
int p=0,j=0;
void create_treap(THPTR &T,char c,int d)
{
    if(T==NULL)
    {THPTR N;
    N=new thnode;
    N->b=c;
    N->h=d;
    N->lchild=NULL;
    N->rchild=NULL;
    T=N;p++;
    if(p==1)
        root=T;
    }
    else
    {
        if(c<T->b)
            create_treap(T->lchild,c,d);
        if(c>T->b)
            create_treap(T->rchild,c,d);
    }
}
int ctr=0;
void inorder(THPTR T)
{
    if(T!=NULL)
    {
        inorder(T->lchild);
        T->x=ctr;
        ctr+=4;
        inorder(T->rchild);
    }
}

THPTR flag,T1;
void level_order(THPTR T)
{flag=new thnode;
flag->b='-';flag->lchild=NULL;flag->rchild=NULL;
    q.push(T);q.push(flag);
   while(q.size()!=1)
   {T1=q.front();
   q.pop();
   if(T1->b!='-')
   {
    while(j<T1->x)
    {cout<<" ";j++;}
    cout<<T1->b<<"-"<<T1->h;j+=4;
   if(T1->lchild!=NULL)
     q.push(T1->lchild);
   if(T1->rchild!=NULL)
    q.push(T1->rchild);}
   else
   {q.push(T1);cout<<"\n";j=0;}
   }
}

bool check_heap(THPTR T)
{
    if(T!=NULL)
    {if(T->lchild!=NULL)
    {if(T->h>T->lchild->h)
        {temp=T;
        k2=T->lchild;
        return false;}}
    if(T->rchild!=NULL)
    {if(T->h>T->rchild->h)
        {temp=T;
        k2=T->rchild;
        return false;}}
    return(check_heap(T->lchild)&&check_heap(T->rchild));
    }
    else
    {temp=NULL;
    return true;}
}

void givek1(THPTR M)
{
if(M!=NULL)
{
    if(M->lchild!=NULL)
    {if(M->lchild==temp)
    {k1=M;return;}
    else
    givek1(M->lchild);}

    if(M->rchild!=NULL)
    {if(M->rchild==temp)
    {k1=M;return;}
    else
    givek1(M->rchild);}
}}

void balance()
{
    if(k3->lchild!=NULL&&k3->lchild->b==k2->b)
    {k3->lchild=k2->rchild;
    k2->rchild=k3;
    }
    else if(k3->rchild!=NULL&&k3->rchild->b==k2->b)
    {k3->rchild=k2->lchild;
    k2->lchild=k3;
    }

    if(k1!=NULL)
    {if(k1->lchild!=NULL&&k1->lchild->b==k3->b)
    k1->lchild=k2;
     else if(k1->rchild!=NULL&&k1->rchild->b==k3->b)
    k1->rchild=k2;
    }
    else
        root=k2;
}

int main()
{char c,ch;int d;
    do
    {cout<<"Enter data:";
    cin>>c>>d;
    create_treap(T,c,d);
    T=root;

   while(!check_heap(T))
   {
       if(temp->b!=root->b)
       {givek1(root);}

       k3=temp;
       balance();
       k1=NULL;
       T=root;
   }

    cout<<"Continue?:";
    cin>>ch;
    }while(ch!='n');
    T=root;
    inorder(T);
    T=root;
    level_order(T);
}
