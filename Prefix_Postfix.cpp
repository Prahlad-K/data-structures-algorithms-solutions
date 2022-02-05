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
    cout<<"Enter the prefix expression:";
cin>>s;


for(int i=s.length()-1;i>=0;i--)
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
        res=c1+c2+c;
        push(res);
        }
    }

cout<<S.elem[S.top];
}

void push(string x)
{S.elem[++S.top]=x;
}


string pop()
{return S.elem[S.top--];}


