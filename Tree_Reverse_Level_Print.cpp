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
       char elements[30];
       }s;
int stkful();
int stkmt();
void push(char x);
char pop();
char top();


struct queue{
int s=0;
int f=-1;
int r=-1;
BTPTR a[30];
}q;
int qempty();
BTPTR dequeue();
void enqueue(BTPTR);


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
{if(T!=NULL)
{inorder(T->lchild);
cout<<T->data<<" ";
inorder(T->rchild);
}
}
void preorder(BTPTR T)
{if(T!=NULL)
{cout<<T->data<<" ";
preorder(T->lchild);
preorder(T->rchild);
}
}

void postorder(BTPTR T)
{if(T!=NULL)
{postorder(T->lchild);
postorder(T->rchild);
cout<<T->data<<" ";
}
}
BTPTR flag,T1;

void level_order(BTPTR T)
{flag=new bnode;
flag->data='-';flag->lchild=NULL;flag->rchild=NULL;
    enqueue(T);enqueue(flag);
   while(q.s!=1)
   {T1=dequeue();
   if(T1->data!='-')
   {push(T1->data);
   if(T1->lchild!=NULL)
    enqueue(T1->lchild);
   if(T1->rchild!=NULL)
    enqueue(T1->rchild);}
   else
   {enqueue(T1);push('#');}
   }

}

int main()
{char ch;
    cout<<"Enter tree standard string:";
    cin>>str;
    cout<<"The tree is successfully created!\n";
    create(T);
    T=root;
    level_order(T);
    do
    {ch=pop();
    if(ch!='#')
    cout<<ch<<" ";
    else
    cout<<"\n";}while(!stkmt());
}
int qempty()
{
    if(q.f==-1)
        return 1;
    else
        return 0;
}

void enqueue(BTPTR x)
{
    if(qempty()==1)
{q.f=0;q.r=0;}

if(qempty()!=1)
    {q.a[q.r]=x;
    q.r=(q.r+1)%30;q.s++;}
}

BTPTR dequeue()
{int k;BTPTR temp;temp=NULL;
    if(qempty()==1)
        return temp;
    else
    {k=q.f;
    q.f=(q.f+1)%30;q.s--;
    return q.a[k];}
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
void push(char x)
{if(stkful())
cout<<"stack is full";
else
{s.top++;
s.elements[s.top]=x;
}
}
char pop()
{
if(stkmt())
{cout<<s.top<<"\nstack is empty";
return -1;}
else
return s.elements[s.top--];
}
char top()
{if(stkmt())
return -1;
else
return s.elements[s.top];
}
