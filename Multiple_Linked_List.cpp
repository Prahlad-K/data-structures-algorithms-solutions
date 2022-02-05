#include <iostream>

using namespace std;

typedef struct mlnode
{
    int data;
    int branches;
    struct mlnode* *branch;
}*MPTR;
MPTR M=NULL,head=NULL;
int m,p=0;
void create(MPTR &M)
{
    if(M==NULL)
    {
        MPTR N=new mlnode;
        cout<<"Enter number:";
        cin>>N->data;
        cout<<"Enter number of branches:";
        cin>>N->branches;
        N->branch=new MPTR[N->branches];
        for(int i=0;i<N->branches;i++)
            N->branch[i]=NULL;
            M=N;
        p++;
        if(p==1)
            head=M;

    }
    for(int i=0;i<M->branches;i++)
        {cout<<"Enter for "<<i+1<<" branch of "<<M->data<<":"<<endl;
        create(M->branch[i]);}


}

void print(MPTR M)
{
    if(M!=NULL)
    {
        cout<<M->data<<" ";
        for(int i=0;i<M->branches;i++)
            {if(M->branch[i]!=NULL)
            {cout<<"(";
                print(M->branch[i]);
             cout<<")";}
            }
    }
}

int main()
{
    cout<<"Lets go!"<<endl;
    create(M);
    M=head;
    cout<<"Multiple linked list is:"<<endl;
    print(M);
}
