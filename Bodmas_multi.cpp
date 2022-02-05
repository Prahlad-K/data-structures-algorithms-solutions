#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
struct stack{
int l=-1;
int elements[50];}S;
int flag=0;
void push(int);
int pop();
int stack_full();
int stack_empty();
int main()
{
cout<<"Enter your expression:\n";
string s;
getline(cin,s);
char t;

char op[4]={'/','*','+','-'};

int e1,e2,e;
for(int i=0;i<s.length();i++)
{if((int)s[i]<=57&&(int)s[i]>=48)
     {push((int)s[i]-48);}
else if(s[i]==' ')
{flag=0;}
    else
    {flag=0;
     for(int j=0;j<4;j++)
    {if(s[i]==op[j])
     {e1=pop();
     e2=pop();
     if(op[j]=='+')
     e=e2+e1;
     if(op[j]=='-')
     e=e2-e1;
     if(op[j]=='*')
     e=e2*e1;
     if(op[j]=='/')
     e=e2/e1;
      push(e);}
      else
        {cout<<"Wrong input!";exit(0);}
      }}}
     cout<<S.elements[S.l];

}

void push(int c)
{
    if(stack_full()==1)
        cout<<"Stack is full!";
    else
    {if(flag==1)
    {int num;
    num=pop();
    S.elements[++S.l]=c+10*num;}
    else if(flag==0)
    {S.elements[++S.l]=c;flag=1;}}
}

int pop()
{
    if(stack_empty()==1)
        {cout<<"Stack is empty!";
        return '0';}
    else
    {return(S.elements[S.l--]);
    }
}

int stack_full()
{
    if(S.l==49)
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
