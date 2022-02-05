#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef struct bnode
{
    struct bnode* lchild;
    char data;
    struct bnode* rchild;

}*BTPTR;
BTPTR T=NULL,root=NULL;int i;int p=0;

string s;
void create(BTPTR &T)
{char ch;
if(i!=-1)
    {if(T==NULL)
    {BTPTR N;
    N=new bnode;
    N->lchild=NULL;
    N->rchild=NULL;
    N->data=s[i];
    i--;p++;
    T=N;
    if(p==1)
    root=T;
    }
  if(T->data<48||T->data>57)
   {create(T->rchild);
   create(T->lchild);}
}}
int ctr=0;
void inorder(BTPTR T)
{if(T!=NULL)
{if(T->lchild!=NULL)
cout<<"(";
inorder(T->lchild);
cout<<T->data;
inorder(T->rchild);
if(T->rchild!=NULL)
cout<<")";
}
}

void solve(BTPTR &T)
{
    int a=(int)(T->lchild->data)-48;

    int b=(int)(T->rchild->data)-48;

    int c;
    switch(T->data)
    {
        case '+':c=a+b;break;
        case '-':c=a-b;break;
        case '*':c=a*b;break;
        case '/':c=a/b;break;
    }
    T->data=(char)(c+48);
    T->lchild=NULL;
    T->rchild=NULL;
}

void evaluate(BTPTR T)
{
    if(T!=NULL)
    {if(T->lchild!=NULL||T->rchild!=NULL)
    {
    if(T->lchild->data>='0'&&T->lchild->data<='9'
        &&T->rchild->data>='0'&&T->rchild->data<='9')
    {solve(T);evaluate(root);}
    else
    {
    evaluate(T->lchild);
    evaluate(T->rchild);}
    }
}}


int main()
{char *in;in=new char;
    cout<<"Enter postfix expression:";
    cin>>s;
    i=s.length()-1;
    create(T);
    T=root;
    inorder(T);
    cout<<endl;
    T=root;
    evaluate(T);
    cout<<T->data<<" is the answer.";
}
