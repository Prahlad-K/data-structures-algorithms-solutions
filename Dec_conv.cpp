#include <iostream>
#include <string>

using namespace std;
string conv(int,int);
string cstr="0123456789ABCDEF";
string s;
int main()
{int m,a; string ans;
cout<<"Enter decimal number:";
cin>>m;
cout<<"Enter base:";
cin>>a;
ans=conv(m,a);
cout<<ans;
}

string conv(int n,int b)
{
if(n<b)
{s=cstr.substr(n,1);
return s;}
else
{return conv(n/b,b)+cstr.substr(n%b,1);}
}
