#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct bnode
{
    struct bnode* lchild;
    int data;
    struct bnode* rchild;

}*BTPTR;
BTPTR T=NULL,root=NULL;
queue <BTPTR> q;

void Heap_tree(BTPTR &T,int H[],int s,int i)
{
    if(i<s&&H[i]!='-')
    {if(T==NULL)
    {BTPTR N;
    N=new bnode;
    N->data=H[i];
    N->lchild=NULL;
    N->rchild=NULL;
    T=N;
    if(i==1)
    root=T;
    }
    Heap_tree(T->lchild,H,s,2*i);
    Heap_tree(T->rchild,H,s,2*i+1);}
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
   {cout<<T1->data<<" ";
   if(T1->lchild!=NULL)
     q.push(T1->lchild);
   if(T1->rchild!=NULL)
    q.push(T1->rchild);}
   else
   {q.push(T1);cout<<"\n";}
   }
}

void preorder(BTPTR T)
{
    if(T!=NULL)
    {cout<<T->data<<" ";
     preorder(T->lchild);
     preorder(T->rchild);
    }
}

bool check_heap(BTPTR T)
{
    if(T!=NULL)
    {if(T->lchild!=NULL)
    {if(T->data>T->lchild->data)
        return false;}
    if(T->rchild!=NULL)
    {if(T->data>T->rchild->data)
        return false;}
    return(check_heap(T->lchild)&&check_heap(T->rchild));
    }
    else
    return true;
}

void heapify(BTPTR T)
{
    if(T!=NULL)
    {if(T->lchild!=NULL)
    {if(T->data>T->lchild->data)
        swap(T->data,T->lchild->data);}
    if(T->rchild!=NULL)
    {if(T->data>T->rchild->data)
        swap(T->data,T->rchild->data);}
    heapify(T->lchild);
    heapify(T->rchild);
    }
}

BTPTR giveleaf(BTPTR T)
{
    if(T->lchild==NULL&&T->rchild==NULL)
      return T;
    else if(T->lchild!=NULL)
        return(giveleaf(T->lchild));
    else if(T->rchild!=NULL)
        return(giveleaf(T->rchild));
}
BTPTR leaf;
void remove_node(BTPTR R)
{
    if(R!=NULL)
    {
    if(R->lchild!=NULL&&R->lchild->data==leaf->data)
    {R->lchild=NULL;return;}
    if(R->rchild!=NULL&&R->rchild->data==leaf->data)
    {R->rchild=NULL;return;}
    remove_node(R->lchild);
    remove_node(R->rchild);
    }
}

void sortheap(BTPTR T)
{
  while(T->lchild!=NULL||T->rchild!=NULL)
  {cout<<T->data<<" ";
  leaf=giveleaf(T);
  T->data=leaf->data;
  remove_node(root);
  heapify(T);
  }
  if(T->lchild==NULL&&T->rchild==NULL)
    cout<<T->data;
}



int main()
{BTPTR heap=NULL;
       int n;
    cout<<"Enter heap size:"<<endl;
    cin>>n;
    int H[n+1];

   for(int i=1;i<n+1;i++)
    cin>>H[i];

    Heap_tree(T,H,n+1,1);
    T=root;

if(check_heap(T))
{cout<<"YES!"<<endl;heap=root;}
else
{cout<<"NO, therefore heapified."<<endl;
do
{heapify(heap);
heap=root;}while(!check_heap(heap));
}

level_order(heap);cout<<endl;
cout<<"Sorted order:";
sortheap(heap);
}
