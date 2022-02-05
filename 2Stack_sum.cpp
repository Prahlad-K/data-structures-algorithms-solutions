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

bool sum_2(int n,int n1,int n2)
{int a1=pop(1),a2=pop(2);
    if(a1+a2==n)
        return true;
    else if(sempty(2)==1)
    {s2.t=n2-1;
        return sum_2(n,n1,n2);}
    else if(sempty(1)==1)
    {s1.t=n1-1;
        return false;}
    else
    {push(a1);
    return(sum_2(n,n1,n2));
    }
}
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
push(num,2);}
int num;
cout<<"Enter number sum to search:";
cin>>num;
sum_2(num,n1,n2);














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
