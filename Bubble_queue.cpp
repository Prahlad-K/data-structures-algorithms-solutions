#include <iostream>
#include <cmath>
using namespace std;

struct queue{
int s=0;
int f=-1;
int r=-1;
int a[15];
}q;
int qempty();
int dequeue();
void enqueue(int);
int main()
{int n;
    cout<<"Enter number of numbers:";
cin>>n;int b[n];
cout<<"Enter array:\n";
for(int i=0;i<n;i++)
    cin>>b[i];

for(int i=0;i<n;i++)
{enqueue(b[i]);}

for(int k=0;k<n;k++)
{for(int i=0;i<n;i++)
{int d,t;
d=dequeue();
if(i!=n-1)
{if(d>q.a[q.f])
{t=d;
d=q.a[q.f];
q.a[q.f]=t;}}
enqueue(d);
}}
for(int i=0;i<n;i++)
    cout<<dequeue()<<" ";
}
int qempty()
{
    if(q.f==-1)
        return 1;
    else
        return 0;
}

void enqueue(int x)
{
    if(qempty()==1)
{q.f=0;q.r=0;}

if(qempty()!=1)
    {q.a[q.r]=x;
    q.r=(q.r+1)%15;}
}

int dequeue()
{int k;
    if(qempty()==1)
        return -1;
    else
    {k=q.f;
    q.f=(q.f+1)%15;
    return q.a[k];}
}
