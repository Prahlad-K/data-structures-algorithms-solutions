#include <iostream>
using namespace std;
struct stack{
int t=-1;
int elem[15];
}s1,s2;
int pop(int);
void push(int,int);
int sempty(int);
int sfull(int);

int main()
{int n1,n2;
cout<<"Enter number of elements in stack1:";
cin>>n1;
cout<<"Enter number of elements in stack2:";
cin>>n2;
cout<<"Enter elements of stack1:\n";
int num;
for(int i=0;i<n1;i++)
{cin>>num;
push(num,1);
}
cout<<"Enter elements of stack2:\n";
for(int i=0;i<n2;i++)
{cin>>num;
push(num,2);
}
int a[n1+n2];
for(int i=0;i<n1;i++)
{a[i]=pop(1);}

for(int i=n1+n2-1;i>=n1;i--)
{a[i]=pop(2);}

char ch;
int p;
cout<<"Perform operations on which stack?:1 or 2:";
cin>>p;
if(p==1)
{cout<<"Do you want to pop?:";
cin>>ch;
int ctr=0;
while(ch=='Y'||ch=='y')
{cout<<a[ctr]<<"\n";ctr++;
if(ctr==n1)
break;
cout<<"Do you want to pop?:";
cin>>ch;
}
}
if(p==2)
{cout<<"Do you want to pop?:";
cin>>ch;
int ctr=n1+n2-1;
while(ch=='Y'||ch=='y')
{cout<<a[ctr]<<"\n";ctr--;
if(ctr==n1-1)
break;
cout<<"Do you want to pop?:";
cin>>ch;
}
}


}
void push(int x,int y)
{if(y==1)
{if(sfull(1)==1)
cout<<"Stack1 is full!";
else
{s1.elem[++s1.t]=x;}
}
if(y==2)
{if(sfull(2)==1)
cout<<"Stack2 is full!";
else
{s2.elem[++s2.t]=x;}
}
}

int pop(int y)
{if(y==1)
{if(sempty(1)==1)
cout<<"Stack1 is empty!";
else
{return (s1.elem[s1.t--]);}
}
if(y==2)
{if(sempty(2)==1)
cout<<"Stack2 is empty!";
else
{return (s2.elem[s2.t--]);}
}
}
int sempty(int y)
{if(y==1)
{if(s1.t==-1)
return 1;
else
return 0;
}
if(y==2)
{if(s2.t==-1)
return 1;
else
return 0;
}}

int sfull(int y)
{if(y==1)
{if(s1.t==15)
return 1;
else
return 0;
}
if(y==2)
{if(s2.t==15)
return 1;
else
return 0;
}}
