#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
typedef struct bnode
{    char data;
    int x;
    int freq;
    bnode *lc,*rc;
}*BTPTR;
vector <BTPTR> v;

bool compare(BTPTR &a,BTPTR &b)
{if(a->freq<b->freq)
return true;
else
return false;
}
queue<BTPTR> q;
BTPTR flag,T1;
int j=0,ctr=0;
void inorder(BTPTR T)
{
    if(T!=NULL)
    {
        inorder(T->lc);
        T->x=ctr++;
        inorder(T->rc);
    }
}

void level_order(BTPTR T)
{inorder(T);
    flag=new bnode;
flag->data='*';flag->lc=NULL;flag->rc=NULL;
    q.push(T);q.push(flag);
   while(q.size()!=1)
   {T1=q.front();
   q.pop();
   if(T1->data!='*')
   {while(j<T1->x)
   {cout<<" ";j++;}
       cout<<T1->data;j++;
   if(T1->lc!=NULL)
     q.push(T1->lc);
   if(T1->rc!=NULL)
    q.push(T1->rc);}
   else
   {q.push(T1);cout<<"\n";j=0;}
   }
}

void create_huffman()
{BTPTR a,b,T;
while(v.size()!=1)
{a=v[0];
b=v[1];
v.erase(v.begin());
v.erase(v.begin());
T=new bnode;
T->lc=a;
T->rc=b;
T->data='-';
T->freq=a->freq+b->freq;
v.push_back(T);
sort(v.begin(),v.end(),compare);
}
level_order(v[0]);cout<<endl;
}

void removenode(BTPTR R,BTPTR T)
{
if(R!=NULL)
{if(R->lc!=NULL)
{if(R->lc->data==T->data)
{R->lc=NULL;return;}
else
removenode(R->lc,T);
}
if(R->rc!=NULL)
{if(R->rc->data==T->data)
{R->rc=NULL;return;}
else
removenode(R->rc,T);
}
}
}



string a,i;int p=0,prev=0;
void print_codes(BTPTR T)
{
    if(T!=NULL)
    {
        if(T->lc==NULL&&T->rc==NULL)
        {
            if(T->data!='-')
            {cout<<T->data<<" ";
            cout<<a<<endl;}
            a="\0";
            if(T!=v[0])
            {removenode(v[0],T);
            print_codes(v[0]);}
        }
        else
        {
            if(T->lc!=NULL)
            {a=a+"0";print_codes(T->lc);}
            if(T->rc!=NULL)
            {a=a+"1";print_codes(T->rc);}
        }
    }
}
int main()
{int n;
    cout<<"Enter the number of characters:";
    cin>>n;
    BTPTR temp;
    for(int i=0;i<n;i++)
    {temp=new bnode;
    cin>>temp->data>>temp->freq;
    temp->lc=NULL;
    temp->rc=NULL;
    v.push_back(temp);
    }
    create_huffman();
    print_codes(v[0]);
}

