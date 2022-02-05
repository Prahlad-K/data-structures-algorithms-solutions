#include <iostream>
using namespace std;
struct stack{
int t=-1;
int elem[15];
}s1,s2;
int pop(int);
int top(int);
void push(int,int);
int sempty(int);
int sfull(int);

int main()
{int n;
    cout<<"Enter the number of numbers:";
cin>>n;
int a[n];
cout<<"Enter the numbers:\n";
for(int i=0;i<n;i++)
    cin>>a[i];

for(int i=0;i<n;i++)
    push(a[i],1);


int b,k;
for(int i=0;i<n;i++)
{b=pop(1);
for(int j=0;j<n-1-i;j++)
{if(b<s1.elem[s1.t])
{k=b;
b=s1.elem[s1.t];
s1.elem[s1.t]=k;}
push(pop(1),2);}

for(int j=0;j<n-1-i;j++)
{push(pop(2),1);}
push(b,2);
}

for(int i=0;i<n;i++)
cout<<pop(2)<<" ";

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

int top(int y)
{if(y==1)
return s1.t;
else
    return s2.t;

}
