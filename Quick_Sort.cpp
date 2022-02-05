#include <iostream>
using namespace std;
int A[100];
int n;
int partition(int low,int high)
{int p,l,h;
p=A[low];
l=low+1;
h=high;
int temp;
    while(l<=h)
    {
    if(p>A[l])
        l++;
    else if(p<A[h])
        h--;
    else
    {temp=A[h];
    A[h]=A[l];
    A[l]=temp;}
    }
    temp=A[h];
    A[h]=A[low];
    A[low]=temp;
    return h;
}
int j;
void quicksort(int low,int high)
{
    if(low<high)
    {j=partition(low,high);
    quicksort(low,j-1);
    quicksort(j+1,high);
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>A[i];
cout<<endl;
    quicksort(0,n-1);
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
}
