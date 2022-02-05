#include <iostream>
#include <queue>
using namespace std;

typedef struct dhnode
{int data;
struct dhnode* *cptr;
}*DHPTR;
DHPTR T=NULL,root=NULL;int d;
int p=0;queue <DHPTR> q;
void create(DHPTR &T,int H[],int s,int i)
{
if(i<s)
{if(T==NULL)
{DHPTR N;
N=new dhnode;
N->data=H[i];
N->cptr=new DHPTR[d];
for(int j=0;j<d;j++)
    N->cptr[j]=NULL;
T=N;
p++;
if(p==1)
    root=T;
}

for(int j=0;j<d;j++)
{create(T->cptr[j],H,s,(i*d)-(d-2)+j);}
}
}

DHPTR flag,T1;
void level_order(DHPTR T)
{flag=new dhnode;
flag->data='-';
flag->cptr=new DHPTR[d];
for(int j=0;j<d;j++)
    flag->cptr[j]=NULL;
    q.push(T);q.push(flag);
   while(q.size()!=1)
   {T1=q.front();
   q.pop();
   if(T1->data!='-')
   {cout<<T1->data<<" ";int m=0;
   while(T1->cptr[m]!=NULL&&m<d)
   q.push(T1->cptr[m++]);}
   else
   {q.push(T1);cout<<"\n";}
   }
   q.pop();
}
bool check_heap(DHPTR T)
{
    if(T!=NULL)
    {
        for(int i=0;i<d;i++)
        {if(T->cptr[i]!=NULL)
        {if(T->data>T->cptr[i]->data)
        return false;
        }}
    for(int i=0;i<d;i++)
    return(check_heap(T->cptr[i]));
    }
    else
    return true;
}

void heapify(DHPTR T)
{
    if(T!=NULL)
    {
        for(int i=0;i<d;i++)
        {if(T->cptr[i]!=NULL)
        {if(T->data>T->cptr[i]->data)
        swap(T->data,T->cptr[i]->data);
        }}
    for(int i=0;i<d;i++)
    heapify(T->cptr[i]);
    }
}
int main()
{int n;DHPTR heap=NULL;
cout<<"Enter d value:";
cin>>d;
cout<<"Enter array size:";
cin>>n;
int H[n+1];
cout<<"Enter heap array:";
for(int j=1;j<n+1;j++)
    cin>>H[j];

create(T,H,n+1,1);

if(check_heap(T))
{cout<<"Yes, it's a heap!"<<endl;heap=root;}
else
{cout<<"No, therefore heapified."<<endl;
do
{heapify(heap);
heap=root;
}while(!check_heap(heap));}

level_order(heap);
}
