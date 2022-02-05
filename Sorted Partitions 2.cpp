#include <iostream>
#include <fstream>

using namespace std;


void findandshift(int *a,int &s,int min[])
{
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<3;j++)
        {
         if(a[i]==min[j])
         {
             for(int k=0;k<s-1;k++)
                 a[k]=a[k+1];

             a[s-1]=0;s--;
         }
        }
    }
}
int temp;
void sortarray(int* a,int n)
{for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
{if(a[i]<a[j])
{temp=a[i];
a[i]=a[j];
a[j]=temp;}
}
}
}

int main()
{
    fstream f1,f2;
    f1.open("SortedPartitions1.txt",ios::in|ios::out);
    f2.open("SortedPartitions2.txt",ios::in|ios::out);
    int A[3],B[3],*C,*D,min[3];
    int s1=3,s2=3;
    C=new int;D=new int;
    fstream f3,f4;
    int i=0,j=0;int ind=0;

    while(i<3)
    f1>>A[i++];
    while(j<3)
    f2>>B[j++];
    for(int l=0;l<3;l++)
    min[l]=A[l];
    for(int l=0;l<3;l++)
    min[l+3]=B[l];
    sortarray(min,6);
    for(int l=0;l<6;l++)
        cout<<min[l]<<" ";

    C[ind++]=min[0];
    C[ind++]=min[1];
    C[ind++]=min[2];

    findandshift(A,s1,min);
    findandshift(B,s2,min);

    if(s1<3)
    {f1>>A[s1++];}

    if(s2<3)
    {f2>>B[s2++];}

    for(int l=0;l<3;l++)
    {cout<<A[i]<<" ";}

    for(int l=0;l<3;l++)
    {cout<<B[i]<<" ";}

    f1.close();
    f2.close();
    f3.close();
    f4.close();
}
