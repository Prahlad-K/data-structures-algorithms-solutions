#include <iostream>
#include <queue>
using namespace std;

union u
{int a;
string b;
char c;
};

typedef struct knode
{
struct knode* lchild;
union u key[10];
struct knode* rchild;
}*BTPTR;

BTPTR T=NULL,root=NULL;int n,p;
queue <BTPTR> q;
void create(BTPTR &T,int &index,u k[])
{
 if(T==NULL)
 {BTPTR N;

 N=new knode;
 N->lchild=NULL;
 N->rchild=NULL;
 for(int i=0;i<n/3;i++)
    N->key[i].a=k[i].a;
for(int i=n/3;i<2*n/3;i++)
    N->key[i].b=k[i].b;
for(int i=2*n/3;i<n;i++)
    N->key[i].c=k[i].c;

 T=N;p++;
 if(p==1)
 root=T;
 }
else
{
    if(index==n)
    {index=0;
    if(k[index]<T->key[index])
        create(T->lchild,++index,k);
    else if(k[index]>T->key[index])
        create(T->rchild,++index,k);}
    else
    {if(k[index]<T->key[index])
        create(T->lchild,++index,k);
    else if(k[index]>T->key[index])
        create(T->rchild,++index,k);}

}
}
void print(BTPTR T)
{
    if(T!=NULL)
    {
        print(T->lchild);
        for(int i=0;i<n;i++)
            cout<<T->key[i]<<" ";
        print(T->rchild);
    }
}

BTPTR flag,T1;
void level_order(BTPTR T)
{flag=new knode;
flag->key[0]='-';flag->lchild=NULL;flag->rchild=NULL;
    q.push(T);q.push(flag);
   while(q.size()!=1)
   {T1=q.front();
   q.pop();
   if(T1->key[0]!='-')
   {for(int i=0;i<n;i++)
       cout<<T1->key[i]<<" ";
       cout<<"  ";
   if(T1->lchild!=NULL)
    q.push(T1->lchild);
   if(T1->rchild!=NULL)
    q.push(T1->rchild);}
   else
   {q.push(T1);cout<<"\n";}
   }
   q.pop();
}

void searchnode(BTPTR T,int index,int k,int i)
{
    if(T!=NULL)
    {   if(index==n)
        index=0;
        if(k==T->key[index])
            {cout<<"Found!";return;}
        else if(k<T->key[index])
        {if(i<n)
        {if(k==T->key[i])
         {cout<<"Found!";return;}
        searchnode(T,index,k,++i);}
        else
        searchnode(T->lchild,++index,k,0);
        }
        else if(k>T->key[index])
        {if(i<n)
        {if(k==T->key[i])
         {cout<<"Found!";return;}
        searchnode(T,index,k,++i);}
        else
        searchnode(T->rchild,++index,k,0);
        }
    }

}


int main()
{int index=0;char ch;
 cout<<"Enter number of keys:";
 cin>>n;
 union u k[n];
 do
 {cout<<"Enter key set:";
 for(int i=0;i<n/3;i++)
    cin>>k[i].a;
 for(int i=n/3;i<2*n/3;i++)
    cin>>k[i].b;
for(int i=2*n/3;i<n;i++)
    cin>>k[i].c;

 create(T,index,k);
 cout<<"Created"<<endl;
 T=root;
 cout<<"Continue?:";
 cin>>ch;
 }while(ch!='n');
 cout<<endl;
 T=root;
 level_order(T);
 cout<<endl;
 index=0;T=root;
 int x;
 cout<<"Enter key to be searched:";
 cin>>x;
 searchnode(T,index,x,0);
 }
