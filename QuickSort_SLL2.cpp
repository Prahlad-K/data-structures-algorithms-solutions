#include <iostream>
using namespace std;
typedef struct lnode
{
    int data;
    struct lnode* next;
}*LPTR;
LPTR L=NULL,head=NULL;
int f=1;
void create(LPTR &L,int num)
{
    if(L==NULL)
    {
        LPTR N=new lnode;
        N->data=num;
        N->next=NULL;
        L=N;
        if(f==1)
        {head=L;
            f++;
        }
    }
    else
    {
        while(L->next!=NULL)
            L=L->next;
        LPTR N=new lnode;
        N->data=num;
        N->next=NULL;
        L->next=N;
    }
}

int position(LPTR L)
{LPTR temp=head;int count=0;
    while(temp->data!=L->data)
        {temp=temp->next;
        count++;}
    return count;
}

LPTR node(int pos)
{LPTR temp=head;
    for(int i=1;i<=pos;i++)
        temp=temp->next;
    if(temp!=NULL)
    return temp;
    else
    cout<<"";//do nothing.
}

int num,size=0;
int partition(LPTR low,LPTR high)
{int p,l,h;
p=low->data;
l=position(low)+1;
h=position(high);
int temp;
    while(l<=h)
    {
    if(p>node(l)->data)
        {l++;}
    else if(p<node(h)->data)
        {h--;}
    else
    {temp=node(h)->data;
    node(h)->data=node(l)->data;
    node(l)->data=temp;}
    }
    temp=node(h)->data;
    node(h)->data=low->data;
    low->data=temp;
    return h;
}

int j;
void quicksort(LPTR low,LPTR high)
{
    if(position(low)<position(high))
    {j=partition(low,high);
    quicksort(low,node(j-1));
    quicksort(node(j+1),high);
    }
}

int main()
{char ch;
    cout<<"Enter?:";
    cin>>ch;
    while(ch!='n')
    {cout<<"Enter number:";
    cin>>num;
    create(L,num);
    L=head;
    size++;
    cout<<"Enter?:";
    cin>>ch;}
    cout<<endl;
    LPTR high=node(size-1);
    quicksort(head,high);
    //after completion of quicksort.
    cout<<"Sorted order:\n";
    LPTR temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
