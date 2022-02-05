#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef struct bnode
{
    struct bnode* lchild;
    char data;
    int level;
    struct bnode* rchild;

}*BTPTR;
BTPTR T=NULL,root=NULL;int i=0;
string s;
int ctr=0;
void create(BTPTR &T)
{char ch;
    if(T==NULL)
    {BTPTR N;
    N=new bnode;
    N->lchild=NULL;
    N->rchild=NULL;
    N->data=s[i];
    i++;
    T=N;
    if(i==1)
    root=T;
    }

    ch=s[i];
    if(ch!='.')
    {create(T->lchild);}
    else
        i++;

    ch=s[i];
    if(ch!='.')
    {create(T->rchild);}
    else
        i++;

}
queue<BTPTR> q;
BTPTR flag,T1;

void level_order(BTPTR T)
{flag=new bnode;
flag->data='-';flag->lchild=NULL;flag->rchild=NULL;
    q.push(T);q.push(flag);
   while(q.size()!=1)
   {T1=q.front();
   q.pop();
   if(T1->data!='-')
   {T1->level=ctr;
   cout<<T1->level<<" ";
   if(T1->lchild!=NULL)
     q.push(T1->lchild);
   if(T1->rchild!=NULL)
    q.push(T1->rchild);}
   else
   {q.push(T1);cout<<"\n";ctr++;}
   }
}
BTPTR pA,pB,A,B;

void parent(BTPTR T,char c,int tag)
{
    if(T!=NULL)
    {
        if(T->lchild!=NULL&&T->lchild->data==c)
        {if(tag==1)
        {pA=T;
        A=T->lchild;
        return;}
        else
        {pB=T;
        B=T->lchild;
        return;}
        }
        if(T->rchild!=NULL&&T->rchild->data==c)
        {
        if(tag==1)
        {pA=T;
        A=T->rchild;
        return;}
        else
        {pB=T;
        B=T->rchild;
        return;}
        }
        parent(T->lchild,c,tag);
        parent(T->rchild,c,tag);
    }

}
int main()
{
cout<<"Enter tree standard string:";
cin>>s;
create(T);
T=root;
level_order(T);
T=root;
char a,b;
cout<<"Enter the nodes:";
cin>>a>>b;
T=root;
parent(T,a,1);
T=root;
parent(T,b,2);


if(pA!=pB&&A->level==B->level)
cout<<"Cousins.";
else
cout<<"Not cousins.";
}
