#include <iostream>
#include <queue>
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

void delete_num(int num);

queue <BTPTR> q;

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

void parentize(BTPTR T)
{
    if(T!=NULL)
    {
        for(int i=0;i<T->count+1;i++)
            {if(T->ptr[i]!=NULL)
                T->ptr[i]->parent=T;
            parentize(T->ptr[i]);}
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
{median->lchild=T;
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
overflow(T->parent,median);
int i=0;
if(k->data>median->data)
    T->parent=T->parent->parent->ptr[1];
else
    T->parent=T->parent->parent->ptr[0];

for(int i=0;i<T->parent->count+1;i++)
{
    T->parent->ptr[i]->parent=T->parent;
}
parentize(root);
}
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

void level_order(BTPTR T)
{
    q.push(T);
    BTPTR flag;
    flag=new bdnode;
    flag->ptr=new BTPTR[2*d+1];
    flag->key[0]='-';
    for(int i=0;i<2*d+1;i++)
    {flag->ptr[i]=NULL;}

    q.push(flag);BTPTR T1;

    while(q.size()!=1)
    {T1=q.front();
    q.pop();
    if(T1->key[0]!='-')
    {
        for(int i=0;i<T1->count;i++)
        {
            if(i!=T1->count-1)
            {if(T1->key[i]!=0)
            cout<<T1->key[i]<<"|";}
            else
            {if(T1->key[i]!=0)
            cout<<T1->key[i]<<"  ";}
        }

        for(int i=0;i<2*d+1;i++)
        {
            if(T1->ptr[i]!=NULL)
                q.push(T1->ptr[i]);
        }
    }
    else
    {    cout<<endl;
        q.push(T1);}

    }
        q.pop();
}

BTPTR search_node(BTPTR T,int n)
{
if(T!=NULL)
{int i=0;
while(i<T->count)
{
    if(n==T->key[i])
        return T;
    else if(n<T->key[i])
        break;
    i++;
}
if(i==T->count)
    {
        if(T->ptr[i]==NULL)
           return NULL;
        else
            search_node(T->ptr[i],n);
    }
else
search_node(T->ptr[i],n);
}

}

bool isleaf(BTPTR T)
{
int i=0;
while(i<T->count+1)
{
    if(T->ptr[i]!=NULL)
        return false;
        i++;
}
if(i==T->count+1)
    return true;
}
int flag=0;
void nodecombining(BTPTR node,int num)
{BTPTR P=node->parent;
int i=0;
while(i<P->count+1)
{
    if(P->ptr[i]==node)
        break;
    i++;
}
int index=0;
BPTR median=new binarynode;

median->lchild=NULL;
median->rchild=NULL;

BPTR O[10];
for(int i=0;i<10;i++)
{
    BPTR N=new binarynode;
    N->lchild=NULL;
    N->rchild=NULL;
    O[i]=N;
}

//When combining with the right node.(your node is at left to this.)
if(P->ptr[i+1]!=NULL)
{median->data=P->key[i];
    int k=0;
for(int j=0;j<node->count;j++)
{
    if(node->key[j]!=num)
    {O[k]->data=node->key[j];
    O[k]->lchild=node->ptr[j];
    O[k++]->rchild=node->ptr[j+1];}
}

BTPTR right=P->ptr[i+1];
median->lchild=O[k-1]->rchild;
O[k++]=median;
for(int j=0;j<right->count;j++)
{
    O[k]->data=right->key[j];
    O[k]->lchild=right->ptr[j];
    O[k++]->rchild=right->ptr[j+1];
}
sortoverflow(O,k);
cout<<"k:"<<k<<endl;
int s=k;
k=0;
for(int j=0;j<s;j++)
{
    node->key[j]=O[k]->data;
    node->ptr[j]=O[k++]->lchild;
}
node->ptr[s]=O[s-1]->rchild;
node->count=node->count+s-right->count;
right->count=0;
P->ptr[i+1]=NULL;
P->ptr[i]=node;
flag=1;
cout<<"Let's try and print:\n";
level_order(root);
cout<<endl;
delete_num(median->data);
flag=0;
parentize(root);
}
//When combining with the left node.(your node is at right to this.)
else if(P->ptr[i-1]!=NULL)
{median->data=P->key[i-1];
    int k=0;
BTPTR left=P->ptr[i-1];
for(int j=0;j<left->count;j++)
{
    O[k]->data=left->key[j];
    O[k]->lchild=left->ptr[j];
    O[k++]->rchild=left->ptr[j+1];
}
for(int j=0;j<node->count;j++)
{
    if(node->key[j]!=num)
    {O[k]->data=node->key[j];
    O[k]->lchild=node->ptr[j];
    O[k++]->rchild=node->ptr[j+1];}
}
median->lchild=O[k-1]->rchild;
O[k++]=median;
sortoverflow(O,k);
cout<<"k:"<<k<<endl;
int s=k;
k=0;
for(int j=0;j<s;j++)
{
    node->key[j]=O[k]->data;
    node->ptr[j]=O[k++]->lchild;
}
node->ptr[s]=O[s-1]->rchild;
node->count=node->count+s-left->count;
left->count=0;
P->ptr[i-1]=NULL;
P->ptr[i]=node;
flag=1;
cout<<"Let's try and print:\n";
level_order(root);
cout<<endl;
delete_num(median->data);
flag=0;
parentize(root);
}
}

void underflow(BTPTR T,int num)
{
    BTPTR P=T->parent;
    int i=0;
    while(i<P->count+1)
    {if(T==P->ptr[i])
    break;
        i++;}
    if(flag!=1&&P->ptr[i+1]!=NULL&&P->ptr[i+1]->count>d)
    {cout<<"Immediate right key redistribution!\n";
     BTPTR right=P->ptr[i+1];
     int a[T->count+1+right->count];
     int j=0;
     for(int k=0;k<T->count;k++)
     a[j++]=T->key[k];
     a[j++]=P->key[i];
     for(int k=0;k<right->count;k++)
     a[j++]=right->key[k];
     //stored all keys into an array.
     int k=0;
     while(k<j)
    {if(a[k]==num)
           break;
    k++;}
    for(int k1=k+1;k1<j;k1++)
        a[k1-1]=a[k1];
    //removed element from that array.
    j=0;
    for(int k=0;k<T->count;k++)
        T->key[k]=a[j++];
    P->key[i]=a[j++];
    for(int k=0;k<right->count-1;k++)
        right->key[k]=a[j++];
    right->count--;
    //inserted them all.
    }
    else if(flag!=1&&i!=0&&P->ptr[i-1]!=NULL&&P->ptr[i-1]->count>d)
    {cout<<"Immediate left key redistribution!\n";
     BTPTR left=P->ptr[i-1];
     int a[T->count+1+left->count];
     int j=0;
     for(int k=0;k<left->count;k++)
     a[j++]=left->key[k];
     a[j++]=P->key[i-1];
     for(int k=0;k<T->count;k++)
     a[j++]=T->key[k];
     //stored all keys into an array.
     int k=0;
     while(k<j)
    {if(a[k]==num)
           break;
    k++;}
    for(int k1=k+1;k1<j;k1++)
        a[k1-1]=a[k1];
    //removed element from that array.

    j=0;
    for(int k=0;k<left->count-1;k++)
        left->key[k]=a[j++];
        left->count--;
    P->key[i-1]=a[j++];
    for(int k=0;k<T->count;k++)
        T->key[k]=a[j++];
    //inserted them all.
    }
    else
    {
        flag=0;
        cout<<"Node combining!"<<endl;
        nodecombining(T,num);

    }

}

void combining(BTPTR node,int num)
{int i=0,n;
while(i<node->count)
{
    if(node->key[i]==num)
        break;
    i++;
}
BTPTR left=node->ptr[i];
BTPTR right=node->ptr[i+1];
if(left==NULL)
left=right;
if(right==NULL)
right=left;

if(left!=NULL&&right!=NULL)
{n=left->count+right->count;
BPTR O[n];

for(int i=0;i<n;i++)
{O[i]=new binarynode;
O[i]->lchild=NULL;
O[i]->rchild=NULL;}
int j=0;
for(int i=0;i<left->count;i++)
{
 O[j]->data=left->key[i];
 O[j]->lchild=left->ptr[i];
 O[j++]->rchild=left->ptr[i+1];
}
for(int i=0;i<right->count;i++)
{O[j]->data=right->key[i];
 O[j]->lchild=right->ptr[i];
 O[j++]->rchild=right->ptr[i+1];
}

right->count=left->count+right->count;
for(int i=0;i<n;i++)
{right->key[i]=O[i]->data;
right->ptr[i]=O[i]->lchild;}
right->ptr[n]=O[n-1]->rchild;
left=right;
}
}


void delete_num(int num)
{BTPTR node;
    node=search_node(root,num);
    if(node!=NULL)
    cout<<node->key[0]<<" ";
    else
    {cout<<"Node isn't present.";
    cout<<endl;
    return;}


if(isleaf(node)==true)
{
    if(node->count<d+1)
        {cout<<"Underflow!\n";
        underflow(node,num);
        level_order(root);
        cout<<endl;}
    else
    {int i=0;
    while(i<node->count)
    {
        if(node->key[i]==num)
            break;
            i++;
    }
    for(int j=i+1;j<node->count;j++)
    {
        node->key[j-1]=node->key[j];
    }
    node->key[node->count-1]=0;
    node->count--;
    cout<<"Successfully deleted!\n";
    }
}
else
{
    cout<<"It isn't a leaf node."<<endl;
    int i=0;
    //Deletion and switching of the root.


    while(i<node->count+1)
    {
        if(node->key[i]==num)
            break;
        i++;
    }
    //flag is to detect if it came from node combining.
    if(flag==1)
    {//Has come from node combining, should not replace with successor or predecessor.
    flag=0;
    cout<<"Non-leaf underflow!"<<endl;
    if(node!=root)
    underflow(node,num);
    else
    {
        int i=0;
    if(node->count!=1)
    {while(i<node->count)
    {
        if(node->key[i]==num)
            break;
        i++;
    }
      int j;
     for(int j=i+1;j<node->count;j++)
     {node->key[j-1]=node->key[j];
     node->ptr[j-1]=node->ptr[j];}
     node->key[node->count-1]=0;
     node->ptr[node->count-1]=node->ptr[node->count];
     node->ptr[node->count]=NULL;
     node->count--;
     root=node;
     cout<<"Manipulation of root complete."<<endl;
    }
    else
    {
        node->key[0]=0;
        node->count=0;
        if(node->ptr[0]!=NULL)
            root=node->ptr[0];
        else
            root=node->ptr[1];

     cout<<"The root has been deleted, and updated!\n";
    }
    }}
    else
    {BTPTR suc=NULL,pre=NULL;
      if(node->ptr[i+1]!=NULL)
        {suc=node->ptr[i+1];
     while(suc->ptr[0]!=NULL)
        suc=suc->ptr[0];}

     if(node->ptr[i]!=NULL)
        { pre=node->ptr[i];
     while(pre->ptr[pre->count]!=NULL)
        pre=pre->ptr[pre->count];}

    if(suc!=NULL&&suc->count>d)
    {//This checks for successor to replace non leaf deletion node.
     cout<<"Replaced by successor!\n";

     int x=suc->key[0];
    delete_num(suc->key[0]);
    node->key[i]=x;
    }
    else if(pre!=NULL&&pre->count>d)
    {//This checks for predecessor to replace non leaf deletion node.
     cout<<"Replaced by predecessor!\n";

    int x=pre->key[pre->count-1];
    delete_num(pre->key[pre->count-1]);
    node->key[i]=x;
    }
    else
    {flag=0;
    cout<<"Non-leaf Underflow!"<<endl;
    cout<<"Children must be combined.\n";
    combining(node,num);
    if(node!=root)
    underflow(node,num);
    //node is root, then manipulation of pointers does it.
    else
    {int i=0;
    if(node->count!=1)
    {while(i<node->count)
    {
        if(node->key[i]==num)
            break;
        i++;
    }
      int j;
     for(int j=i+1;j<node->count;j++)
     {node->key[j-1]=node->key[j];
     node->ptr[j-1]=node->ptr[j];}
     node->key[node->count-1]=0;
     node->ptr[node->count-1]=node->ptr[node->count];
     node->ptr[node->count]=NULL;
     node->count--;
     root=node;
     cout<<"Manipulation complete."<<endl;}
     else
     {cout<<"Root count is 1.\n";
     if(pre!=NULL&&suc!=NULL)
     {int n=pre->count+suc->count;
     int a[n];

     for(int i=0;i<pre->count;i++)
        a[i]=pre->key[i];
     for(int i=0;i<suc->count;i++)
        a[pre->count+i]=suc->key[i];
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
     for(int i=0;i<n;i++)
     {suc->key[i]=a[i];}
     suc->count=n;
     }
        node->key[0]=0;
        node->count=0;

        if(node->ptr[0]!=NULL)
            root=node->ptr[0];
        else
            root=node->ptr[1];
        cout<<"The root has been deleted, and updated!\n";
     }
    }
}
}
}
}


void inorder(BTPTR T)
{
    if(T!=NULL)
    {
        for(int i=0;i<T->count;i++)
        {
            inorder(T->ptr[i]);
            if(T->parent!=NULL)
            cout<<T->count<<" "<<T->key[i]<<"\n";
        }
        inorder(T->ptr[T->count]);
    }

}

int main()
{int num,n;char ch;
    cout<<"Enter d:";
    cin>>d;
    cout<<"Enter number of elements:";
    cin>>n;
    int a[n];
    cout<<"Enter array:";
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {create(T,a[i]);
    T=root;}

   level_order(T);
   cout<<endl;
   cout<<"Delete?:";
   cin>>ch;
   while(ch!='n')
   {cout<<"Enter the number to be deleted:";
   cin>>num;
   delete_num(num);
   cout<<endl;
   level_order(root);
   cout<<endl;
   cout<<"Delete?:";
   cin>>ch;
   flag=0;}
}
