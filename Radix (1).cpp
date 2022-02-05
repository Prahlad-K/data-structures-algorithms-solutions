#include <iostream>
#include <cmath>
using namespace std;

struct queue{
int s=0;
int f=-1;
int r=-1;
int elemq[20];}q[10];

int qempty(int);
int dequeue(int);
void enqueue(int,int);
int main()
{int n;
cout<<"Enter number of numbers:";
cin>>n;int a[n];
cout<<"Enter array:\n";
for(int i=0;i<n;i++)
cin>>a[i];
int max=a[0];
for(int i=0;i<n;i++)
{if(a[i]>max)
max=a[i];
}
int c=0;
while(max>0)
{max=max/10;
c++;}

int num,rem;
for(int k=0;k<c;k++)
{
for(int i=0;i<n;i++)
{num=a[i]/pow(10,k);
rem=num%10;
enqueue(a[i],rem);}

int j=0;
for(int m=0;m<10;m++)
{for(int p=0;p<q[m].s;p++)
{if(j==n)
break;
else
{a[j]=dequeue(m);j++;}
}
}
for(int i=0;i<10;i++)
{q[i].s=0;}


}

for(int i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<"is the sorted order.";
}

int qempty(int pos)
{if(q[pos].f==-1)
return 1;
else
return 0;}

void enqueue(int x,int pos)
{int k;
if(qempty(pos)==1)
{q[pos].f=0;q[pos].r=0;}
if(qempty(pos)!=1)
{q[pos].elemq[q[pos].r]=x;q[pos].s++;
q[pos].r=(q[pos].r+1)%20;}
}

int dequeue(int pos)
{int k;
if(qempty(pos)!=1)
{k=q[pos].f;
q[pos].f=(q[pos].f+1)%20;
return q[pos].elemq[k];
}
}
