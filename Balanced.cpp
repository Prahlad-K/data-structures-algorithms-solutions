#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
struct stack{
int l=0;
char elements[50];}S;

void push(char);
char pop();

int stack_full();
int stack_empty();

int main()
{
cout<<"Enter your expression:\n";
string s;
cin>>s;


char open[4]={'{','(','[','<'},close[4]={'}',')',']','>'};
char e;
for(int i=0;i<s.length();i++)
{for(int j=0;j<4;j++)
    {if(s[i]==open[j])
     {push(s[i]);}

     if(s[i]==close[j])
     {e=pop();
     if(e!=open[j])
        {cout<<"Not balanced!";exit(0);}}}}

     if(stack_empty()==1)
     cout<<"Balanced!";
}

void push(char c)
{
    if(stack_full()==1)
        cout<<"Stack is full!";
    else
    {
    S.elements[S.l++]=c;

    }
}

char pop()
{
    if(stack_empty()==1)
        {cout<<"Stack is empty!";
        return '0';}
    else
    {S.l--;

    return(S.elements[S.l]);
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
    if(S.l==0)
    return 1;
    else
    return 0;
}
