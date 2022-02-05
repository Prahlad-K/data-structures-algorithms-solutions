#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef struct bnode
{
    struct bnode* lchild;
    char data;
    int l;
    struct bnode* rchild;

}*BTPTR;
BTPTR T=NULL,root=NULL;int i=0;

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
queue <BTPTR> q;
BTPTR flag=new bnode;

void diagonal()
{BTPTR T,temp;
    flag->data='-';
    flag->lchild=NULL;
    flag->rchild=NULL;
    T=root;
    while(T!=NULL)
    {q.push(T);T=T->rchild;}
    if(T==NULL)
    {q.push(flag);}

    while(q.size()!=1)
    {temp=q.front();
    if(temp!=flag)
    {cout<<temp->data<<" ";
    q.pop();
    temp=temp->lchild;
    while(temp!=NULL)
    {q.push(temp);temp=temp->rchild;}
    }
    else
    {q.pop();cout<<"\n";
    q.push(flag);}
    }
}

int main()
{
    cout<<"Enter tree standard string:";
    cin>>s;
    cout<<"The tree is successfully created!\n";
    cout<<"Inorder:";
    create(T);
    T=root;
    inorder(T);
    T=root;
    cout<<"\nPreorder:";
    preorder(T);
    T=root;
    cout<<"\nPostorder:";
    postorder(T);
    T=root;
    cout<<"\nDiagonal:\n";
    diagonal();

}
