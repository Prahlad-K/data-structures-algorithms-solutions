#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct bnode
{int data;
struct bnode* lchild;
struct bnode* rchild;
}*BTPTR;

vector <BTPTR> v;
queue<BTPTR> q;
BTPTR flag,T1;

void level_order(BTPTR T)
{flag=new bnode;
flag->data='-';flag->lchild=NULL;flag->rchild=NULL;
    q.push(T);q.push(flag);
   while(q.size()!=1)
   {T1=q.front();
   q.pop();
   if(T1->data!='-')
   {cout<<T1->data<<" ";
   if(T1->lchild!=NULL)
     q.push(T1->lchild);
   if(T1->rchild!=NULL)
    q.push(T1->rchild);}
   else
   {q.push(T1);cout<<"\n";}
   }
}

int p=0;
void fibonacci()
{
    while(v.size()!=1)
    {BTPTR a,b,T;
        a=v[0];
        v.erase(v.begin());
        b=a->lchild;
        v.erase(v.begin(),v.begin()+b->data);
        T=new bnode;
        T->lchild=a;
        T->rchild=b;
        T->data=a->data+b->data;
        v.insert(v.begin(),T);
    }
    level_order(v[0]);
}

int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;

    BTPTR t1;
    t1=new bnode;
    t1->data=2;
    t1->lchild=new bnode;
    t1->rchild=new bnode;
    t1->lchild->data=1;
    t1->lchild->lchild=NULL;
    t1->lchild->rchild=NULL;

    t1->rchild->data=1;
    t1->rchild->lchild=NULL;
    t1->rchild->rchild=NULL;

BTPTR temp;
    v.push_back(t1);
    for(int i=0;i<n-2;i++)
    {
    temp=new bnode;
    temp->data=1;
    temp->lchild=NULL;
    temp->rchild=NULL;
    v.push_back(temp);
    }
    fibonacci();
}
