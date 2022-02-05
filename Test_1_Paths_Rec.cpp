#include <iostream>
using namespace std;
typedef struct mlnode{
int data;
int count;
struct mlnode **link;}*lptr;

void add(lptr &h)
{
    if(h==NULL)
{h=new mlnode;
cout<<"Enter data:";
cin>>h->data;
cout<<"Enter count:";
cin>>h->count;
}
h->link=new mlnode*[h->count+1];
for(int i=0;i<=h->count;i++)
{h->link[i]=NULL;
add(h->link[i]);}
}

void print(lptr h)
{static lptr head=h;
    if(h->count==0)
{cout<<h->data<<" ";
print(h->link[0]);}
if(h->count==1)
{cout<<h->data<<" ";
print(h->link[0]);
h->link[0]=h->link[1];h->count=0;
cout<<"\n";
print(head);
}
if(h->count==-1)
{cout<<h->data<<" ";}
}

int main()
{
    lptr ML;ML=NULL;
    add(ML);
    print(ML);
}
