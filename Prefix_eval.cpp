#include <iostream>
#include <string>

using namespace std;
union u{
int a;
char b;
};

struct queue{
int s;
int f=-1;
int r=-1;
int tag[20];
union u elemq[20];
}q;

int qfull();
int qempty();
void enqueue(u,int);
u dequeue();


int main()
{
string p;
cout<<"Enter prefix expression:\n";
getline(cin,p);

int i=0,n=0;u x,res1,res2,res3,res;
q.s=p.length();
while(i<p.length())
{
if((int)p[i]-48>=0&&(int)p[i]-48<=9)
{x.a=(int)p[i]-48;
enqueue(x,1);}
else
{x.b=p[i];
enqueue(x,2);}
i++;}
i=0;
int m=q.s;
while(m!=1)
{if(q.f==0)
{q.s=m;q.r=0;}

if(q.tag[i]==2&&q.tag[i+1]==1&&q.tag[i+2]==1)
{
res1=dequeue();
res2=dequeue();
res3=dequeue();
if(res1.b=='+')
res.a=res2.a+res3.a;
if(res1.b=='-')
res.a=res2.a-res3.a;
if(res1.b=='*')
res.a=res2.a*res3.a;
if(res1.b=='/')
res.a=res2.a/res3.a;
i=(i+3)%q.s;
m=m-2;
enqueue(res,1);}//case1
else
{if(q.tag[i]==1)
    enqueue(dequeue(),1);
if(q.tag[i]==2)
    enqueue(dequeue(),2);
i=(i+1)%q.s;}//case2
}
q.s=m;

if(q.s==1)
cout<<q.elemq[0].a;
else
cout<<"Invalid!\n";
return 0;}

int qempty()
{if(q.f==-1)
return 1;
else
return 0;
}

int qfull()
{if(q.f==(q.r+1)%q.s)
return 1;
else
return 0;}

void enqueue(u y,int t)
{int m;
if(qempty()==1)
{q.f=0;q.r=0;}
if(qempty()!=1)
{m=q.r;
q.r=(q.r+1)%q.s;
if(t==1)
{q.elemq[m].a=y.a;q.tag[m]=1;}
else
{q.elemq[m].b=y.b;q.tag[m]=2;}}

}

u dequeue()
{int k,x;
u def;
def.a=-1;def.b='\0';
if(qempty()==1)
return def;
else
{x=q.f;
q.f=(q.f+1)%q.s;
return q.elemq[x];
}}


