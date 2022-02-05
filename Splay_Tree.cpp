#include <iostream>
#include <queue>

using namespace std;

typedef struct bnode
{
    int data;
    int x;
    struct bnode* lchild;
    struct bnode* rchild;
}*BTPTR;
BTPTR T=NULL,root=NULL,x=NULL;
int ctr=0,j=0,c=0;
queue <BTPTR> q;
void create(BTPTR &T,int k)
{
    if(T==NULL)
    {
        BTPTR N;
        N=new bnode;
        N->lchild=NULL;
        N->rchild=NULL;
        N->data=k;
        T=N;
        ctr++;
        if(ctr==1)
            root=T;
    }
    else
    {
     if(k<T->data)
        create(T->lchild,k);
     else
        create(T->rchild,k);
    }
}

BTPTR search(int s,BTPTR T)
{
if(T!=NULL)
{
    if(s==T->data)
        return T;
    else if(s<T->data)
        search(s,T->lchild);
    else
        search(s,T->rchild);
}

}

BTPTR searchParent(BTPTR T,BTPTR parent)
{
    if(T==root)
        return NULL;
    if(parent!=NULL)
    {
        if(parent->lchild==T||parent->rchild==T)
            return parent;
            if(parent->lchild!=NULL)
            return(searchParent(T,parent->lchild));
            if(parent->rchild!=NULL)
            return(searchParent(T,parent->rchild));
    }
}

void splay(int s)
{
    BTPTR p,g,gg;
    x=search(s,root);
    cout<<x->data<<" is x."<<endl;
    p=searchParent(x,root);
    if(p!=NULL)
    {cout<<p->data<<" is p."<<endl;
        g=searchParent(p,root);
      if(g!=NULL)
      {cout<<g->data<<" is g."<<endl;
          gg=searchParent(g,root);
       if(p->lchild==x&&g->lchild==p)
       {
       p->lchild=x->rchild;
       g->lchild=p->rchild;
       x->rchild=p;
       p->rchild=g;
       }
       else if(p->rchild==x&&g->rchild==p)
       {
       p->rchild=x->lchild;
       g->rchild=p->lchild;
       x->lchild=p;
       p->lchild=g;
       }
       else if(p->rchild==x&&g->lchild==p)
       {
           p->rchild=x->lchild;
           g->lchild=x->rchild;
           x->lchild=p;
           x->rchild=g;
       }
       else if(p->lchild==x&&g->rchild==p)
       {
           p->lchild=x->rchild;
           g->rchild=x->lchild;
           x->rchild=p;
           x->lchild=g;
       }
       if(gg!=NULL)
       {
           if(gg->lchild==g)
           gg->lchild=x;
           else
            gg->rchild=x;
       }
       else
        root=x;
      }
      else
      {
          if(p->lchild==x)
          {p->lchild=x->rchild;
          x->rchild=p;
          root=x;}
          else
          {p->rchild=x->lchild;
          x->lchild=p;
          root=x;}
      }
    }
    else
    {
        root=x;
    }
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
   q.pop();
}

void inorder(BTPTR T)
{
    if(T!=NULL)
    {
        inorder(T->lchild);
        T->x=c++;
        inorder(T->rchild);
    }
}
int main()
{
    char ch='y';int num,s;
    while(ch!='n')
    {
        cout<<"Enter number:";
        cin>>num;
        create(T,num);
        T=root;
        cout<<"Enter?:";
        cin>>ch;
    }
    T=root;
    inorder(T);
    level_order(T);
    cout<<endl;
    cout<<"Splay number:";
    cin>>s;
    while(x!=root)
    {splay(s);}
    level_order(x);
}
