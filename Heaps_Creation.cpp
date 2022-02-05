#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef struct bnode
{
    struct bnode* lchild;
    char data;
    struct bnode* rchild;

}*BTPTR;
BTPTR T=NULL,root=NULL;int i=0;
queue <BTPTR> q;
string s;
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

BTPTR flag,T1;
void level_order(BTPTR T)
{flag=new bnode;
flag->data='-';flag->lchild=NULL;flag->rchild=NULL;
    q.push(T);q.push(flag);
   while(q.size()!=1)
   {T1=q.front();
   q.pop();
   if(T1->data!='-')
   {cout<<T1->data<<" ";
   if(T1->lchild!=NULL)
     q.push(T1->lchild);
   if(T1->rchild!=NULL)
    q.push(T1->rchild);}
   else
   {q.push(T1);cout<<"\n";}
   }
}

bool check_heap(BTPTR T)
{
    if(T!=NULL)
    {if(T->lchild!=NULL)
    {if(T->data>T->lchild->data)
        return false;}
    if(T->rchild!=NULL)
    {if(T->data>T->rchild->data)
        return false;}
    else
    {return(check_heap(T->lchild)&&check_heap(T->rchild));}
    }
    else
    return true;
}


int main()
{   cout<<"Enter tree standard string:";
    cin>>s;
    cout<<"The tree is successfully created!\n";
    create(T);
    T=root;
if(check_heap(T))
cout<<"YES!\n";
else
cout<<"NO!\n";
level_order(T);
}
