#include <iostream>
#include <string>
#include <queue>

using namespace std;
int m;
typedef struct bnode
{
    int cnt=0;
    int key[100];
    struct bnode* *ptr;
    struct bnode* parent;
}*BTPTR;
BTPTR T=NULL,root=NULL;

queue <BTPTR> q;

int k;int p=0;

void sortnode(int *a,int n)
{int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        if(a[i]<a[j])
        {temp=a[i];
        a[i]=a[j];
        a[j]=temp;}
        }}
}


void create(BTPTR &T,int k)
{
if(T==NULL)
{BTPTR N;
N=new bnode;
N->ptr=new BTPTR[m];
for(int i=0;i<m;i++)
    {N->ptr[i]=NULL;}
N->parent=NULL;

if(N->cnt==0)
{N->key[0]=k;N->cnt=1;}

T=N;
p++;
if(p==1)
{root=T;root->parent=NULL;}
}
else
{if(T->cnt==0)
{T->key[0]=k;T->cnt=1;}

else if(T->cnt<m-1)
{T->key[T->cnt]=k;
T->cnt++;
sortnode(T->key,T->cnt);
for(int i=0;i<T->cnt;i++)
    cout<<T->key[i]<<" ";
}
else if(T->cnt==m-1)
{int i=0;
while(i<m-1)
{if(k<T->key[i])
break;
i++;
}

create(T->ptr[i],k);
T->ptr[i]->parent=T;}
}
}
void inorder(BTPTR T)
{
if(T!=NULL)
{
for(int i=0;i<m;i++)
{inorder(T->ptr[i]);
if(T->key[i]!=0)
cout<<T->key[i]<<" ";}}
}

void levelorder(BTPTR T)
{
    q.push(T);
    BTPTR flag;
    flag=new bnode;
    flag->ptr=new BTPTR[m];
    for(int i=0;i<m-1;i++)
        {flag->key[i]='-';
        flag->ptr[i]=NULL;}
        flag->ptr[m-1]=NULL;
    q.push(flag);BTPTR T1;
    while(q.size()!=1)
    {T1=q.front();
    q.pop();
    if(T1->key[0]!='-')
    {
        for(int i=0;i<T1->cnt;i++)
        {
            if(i!=T1->cnt-1)
            {if(T1->key[i]!=0)
            cout<<T1->key[i]<<"|";}
            else
            {if(T1->key[i]!=0)
            cout<<T1->key[i]<<"  ";}
        }

        for(int i=0;i<m;i++)
        {
            if(T1->ptr[i]!=NULL)
                q.push(T1->ptr[i]);
        }
    }
    else
    {
        cout<<endl;
        q.push(T1);
    }

    }
        q.pop();

}

BTPTR searchnode(int num,BTPTR T)
{

    if(T!=NULL)
    {
        int i=0;
        while(i<T->cnt)
        {
            if(num<T->key[i])
                break;
            else if(num==T->key[i])
                return T;
            i++;
        }
    searchnode(num,T->ptr[i]);

    }

}

void deletenode(int num)
{
    BTPTR dnode,dparent;
    dnode=searchnode(num,root);
    cout<<dnode->key[0]<<" is the node to be deleted.\n";
    if(dnode->cnt==1)
    {
    dparent=dnode->parent;
    int i=0;
    while(i<m)
    {
        if(dparent->ptr[i]==dnode)
            {dparent->ptr[i]=NULL;
            break;}
            i++;
    }
    }
    else
    {int i=0;
        while(i<dnode->cnt)
        {
            if(dnode->key[i]==num)
                break;
                i++;
        }

        int rep;
        if(dnode->ptr[i]!=NULL)
        {rep=dnode->ptr[i]->key[dnode->ptr[i]->cnt-1];
        deletenode(dnode->ptr[i]->key[dnode->ptr[i]->cnt-1]);
        dnode->key[i]=rep;}

        else if(dnode->ptr[i+1]!=NULL)
        {rep=dnode->ptr[i+1]->key[0];
        deletenode(dnode->ptr[i+1]->key[0]);
        dnode->key[i]=rep;}

        else
        {dnode->key[i]=0;dnode->cnt--;}

    }
}


int main()
{int n;char ch;
cout<<"Enter m:";
cin>>m;
    do
    {
    cout<<"Enter number:";
    cin>>n;
    create(T,n);
     T=root;
    cout<<"Continue?:";
    cin>>ch;
    }while(ch!='n');

    T=root;
    cout<<"\nInorder:";
    inorder(T);
    cout<<endl;
    T=root;
    levelorder(T);
    cout<<endl;
    int num;
    cout<<"Do you want to delete?:";
    cin>>ch;
    while(ch!='n')
    {
        cout<<"Enter the number:";
        cin>>num;
        deletenode(num);
        T=root;
        levelorder(T);
        cout<<"Do you want to delete?:";
    cin>>ch;
    }

}
