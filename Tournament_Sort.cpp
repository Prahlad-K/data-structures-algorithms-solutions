#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct bnode
{
int data;
int x=0;
bnode *lchild,*rchild;
}*BTPTR;

vector <BTPTR> v;

queue<BTPTR> q;
BTPTR flag,T1;
int ctr=0,j=0;

void inorder(BTPTR T)
{
    if(T!=NULL)
    {
        inorder(T->lchild);
        T->x=ctr++;
        inorder(T->rchild);
    }
}

void level_order(BTPTR T)
{inorder(T);
    flag=new bnode;
flag->data='-';flag->lchild=NULL;flag->rchild=NULL;
    q.push(T);q.push(flag);
   while(q.size()!=1)
   {T1=q.front();
   q.pop();
   if(T1->data!='-')
   {while(j<T1->x)
   {cout<<" ";j++;}
       cout<<T1->data;j++;
   if(T1->lchild!=NULL)
     q.push(T1->lchild);
   if(T1->rchild!=NULL)
    q.push(T1->rchild);}
   else
   {q.push(T1);cout<<"\n";j=0;}
   }
}


void make_tree()
{BTPTR a,b,T;
    while(v.size()!=1)
    {a=v[0];b=v[1];
    v.erase(v.begin());
    v.erase(v.begin());
    T=new bnode;
    T->lchild=a;
    T->rchild=b;
    T->data=min(a->data,b->data);
    v.push_back(T);
    }
    level_order(v[0]);
}


int main()
{int n;BTPTR temp;
 cout<<"Enter number of elements:";
 cin>>n;
 cout<<"Enter array:";
 for(int i=0;i<n;i++)
 {temp=new bnode;
 cin>>temp->data;
 temp->lchild=NULL;
 temp->rchild=NULL;
 v.push_back(temp);
 }
 make_tree();

}
