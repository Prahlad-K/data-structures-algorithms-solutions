#include<iostream>
#include<string>
using namespace std;

struct stack
{
int top=-1;
char elems[20];
}s;

struct queue
{int s=0;
int f=-1;
int r=-1;
char elemq[20];
}q;

int stkful();
int stkmt();
void push(char x);
char pop();

void enqueue(char);
char dequeue();
int qfull();
int qempty();

int main()
{string p;
cout<<"Enter queue:\n";
getline(cin,p);
int i=0;
while(i<p.length())
{if(p[i]!=' ')
{enqueue(p[i]);
q.s++;}i++;}

for(int i=0;i<q.s;i++)
push(dequeue());

for(int i=0;i<q.s;i++)
enqueue(pop());

for(int i=0;i<q.s;i++)
cout<<q.elemq[i]<<" ";
cout<<"Is the reverse of the queue :)\n";
return 0;
}
int stkful()
{
if(s.top==20)
return 1;
else
return 0;}

int stkmt()
{if(s.top==-1)
return 1;
else
return 0;}

void push(char x)
{if(stkful()==1)
cout<<"stack is full";
else
{s.elems[++s.top]=x;}

}
char pop()
{
if(stkmt())
{cout<<s.top<<"\nstack is empty";
return '\0';}
else
return s.elems[s.top--];
}
char top()
{if(stkmt())
return -1;
else
return s.elems[s.top];
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
if((q.r+1)/q.s==q.f)
  return 1;
else
  return 0;}

void enqueue(char x)
{   if(qempty()==1)
    {q.f=0;q.r=0;}
    else
    {q.r++;}
    q.elemq[q.r]=x;
}
char dequeue()
{char x;int k;
    if(qempty()==1)
    {return -1;}
    else
    {if(q.f==q.r)
    {k=q.r;
    q.f=-1;q.r=-1;
        return(q.elemq[k]);}
    else
    {
    return(q.elemq[q.f++]);}
    }
}

