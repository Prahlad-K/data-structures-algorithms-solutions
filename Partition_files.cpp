#include <iostream>
#include <fstream>

using namespace std;

int mer[40];

void merge2(int *a1,int n1,int *a2,int n2)
{int i=0,j=0,index=0;

while(i<n1&&j<n2)
{
    if(a1[i]<a2[j])
    mer[index++]=a1[i++];
    else
    mer[index++]=a2[j++];
}
while(i<n1)
{
    mer[index++]=a1[i++];
}

while(j<n2)
{
    mer[index++]=a2[j++];
}


}

int main()
{
    fstream f1,f2;
    f1.open("File1.txt",ios::in|ios::out);
    f2.open("File2.txt",ios::in|ios::out);

    int *a1,*a2;
    a1=new int;
    a2=new int;
    int i=0,j=0;
    while(!f1.eof())
    {f1>>a1[i++];}//all sorted partitions into a1;

    while(!f2.eof())
    {f2>>a2[j++];}//all sorted partitions into a2;

    int part[20][20];int partno=0,index=0;
    int sizes[20];
    for(int k=0;k<i;k++)
    {if(k!=i-1)
    {if(a1[k]<a1[k+1])
    {part[partno][index++]=a1[k];}
    else
    {part[partno][index]=a1[k];sizes[partno]=index+1;partno++;index=0;}
    }
    else
    {part[partno][index++]=a1[k];
    sizes[partno]=index;partno++;index=0;}
    }//saves all partitions into the array.


    for(int k=0;k<j;k++)
    {if(k!=j-1)
    {if(a2[k]<a2[k+1])
    {part[partno][index++]=a2[k];}
    else
    {part[partno][index]=a2[k];sizes[partno]=index+1;partno++;index=0;}
    }
    else
    {part[partno][index++]=a2[k];
    sizes[partno]=index;partno++;}
    }//saves all partitions into the array.



    int arr1[20], arr2[20];
    while(partno!=1)
    {for(int k1=0;k1<partno;k1++)
    {
        for(int i=0;i<sizes[k1];i++)
        arr1[i]=part[k1][i];
        for(int i=0;i<sizes[k1+1];i++)
        arr2[i]=part[k1+1][i];
        merge2(arr1,sizes[k1],arr2,sizes[k1+1]);
        for(int i=0;i<sizes[k1]+sizes[k1+1];i++)
        part[k1][i]=mer[i];
        sizes[k1]=sizes[k1]+sizes[k1+1];

        for(int i=k1+2;i<partno;i++)
        {
            for(int j=0;j<sizes[i];j++)
            {
                part[i-1][j]=part[i][j];
            }
            sizes[i-1]=sizes[i];

        }//all partitions are shifted.
        sizes[partno-1]=0;
        for(int i=0;i<sizes[partno-1];i++)
            part[partno-1][i]=0;
        //last partition is made null.
        partno--;
    }
    }
    cout<<"The sorted partitions from File1.txt and File2.txt have been saved into Merged.txt"<<endl;
    for(int i=0;i<sizes[0];i++)
        cout<<part[0][i]<<" ";

    fstream f3;
    f3.open("Merged.txt",ios::in|ios::out);
    for(int i=0;i<sizes[0];i++)
        f3<<part[0][i]<<" ";

    f1.close();
    f2.close();
    f3.close();
}
