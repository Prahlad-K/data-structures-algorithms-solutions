#include <iostream>

using namespace std;
int d;

typedef struct bdnode
{
    int count=0;
    int key[100];
    struct bdnode* *ptr;
    struct bdnode* parent;
}*BTPTR;

typedef struct over
{
    int keyo[101];
    BTPTR *ptr;
}*OPTR;
OPTR O=NULL;
BTPTR T=NULL,root=NULL;
int p=0;

void sortnode(int* a,int n)
{int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]<a[j])
            {temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            }
        }
    }
}
void create(BTPTR&,int);

void findandset(BTPTR &node,BTPTR &T,BTPTR &N,int median)
{
  int i=0;
  while(i<2*d+1)
  {
      if(node->key[i]==median)
        break;
        i++;
  }
  node->ptr[i]=T;
  node->ptr[i+2]=node->ptr[i+1];//Example case.
  node->ptr[i+1]=N;
  if(T->parent==root)
  {T->parent=node;
  root=node;}
}


void overflow(BTPTR T,int k)
{O=new over;
O->ptr=new BTPTR[2*d+2];
for(int i=0;i<2*d+2;i++)
    O->ptr[i]=NULL;
int median;
for(int i=0;i<2*d;i++)
{O->keyo[i]=T->key[i];}

O->keyo[2*d]=k;
sortnode(O->keyo,2*d+1);

median=O->keyo[d];

BTPTR N=new bdnode;
N->ptr=new BTPTR[2*d+1];

for(int i=0;i<2*d+1;i++)
{N->ptr[i]=NULL;}

N->parent=T->parent;

for(int i=0;i<d;i++)
{T->key[i]=O->keyo[i];
}//putting all left values to old node.
for(int i=d;i<2*d;i++)
{T->key[i]=0;T->count--;}//removing leftovers in old node.

for(int i=d+1;i<2*d+1;i++)
{N->key[i-d-1]=O->keyo[i];N->count++;
}//putting all right values to new node

if(T->parent==NULL)
{cout<<"Parent is NULL.\n";
p=0;
create(T->parent,median);
cout<<"Parent:"<<T->parent->key[0]<<"\n";
cout<<"Parent count:"<<T->parent->count<<"\n";
T->parent->ptr[0]=T;
T->parent->ptr[1]=N;
}
else if(T->parent->count<2*d)
{cout<<"Parent isn't NULL.\n";
BTPTR node,P;
node=new bdnode;
node->ptr=new BTPTR[2*d+1];
for(int i=0;i<2*d+1;i++)
 node->ptr[i]=NULL;

P=T->parent;
cout<<P->key[0]<<" is the parent.\n";
cout<<median<<" is the median.\n";
for(int i=0;i<P->count;i++)
{node->key[i]=P->key[i];node->count++;}//keeping all keys to a new node.

for(int i=0;i<2*d+1;i++)
{node->ptr[i]=P->ptr[i];}//keeping all pointers into the new node as it is.

node->key[P->count]=median;node->count++;
sortnode(node->key,node->count);
findandset(node,T,N,median);
}
else
{cout<<"Parent:"<<T->parent->key[0]<<"\n";
cout<<"Parent count:"<<T->parent->count<<"\n";
cout<<"Parent is full, overflow!\n";
overflow(T->parent,median);}
}

void create(BTPTR &T,int k)
{
    if(T==NULL)
    {
        BTPTR N;
        N=new bdnode;
        N->ptr=new BTPTR[2*d+1];
        for(int i=0;i<2*d+1;i++)
            {N->ptr[i]=NULL;}

        if(N->count==0)
        {N->key[0]=k;N->count++;}
        T=N;
        p++;
        if(p==1)
            {T->parent=NULL;root=T;}
    }
    else
    {      int i=0;
            while(i<T->count)
            {if(T->key[i]>k)
             break;
             i++;}
        if(T->ptr[i]==NULL)
        {if(T->count<2*d)
        {T->key[T->count]=k;T->count++;
        sortnode(T->key,T->count);}
        else
        {cout<<"Overflow!\n";
        overflow(T,k);}}
        else
        {T->ptr[i]->parent=T;
        create(T->ptr[i],k);}
        }
}

void inorder(BTPTR T)
{
    if(T!=NULL)
    {
        for(int i=0;i<2*d+1;i++)
        {
            inorder(T->ptr[i]);
            if(T->key[i]!=0)
            cout<<T->count<<" "<<T->key[i]<<"\n";
        }

    }
}
int main()
{
    cout<<"Enter d:";
    cin>>d;
    char ch;int k;
    cout<<"Enter?:";
    cin>>ch;
    while(ch!='n')
    {cout<<"Enter number:";
        cin>>k;
        create(T,k);
        T=root;
    cout<<"Enter?:";
    cin>>ch;
    }
   inorder(T);
}
