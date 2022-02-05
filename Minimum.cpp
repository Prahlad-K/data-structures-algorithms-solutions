#include <iostream>

using namespace std;

int main()
{
 int a[10];

 for(int i=0;i<10;i++)
 {
     cin>>a[i];
 }

 int m=a[0];int index;
 for(int i=0;i<10;i++)
 {
     if(a[i]<=m)
     {
         m=a[i];
         index=i;
     }
 }
 cout<<m<<" "<<index<<endl;
}
