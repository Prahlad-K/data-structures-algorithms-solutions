#include<iostream>
#include<string>
using namespace std;
union u
    {int a;
    float b;
	char c;	
	};
struct stack
       {int size=20;
       int top=-1;
       int tag[20];
       union u elements[20];
       }s;
int stkful();
int stkmt();
void push(u x,int tag);
u pop();
u peep();
int main()
{char ch;int c=0,tag;u y,res;
do{c++;
cout<<"to push data type enter the corresponding values "<<endl<<"int:\t1\nfloat:\t2\nchar:\t3\n";
cin>>tag;
cout<<"\nenter the data";
if(tag==1)
{cin>>y.a;
push(y,tag);}
if(tag==2)
{cin>>y.b;
push(y,tag);}
if(tag==3)
{cin>>y.c;
push(y,tag);}
cout<<"\nto continue enter y";cin>>ch;
}while(ch=='y'||ch=='Y');
while(c>0)
{res=pop();
cout<<res.a;c--;
}
}
int stkful()
{
if(s.top==s.size)
return 1;
else
return 0;}
int stkmt()
{if(s.top==-1) 
return 1;
else
return 0;}
void push(u x,int tag)
{if(stkful())
cout<<"stack is full";
else
{s.top++;
if(tag==1)
{s.elements[s.top].a=x.a;s.tag[s.top]=1;}
if(tag==2)
{s.elements[s.top].b=x.b;s.tag[s.top]=2;}
if(tag==3)
{s.elements[s.top].c=x.c;s.tag[s.top]=3;}
}
}
u pop()
{u bla;bla.a=-1;bla.b=0.0,bla.c='\0';
if(stkmt())
{cout<<s.top<<"\nstack is empty";
return bla;}
else
return s.elements[s.top];
s.top--;
}
u peep()
{u bla;bla.a=-1;bla.b=0.0,bla.c='\0';
if(stkmt())
return bla;
else
return s.elements[s.top];
}

