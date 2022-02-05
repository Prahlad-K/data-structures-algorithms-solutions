#include <iostream>
#include <string>
using namespace std;
typedef struct bnode
{
    struct bnode* lchild;
    char data;
    int level;
    struct bnode* rchild;

}*BTPTR;
BTPTR T=NULL,root=NULL;int i=0,j=0;int ctr=0;

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
int x=0;
void levelify(BTPTR &T)
{
    if(T!=NULL)
    {
        T->level=x;
        if(T->lchild!=NULL)
        {x=T->level;
        T->lchild->level=--x;
        levelify(T->lchild);}
        if(T->rchild!=NULL)
        {x=T->level;
        T->rchild->level=++x;
        levelify(T->rchild);}


    }

}

BTPTR flag,T1;int f=0;
void level_order(BTPTR T)
{
    flag=new bnode;
    flag->data='-';flag->lchild=NULL;flag->rchild=NULL;
    enqueue(T);enqueue(flag);
   while(q.s!=1)
   {T1=dequeue();
   if(T1->data!='-')
   {
   if(T1->level==j||T1->level==(-1)*j)
    {cout<<T1->data<<" ";f=1;}

   if(T1->lchild!=NULL)
    enqueue(T1->lchild);
   if(T1->rchild!=NULL)
    enqueue(T1->rchild);}
   else
   {enqueue(T1);
   if(f==1)
    {j++;f=0;}
   }
   }
}

void printlevel(BTPTR T)
{
    if(T!=NULL)
    {
        printlevel(T->lchild);
        cout<<T->level<<T->data<<" ";
        printlevel(T->rchild);
    }

}

int main()
{
    cout<<"Enter tree standard string:";
    cin>>s;
    cout<<"The tree is successfully created!\n";
        create(T);
    levelify(T);
    T=root;
    printlevel(T);
    T=root;cout<<endl;
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
