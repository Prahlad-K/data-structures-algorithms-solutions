#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
struct stack{
int l=-1;
char top;
char elements[50];}S;

void push(char);
char pop();
char top();
int stack_full();
int stack_empty();
int retind(char);
char op[4]={'-','+','*','/'};

int main()
{
cout<<"Enter your expression:\n";
string s;
cin>>s;
char t;
int index=-1;

for(int i=0;i<s.length();i++)
{for(int j=0;j<4;j++)
    {if(s[i]==op[j])
    {
        index=retind(top());
        if(j>=index)
        push(s[i]);
        else
        {

        while((index>j||(index==0&&j==1)||(index==2&&j==3))&&stack_empty()!=1)
        {
            cout<<pop();
            index=retind(top());
        }
        push(s[i]);}
    }
    }
     if((int)s[i]<=57&&(int)s[i]>=48)
    {cout<<s[i];}

}

while(stack_empty()!=1)
    cout<<S.elements[S.l--];


}

void push(char c)
{
    if(stack_full()==1)
        cout<<"Stack is full!";
    else
    {S.elements[++S.l]=c;}
}

char pop()
{
    if(stack_empty()==1)
        {return '0';}
    else
    {
    return(S.elements[S.l--]);}
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
return S.elements[S.l];
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
