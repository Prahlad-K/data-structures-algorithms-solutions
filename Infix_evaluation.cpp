#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
union u{
int a;
char b;};

struct stack{
int l=-1;
char top;
union u elem[50];}S;

void push(u,int);
u pop();
char top();
int stack_full();
int stack_empty();
int retind(char);
char op[4]={'-','+','*','/'};

int main()
{
cout<<"Enter your expression:\n";
string s;char *s1;int pos=0;
s1=new char;
cin>>s;
char t;
int index=-1;
union u x,y,res;
for(int i=0;i<s.length();i++)
{for(int j=0;j<4;j++)
    {if(s[i]==op[j])
    {
        index=retind(top());
        if(j>=index)
        {x.b=s[i];
        push(x,2);}
        else
        {

        while((index>j||(index==0&&j==1)||(index==2&&j==3))&&stack_empty()!=1)
        {
            y=pop();
            *(s1+pos)=y.b;
            pos++;
            index=retind(top());
        }
        x.b=s[i];
        push(x,2);}
    }
    }
     if((int)s[i]<=57&&(int)s[i]>=48)
    {*(s1+pos)=s[i];pos++;}

}

while(stack_empty()!=1)
    {*(s1+pos)=S.elem[S.l--].b;pos++;}



S.l=-1;
int e1,e2,e;char p,q;
for(int i=0;i<s.length();i++)
    {if((int)*(s1+i)<=57&&*(s1+i)>=48)
     {x.a=(int)*(s1+i)-48;
    push(x,1);}
     else
    {for(int j=0;j<4;j++)
    {
     if(*(s1+i)==op[j])
     {x=pop();
     y=pop();
     e1=x.a;
     e2=y.a;
     if(op[j]=='+')
     e=e2+e1;
     if(op[j]=='-')
     e=e2-e1;
     if(op[j]=='*')
     e=e2*e1;
     if(op[j]=='/')
     e=e2/e1;

      res.a=e;
      push(res,1);
    }}}}
     if(S.l==0)
     cout<<S.elem[S.l].a;
     else
     cout<<"Nonsense example!";

}

void push(u c,int t)
{
    if(stack_full()==1)
        cout<<"Stack is full!";
    else
    {   if(t==1)
        {S.elem[++S.l].a=c.a;}
        if(t==2)
        {S.elem[++S.l].b=c.b;}
    }
}
u pop()
{u def;def.a=-1;def.b='0';
    if(stack_empty()==1)
        {return def;}
    else
    {
    return(S.elem[S.l--]);}
}

int stack_full()
{
    if(S.l==50)
    return 1;
    else
    return 0;
}
int stack_empty()
{
    if(S.l==-1)
    return 1;
    else
    return 0;
}
char top()
{if(S.l==-1)
return '0';
else
return S.elem[S.l].b;
}

int retind(char x)
{int flag=0;int j;
    for(int i=0;i<4;i++)
    {
        if(x==op[i])
            {flag=1;j=i;break;}
    }
    if(flag==1)
    return j;
    else
    return -1;
}
