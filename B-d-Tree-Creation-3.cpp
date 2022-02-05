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

typedef struct binarynode
{
    int data;
    BTPTR lchild;
    BTPTR rchild;
}*BPTR;

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

void rightredis(BTPTR T,int k)
{BTPTR P=T->parent;

int i=0;
while(i<P->count+1)
{ if(P->ptr[i]==T)
        break;
        i++;
}
BTPTR right=P->ptr[i+1];
cout<<right->key[0]<<" is right."<<endl;
int n=T->count+right->count+2;
int a[n];
a[0]=k;
int j=1;
while(j<n)
{
for(int i=0;i<T->count;i++)
a[j++]=T->key[i];

a[j++]=P->key[i];

for(int i=0;i<right->count;i++)
a[j++]=right->key[i];
}
sortnode(a,n);
for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<endl;
//putting back to nodes.
for(int i=0;i<T->count;i++)
T->key[i]=a[i];

P->key[i]=a[T->count];

for(int i=0;i<right->count;i++)
right->key[i]=a[i+T->count+1];

right->key[right->count]=a[n-1];
right->count++;
}

bool checkright(BTPTR T)
{BTPTR P=T->parent;
int i=0;
while(i<P->count+1)
{ if(P->ptr[i]==T)
        break;
        i++;
}

if(i!=P->count&&P->ptr[i+1]!=NULL&&P->ptr[i+1]->count!=2*d)
    return true;
else
    return false;

}

void leftredis(BTPTR T,int k)
{BTPTR P=T->parent;

int i=0;
while(i<P->count+1)
{ if(P->ptr[i]==T)
        break;
        i++;
}
BTPTR left=P->ptr[i-1];
cout<<left->key[0]<<" is left."<<endl;
int n=T->count+left->count+2;
int a[n];
a[0]=k;
int j=1;
for(int i=0;i<left->count;i++)
a[j++]=left->key[i];

a[j++]=P->key[i-1];

for(int i=0;i<T->count;i++)
a[j++]=T->key[i];

sortnode(a,n);
for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<endl;
//putting back to nodes.
for(int i=0;i<left->count+1;i++)
left->key[i]=a[i];

P->key[i-1]=a[left->count+1];

for(int i=0;i<T->count;i++)
T->key[i]=a[i+left->count+2];

left->count++;
}

bool checkleft(BTPTR T)
{BTPTR P=T->parent;
int i=0;
while(i<P->count)
{ if(P->ptr[i]==T)
        break;
        i++;
}

if(i!=0&&P->ptr[i-1]!=NULL&&P->ptr[i-1]->count!=2*d)
    return true;
else
    return false;

}


void sortoverflow(BPTR *O,int n)
{
    BPTR temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(O[i]->data<O[j]->data)
            {temp=O[i];
            O[i]=O[j];
            O[j]=temp;}
        }
    }
}

void overflow(BTPTR T,BPTR k)
{BPTR O[2*d+1];//consists of all binary node structures
for(int i=0;i<2*d+1;i++)
{
    O[i]=new binarynode;
    O[i]->lchild=NULL;
    O[i]->rchild=NULL;
}
BPTR median;

for(int i=0;i<2*d;i++)
{
    O[i]->data=T->key[i];
    O[i]->lchild=T->ptr[i];
    O[i]->rchild=T->ptr[i+1];
}
O[2*d]=k;
//array of binary nodes, ready for sorting.
sortoverflow(O,2*d+1);
median=O[d];
cout<<"Median:"<<median->data<<"\n";
//SPLITTING STARTS.
BTPTR N=new bdnode;
if((T!=root&&!checkright(T)&&!checkleft(T))||T==root)
{for(int i=0;i<d;i++)
{T->key[i]=O[i]->data;}//putting all left values to old node.

for(int i=d;i<2*d;i++)
{T->key[i]=0;T->count--;
T->ptr[i]=NULL;
}
T->ptr[2*d]=NULL;//making remaining key values and pointers to zero.
for(int i=0;i<d-1;i++)
{T->ptr[i]=O[i]->lchild;}
T->ptr[d-1]=O[d-1]->lchild;
T->ptr[d]=O[d-1]->rchild;//putting all left pointers to old node.


N->ptr=new BTPTR[2*d+1];

for(int i=0;i<2*d+1;i++)
{N->ptr[i]=NULL;}

N->parent=T->parent;

for(int i=d+1;i<2*d+1;i++)
{N->key[i-d-1]=O[i]->data;N->count++;}//putting all right values to new node.

for(int i=d+1;i<2*d;i++)
{N->ptr[i-d-1]=O[i]->lchild;}
N->ptr[d-1]=O[2*d]->lchild;
N->ptr[d]=O[2*d]->rchild;//putting all right pointers to new node.



if(T->parent==NULL)
{cout<<"Parent is NULL.\n";
p=0;
create(T->parent,median->data);//creates new root.
cout<<"Parent:"<<T->parent->key[0]<<"\n";
cout<<"Parent count:"<<T->parent->count<<"\n";
T->parent->ptr[0]=T;
T->parent->ptr[1]=N;//Successful.
}

else if(T->parent->count<2*d)
{//literally because of sorting with pointers.
median->lchild=T;
median->rchild=N;
cout<<"Parent isn't NULL.\n";
BTPTR P=T->parent;
BPTR O1[P->count+1];

for(int i=0;i<P->count+1;i++)
{O1[i]=new binarynode;
O1[i]->lchild=NULL;
O1[i]->rchild=NULL;}

for(int i=0;i<P->count;i++)
{O1[i]->data=P->key[i];
O1[i]->lchild=P->ptr[i];
O1[i]->rchild=P->ptr[i+1];}

O1[P->count]=median;
sortoverflow(O1,P->count+1);
int index;
for(int i=0;i<P->count+1;i++)
{P->key[i]=O1[i]->data;
if(O1[i]==median)
    index=i;
}
//most important part
int j=0;
for(int i=0;i<index;i++)
{P->ptr[j++]=O1[i]->lchild;}

P->ptr[j++]=median->lchild;
P->ptr[j++]=median->rchild;

for(int i=index+1;i<P->count+1;i++)
{P->ptr[j++]=O1[i]->rchild;}


P->count++;
}
else
{median->lchild=T;
median->rchild=N;
cout<<"Parent:"<<T->parent->key[0]<<"\n";
cout<<"Parent count:"<<T->parent->count<<"\n";
cout<<"Parent is full, overflow!\n";
overflow(T->parent,median);}
}
else if(checkright(T))
{cout<<"Immediate right key redistribution!\n";
rightredis(T,k->data);}
else
{cout<<"Immediate left key redistribution!"<<endl;
leftredis(T,k->data);}
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
        BPTR K=new binarynode;
        K->data=k;
        K->lchild=NULL;
        K->rchild=NULL;
        overflow(T,K);}}
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
            cout<<T->count<<" "<<T->key[i]<<"\n";//prints count and key value.
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
