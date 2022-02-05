#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef struct bnode
{
    struct bnode* lchild;
    string data;
    int x;
    struct bnode* rchild;

}*BTPTR;
BTPTR T=NULL,root=NULL;
string pre;
int ctr,f=0;
int index=0;
int giveind(string in)
{char ch=pre[index++];
for(int j=0;j<in.length();j++)
{if(ch==in[j])
return j;}}

void split(string in,int ctr,string &l,string &r)
{
l=in.substr(0,ctr);

r=in.substr(ctr+1,in.length()-(ctr+1));

}

void create(BTPTR &T,string in)
{string l,r;
if(in.length()!=0)
{if(T==NULL)
{ctr=giveind(in);
BTPTR N=new bnode;
N->data=in.substr(ctr,1);
N->lchild=NULL;
N->rchild=NULL;
split(in,ctr,l,r);
f++;
T=N;
if(f==1)
root=T;
}
create(T->lchild,l);
create(T->rchild,r);
}
}

queue<BTPTR> q;
BTPTR flag,T1;
int j=0,c=0;
void inorder(BTPTR T)
{
    if(T!=NULL)
    {
        inorder(T->lchild);
        T->x=c++;
        inorder(T->rchild);
    }
}

void level_order(BTPTR T)
{inorder(T);
    flag=new bnode;
flag->data="*";flag->lchild=NULL;flag->rchild=NULL;
    q.push(T);q.push(flag);
   while(q.size()!=1)
   {T1=q.front();
   q.pop();
   if(T1->data.compare("*")!=0)
   {while(j<T1->x)
   {cout<<" ";j++;}
       cout<<T1->data;j++;
   if(T1->lchild!=NULL)
     q.push(T1->lchild);
   if(T1->rchild!=NULL)
    q.push(T1->rchild);}
   else
   {q.push(T1);cout<<"\n";j=0;}
   }
}
int main()
{string in;
    cout<<"Enter inorder:";
    cin>>in;
    cout<<"Enter preorder:";
    cin>>pre;
    create(T,in);
    cout<<"Tree has been created successfully!";
    cout<<endl;
    T=root;
    level_order(T);

}
