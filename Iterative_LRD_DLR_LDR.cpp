#include <iostream>
#include <string>
using namespace std;
typedef struct bnode
{
    struct bnode* lchild;
    char data;
    struct bnode* rchild;

}*BTPTR;
BTPTR T=NULL,root=NULL;int i=0;

struct stack
       {int size=30;
       int top=-1;
       BTPTR elements[30];
       }s;
int stkful();
int stkmt();
void push(BTPTR);
BTPTR pop();
BTPTR top();


string str;
void create(BTPTR &T)
{char ch;
    if(T==NULL)
    {BTPTR N;
    N=new bnode;
    N->lchild=NULL;
    N->rchild=NULL;
    N->data=str[i];
    i++;
    T=N;
    if(i==1)
    root=T;
    }

    ch=str[i];
    if(ch!='.')
    {create(T->lchild);}
    else
        i++;

    ch=str[i];
    if(ch!='.')
    {create(T->rchild);}
    else
        i++;
}

void inorder(BTPTR T)
{BTPTR T1;
l:
while(T!=NULL)
{push(T);
T=T->lchild;}

while(stkmt()!=1)
{T1=pop();
cout<<T1->data<<" ";
 if(T1->rchild!=NULL)
    {T=T1->rchild;}
goto l;
}
}

void preorder(BTPTR T)
{BTPTR T1;
l:
while(T!=NULL)
{push(T);
cout<<T->data<<" ";T=T->lchild;}
while(stkmt()!=1)
{T1=pop();
if(T1->rchild!=NULL)
    T=T1->rchild;
goto l;
}
}

void postorder(BTPTR T)
{BTPTR T1,r;
label:
while(T!=NULL)
{if(T->rchild!=NULL)
push(T->rchild);
push(T);T=T->lchild;}
if(stkmt()!=1)
{T1=pop();
if(T1->rchild!=NULL&&top()==T1->rchild)
{r=pop();
T=r;
push(T1);
}
else
{cout<<T1->data<<" ";
T=NULL;
}
goto label;
}
}



int main()
{
    cout<<"Enter tree standard string:";
    cin>>str;
    cout<<"The tree is successfully created!\n";
    cout<<"Inorder:";
    create(T);
    T=root;
    inorder(T);
    cout<<"\nPreorder:";
    T=root;
    preorder(T);
    cout<<"\nPostorder:";
    T=root;
    postorder(T);

}
int stkful()
{
if(s.top==s.size)
return 1;
else
return 0;}
int stkmt()
{if(s.top==-1)
return 1;
else
return 0;}
void push(BTPTR x)
{if(stkful())
cout<<"stack is full";
else
{s.top++;
s.elements[s.top]=x;
}
}
BTPTR pop()
{return s.elements[s.top--];
}
BTPTR top()
{
return s.elements[s.top];
}

