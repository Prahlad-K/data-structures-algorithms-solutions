#include <iostream>
#include <string>
using namespace std;
typedef struct bnode
{
    int cnt=0;
    int key[2];
    struct bnode* *ptr;

}*BTPTR;
BTPTR T=NULL,root=NULL;

int k;int p=0;
void create(BTPTR &T,int k)
{
if(T==NULL)
{BTPTR N;
N=new bnode;
N->ptr=new BTPTR[3];
for(int i=0;i<3;i++)
    {N->ptr[i]=NULL;}

if(N->cnt==0)
{N->key[0]=k;N->cnt=1;}

else if(N->cnt==1)
{if(k>N->key[0])
 {N->key[1]=k;N->cnt=2;}
 else
 {N->key[1]=N->key[0];
 N->key[0]=k;
 N->cnt=2;}
}
T=N;
p++;
if(p==1)
root=T;
}
else
{if(T->cnt==0)
{T->key[0]=k;T->cnt=1;}

else if(T->cnt==1)
{if(k>T->key[0])
 {T->key[1]=k;T->cnt=2;}
 else
 {T->key[1]=T->key[0];
 T->key[0]=k;
 T->cnt=2;}
 return;
}
else if(T->cnt==2)
{if(k<T->key[0])
    create(T->ptr[0],k);
else if(k>T->key[0]&&k<T->key[1])
    create(T->ptr[1],k);
else
    create(T->ptr[2],k);
}
}
}
void inorder(BTPTR T)
{
if(T!=NULL)
{inorder(T->ptr[0]);
cout<<T->key[0]<<" ";
inorder(T->ptr[1]);
cout<<T->key[1]<<" ";
inorder(T->ptr[2]);
}
}

int main()
{int num;char ch;
    do
    {
    cout<<"Enter number:";
    cin>>num;
    create(T,num);
     T=root;
    cout<<"Continue?:";
    cin>>ch;
    }while(ch!='n');

    T=root;
    cout<<"\nInorder:";
    inorder(T);
}
