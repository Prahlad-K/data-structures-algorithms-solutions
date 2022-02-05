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

int num,size=0;int sizenow=0;
int partition(LPTR low,LPTR high)
{int p;sizenow=0;
LPTR l,h;
p=low->data;
cout<<p<<"p\n";
l=low;
h=high;
LPTR templ=l;
while(templ->data!=h->data)
{templ=templ->next;
sizenow++;}
cout<<sizenow<<"sn\n";
int temp;
    while(position(l)<position(h))
    {cout<<position(l)<<"l \n";
     cout<<position(h)<<"h \n";
    if(p>l->data)
        {l=l->next;}
    else if(p<h->data)
        {for(int i=1;i<=sizenow;i++)
        h=h->next;
        cout<<h->data<<"hdata\n";
        }
    else
    {temp=h->data;
    h->data=l->data;
    l->data=temp;}
    }
    temp=h->data;
    h->data=low->data;
    low->data=temp;
    return position(h);
}

int j;
void quicksort(LPTR low,LPTR high)
{
    if(position(low)<position(high))
    {j=partition(low,high);
    cout<<j<<"j\n";
    if(j!=0)
    {node(j-1)->next=low;
    cout<<node(j-1)->data<<"nd\n";
    quicksort(low,node(j-1));}
    if(j!=size-1)
    {high->next=node(j+1);
    quicksort(node(j+1),high);
    }}
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
    high->next=head;//making circular.
    quicksort(head,high);
    //after completion of quicksort.
    cout<<"Sorted order:\n";

    int i=1;
    LPTR temp=head;
    while(i<=size)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        i++;
    }
    cout<<endl;
}
