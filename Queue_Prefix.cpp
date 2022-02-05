#include<iostream>
#include<string>
#include<cctype>
using namespace std;

union u{
int a;
char c;};

struct queue
{int s=0;
int f=-1;
int r=-1;
int tag[20];
union u elemq[20];
}q;


void enqueue(u,int);
u dequeue();
int qfull();
int qempty();

int main()
{string p;
cout<<"Enter prefix expression:\n";
getline(cin,p);
int i=0;u x,res1,res2,res3,res;
while(i<p.length())
{if(isdigit(p[i]))
{x.a=(int)p[i]-48;
x.c='\0';
enqueue(x,1);}
else
{x.c=p[i];
x.a=-1;
enqueue(x,2);}
i++;}

for(int i=0;q.f==q.r&&q.f==0;i++)
{
if(q.tag[i]==2&&q.tag[i+1]==2)
{res1=dequeue();
res2=dequeue();
enqueue(res1,2);}

else if(q.tag[i]==2&&q.tag[i+1]==1)
{
if(q.tag[i+2]==1)
{res1=dequeue();
res2=dequeue();
res3=dequeue();
if(res1.c=='+')
 res.a=res2.a+res3.a;
if(res1.c=='-')
 res.a=res2.a-res3.a;
if(res1.c=='*')
res.a=res2.a*res3.a;
if(res1.c=='/')
 res.a=res2.a/res3.a;
     enqueue(res,1);}
  else
    {res1=dequeue();res2=dequeue();
        enqueue(res1,2);enqueue(res2,1);} }

else if(q.tag[i]==1&&q.tag[i+1]==1)
{
if(q.tag[i+2]==1)
{res1=dequeue();
res2=dequeue();
enqueue(res1,1);enqueue(res2,1);}}
}
cout<<q.elemq[0].a<<"\n";
return 0;
}

int qempty()
{
    if(q.f==-1)
        return 1;
    else
        return 0;
}

int qfull()
{
if((q.r+1)%q.s==q.f)
  return 1;
else
  return 0;}

void enqueue(u y,int t)
{   if(qempty()==1)
    {q.f=0;q.r=0;}
    else
    {q.r=(q.r+1)%q.s;
    if(t==1)
    {q.elemq[q.r].a=y.a;q.tag[q.r]=1;}
    else
    {q.elemq[q.r].c=y.c;q.tag[q.r]=2;}
    }
}
u dequeue()
{char x;int k;union u def;def.a=-1;def.c='\0';
    if(qempty()==1)
    {return def;}
    else
    {if(q.f==q.r)
    {k=q.r;
    q.f=-1;q.r=-1;
    return q.elemq[k];}
    else
    {return q.elemq[q.f++];}
    }}


