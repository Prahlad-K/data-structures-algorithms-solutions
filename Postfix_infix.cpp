#include <iostream>
#include <string>
using namespace std;

struct stack{
int top=-1;
string elem[20];}S;

void push(string);
string pop();


int main()
{string s;
    cout<<"Enter the postfix expression:";
cin>>s;
for(int i=0;i<s.length();i++)
    {if((int)s[i]>=48&&(int)s[i]<=57)
        {push(s.substr(i,1));}
        else
        {string c,c1,c2,res;

        switch(s[i])
        {
        case '+':c="+";break;
        case '-':c="-";break;
        case '*':c="*";break;
        case '/':c="/";break;
        }
        c1=pop();
        c2=pop();
        res=c2+c+c1;
        push(res);
        }
    }
cout<<"The equivalent infix expression:";
cout<<S.elem[S.top];
}

void push(string x)
{S.elem[++S.top]=x;
}


string pop()
{return S.elem[S.top--];}


