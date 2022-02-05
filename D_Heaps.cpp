#include <iostream>
#include <queue>
using namespace std;
typedef struct dhnode
{
    int data;
    struct dhnode* *cptr;
    struct dhnode* pptr;
}*DHPTR;
DHPTR T=NULL,root=NULL;
queue <DHPTR> q;
int p=0,d;
char ch;
void create(DHPTR &T)
{
    if(T==NULL)
    {

        if(ch=='n')
            return;
        DHPTR N=new dhnode;
        cout<<"Enter number:";
        cin>>N->data;
        N->cptr=new DHPTR[d];
        for(int i=0;i<d;i++)
            N->cptr[i]=NULL;
        T=N;
        p++;
        if(p==1)
            root=T;
    q.push(T);
    }
    else
    {DHPTR D;
        D=q.front();q.pop();
        for(int i=0;i<d;i++)
        { cout<<"Enter?:";
        cin>>ch;
        if(ch=='n')
            return;
        DHPTR C=new dhnode;
        C->cptr=new DHPTR[d];
        for(int j=0;j<d;j++)
            C->cptr[j]=NULL;
        cout<<"Enter number:";
        cin>>C->data;
        C->pptr=D;
        D->cptr[i]=C;
        q.push(C);}

    }

}

void print(DHPTR T)
{
    if(T!=NULL)
    {
        cout<<T->data;
        for(int i=0;i<d;i++)
            {if(T->cptr[i]!=NULL)
            {cout<<"{";
            print(T->cptr[i]);
            cout<<"}";}
            }
    }
}

bool check_heap(DHPTR T)
{
    if(T!=NULL)
    {
        for(int i=0;i<d;i++)
        {if(T->cptr[i]!=NULL&&T->data>T->cptr[i]->data)
        return false;}
        for(int i=0;i<d;i++)
        {return(check_heap(T->cptr[i]));}

    }
    else
        return true;

}

void heapify(DHPTR T)
{
    if(T!=NULL)
    {
        for(int i=0;i<d;i++)
        {if(T->cptr[i]!=NULL&&T->data>T->cptr[i]->data)
        swap(T->data,T->cptr[i]->data);}
        for(int i=0;i<d;i++)
        heapify(T->cptr[i]);
    }

}
int main()
{
    cout<<"Enter d value:";
    cin>>d;

    ch='y';
    while(ch!='n')
    {create(T);}
    T=root;
    while(!check_heap(T))
    {heapify(T);T=root;}
    print(T);
}
