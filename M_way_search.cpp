#include <iostream>
#include <string>
using namespace std;
int m;
typedef struct bnode
{
    int cnt=0;
    int key[100];
    struct bnode* *ptr;

}*BTPTR;
BTPTR T=NULL,root=NULL;

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

if(N->cnt==0)
{N->key[0]=k;N->cnt=1;}

else if(N->cnt<m-1)
{N->key[N->cnt]=k;N->cnt++;
sortnode(N->key,N->cnt);
}
T=N;
p++;
if(p==1)
root=T;
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
create(T->ptr[i],k);}
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
int main()
{int num;char ch;
cout<<"Enter m:";
cin>>m;
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
