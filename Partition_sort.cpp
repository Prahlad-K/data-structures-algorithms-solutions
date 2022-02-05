#include <iostream>

using namespace std;

void partial(int a[],int n)
{int temp;
int a1=0,a2=0,a3=0,index=0;

while(index!=n)
{int temp;
if(a1==0)
a1=a[index++];
if(a2==0)
a2=a[index++];

  if(a1<a2)
  {temp=a1;
   a1=a2;
   a2=temp;}

   if(a3==0)
    {a3=a2;
    a2=0;
    }
    else
    {
    if(a3<a2)
    {cout<<a3<<" ";
       a3=a2;
       a2=0;}
    else
    {cout<<a3<<" "<<a1<<"\n";
    a1=a2;
    a2=0;a3=0;}
    }
}}

int main()
{
    int n;
    cout<<"Enter number of numbers:";
    cin>>n;
    int a[n];
    cout<<"Enter array:";
    for(int i=0;i<n;i++)
        cin>>a[i];

    partial(a,n);
}
