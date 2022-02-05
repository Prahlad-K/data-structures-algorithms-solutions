#include <iostream>
using namespace std;
typedef struct mlnode{
int data;
int count;
struct mlnode **link;}*lptr;
struct stack
       {int top=-1;
       lptr elements[20];
       }s;
int stkmt();
void push(lptr x);
lptr pop();
lptr peep();

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
void popall()
{
    while(!stkmt())
    {cout<<pop()->data<<" ";}
}

void print(lptr h)
{static lptr head=h;
    if(h->count==0)
{push(h);
print(h->link[0]);}
if(h->count==1)
{push(h);
print(h->link[0]);
h->link[0]=h->link[1];h->count=0;
cout<<"\n";
print(head);
}
if(h->count==-1)
{push(h);popall();}
}
int main()
{
    lptr ML;ML=NULL;
    add(ML);
    print(ML);
}

void push(lptr x)
{s.elements[++s.top]=x;}

lptr pop()
{return s.elements[s.top--];}

lptr peep()
{return s.elements[s.top];}

int stkmt()
{if(s.top==-1)
return 1;
else
return 0;}



