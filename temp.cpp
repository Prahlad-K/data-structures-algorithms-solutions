#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{int n,x;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
cout<<"X:";
cin>>x;
int s;
for(int l=0;l<n;l++)
{for(int k=0;k<n;k++)
{s=0;
    for(int i=l;i<k;i++)
        s=s+a[i];
    if(s==x)
      {cout<<"found.";exit(1);}

}

}
cout<<"Hi.";

}
