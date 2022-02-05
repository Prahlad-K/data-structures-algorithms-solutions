#include <iostream>
#include <string>
using namespace std;

struct stack{
int top=-1;
string elem[20];}S;

void push(string);
string pop();

string ptop(string,string,int);

int main()
{string s,ans;
    cout<<"Enter the prefix expression:";
cin>>s;
ans=ptop(s," ",s.length()-1);
cout<<ans;
}

void push(string x)
{S.elem[++S.top]=x;
}


string pop()
{return S.elem[S.top--];}

string ptop(string str,string res,int i)
{
    if(i!=-1)
    {
        if((int)str[i]>=48&&(int)str[i]<=57)
        {push(str.substr(i,1));
        return(ptop(str,res,--i));
        }
        else
        {string c1,c2,c;
        switch(str[i])
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
        return(ptop(str,res,--i));
        }
    }
    else
    {
        return S.elem[S.top];
    }
}
