#include <iostream>
using namespace std;

bool is_leap(int);
int main()
{int year,days;
cin>>year;
for(int m=1;m<=12;m++)
{ int month=m;
     switch(m)
    {case 1:cout<<"January \n";break;
     case 2:cout<<"February \n";break;
     case 3:cout<<"March \n";break;
     case 4:cout<<"April \n";break;
     case 5:cout<<"May \n";break;
     case 6:cout<<"June \n";break;
     case 7:cout<<"July \n";break;
     case 8:cout<<"August \n";break;
     case 9:cout<<"September \n";break;
     case 10:cout<<"October \n";break;
     case 11:cout<<"November \n";break;
     case 12:cout<<"December \n";break;
    }


    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    days=31;
    else if(m==2)
    {if(is_leap(year))
    days=29;
    else
    days=28;
    }
    else
    days=30;

    int y=year,ctr=0;
    if(m==1||m==2)
    {m=m+12;y=y-1;}
    int N;int d=1;
    N=d+2*m+(3*m+3)/5+y+y/4-y/100+y/400+2;
    int n=N%7;
    if(n==0)
        n=7;
    for(int i=1;i<=7;i++)
    {switch(i)
     {
     case 1:cout<<"Su ";break;
     case 2:cout<<"M0 ";break;
     case 3:cout<<"Tu ";break;
     case 4:cout<<"We ";break;
     case 5:cout<<"Th ";break;
     case 6:cout<<"Fr ";break;
     case 7:cout<<"Sa ";break;
    }
    if(i<n)
    {cout<<"  ";
    for(int d=8-n+i;d<=days;d+=7)
    cout<<d<<" ";
    cout<<"\n";}
    else
    {for(int d=i-n+1;d<=days;d+=7)
    cout<<d<<" ";
    cout<<"\n";}
    }
     m=month;
    }
}

bool is_leap(int x)
{
    if(x%4==0)
    {if(x%100==0)
    {if(x%400==0)
    return true;
    else
    return false;}
    else
    return true;}
    else
    return false;
}



