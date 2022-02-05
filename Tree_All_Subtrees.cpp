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

void print_subs(BTPTR T)
{  if(T!=NULL)
    {inorder(T->lchild);
    cout<<"\n";
    print_subs(T->lchild);
    inorder(T->rchild);
    cout<<"\n";
    print_subs(T->rchild);
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
    cout<<"\n";
    T=root;
    cout<<"All subtrees in inorder:\n";
    print_subs(T);}

