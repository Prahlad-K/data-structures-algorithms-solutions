#include <iostream>
using namespace std;
int arr(int[],int,int*,int*);
int main()
{int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
    cin>>a[i];
int sum,ma,mi,*p1,*p2;
p1=&ma;p2=&mi;
*p1=a[0];*p2=a[0];
sum=arr(a,n-1,p1,p2);
double avg=sum/n;
cout<<avg<<" "<<ma<<" "<<mi<<"\n";
}

int arr(int x[],int m,int* p,int *q)
{
if(x[m]>*p)
    *p=x[m];
if(x[m]<*q)
    *q=x[m];
if(m==0)
return x[0];
else
{return(x[m]+arr(x,m-1,p,q));}


}
