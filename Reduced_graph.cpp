#include <iostream>
using namespace std;
int n,start;
int visit[100];
int vertnum[100];
int num=1;
int G[100][100];
void DFT(int current,int *visit)
{
    visit[current]=1;
    for(int i=1;i<=n;i++)
    {if(G[current][i]>0&&visit[i]==0)
    DFT(i,visit);
    }
    vertnum[current]=num++;
}

void compnum()
{
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)
            DFT(i,visit);
    }
}
int temp[100][100];
void reverse_graph()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {if(G[i][j]>0)
        {temp[j][i]=1;
        G[i][j]=0;
        }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(temp[i][j]>0)
                {G[i][j]=1;}
        }
    }
}
int store[100][100];
int sizes[100];
int pos=1,index=1;
void DFTprint(int current,int *visit)
{

    store[pos][index++]=current;
    visit[current]=1;
    for(int i=1;i<=n;i++)
    {if(G[current][i]>0&&visit[i]==0)
    DFTprint(i,visit);
    }
}

void printall()
{
    for(int i=1;i<=n;i++)
        visit[i]=0;

    int max=0;int s;
for(int i=1;i<=n;i++)
{
    if(visit[i]==0)
    {max=0;

    for(int i=1;i<=n;i++)
    {
        if(vertnum[i]>max&&visit[i]==0)
           {max=vertnum[i];
           s=i;}
    }
    vertnum[s]=0;

        DFTprint(s,visit);
        sizes[pos++]=index;
        index=1;
}
}
}

int redG[100][100];

void givered()
{int single[100];
int singind=1;
for(int i=1;i<pos;i++)
{if(sizes[i]==2)
single[singind++]=store[i][1];}

for(int i=1;i<singind;i++)
{ for(int j=1;j<singind;j++)
    { if(G[single[i]][single[j]]>0)
            redG[single[i]][single[j]]=1;
    }
}

for(int i=1;i<pos;i++)
{for(int j=1;j<pos;j++)
{if(i!=j)
{for(int k=1;k<sizes[i];k++)
{for(int l=1;l<sizes[i];l++)
    {if(G[store[i][k]][store[j][l]]>0)
    {redG[store[i][1]][store[j][1]]=1;}
     if(G[store[j][l]][store[i][k]]>0)
    {redG[store[j][1]][store[i][1]]=1;}}
}}}}

cout<<"Reduced graph is:\n";
for(int i=1;i<=n;i++)
{ for(int j=1;j<=n;j++)
    cout<<redG[i][j]<<" ";
    cout<<endl;
}
for(int i=1;i<=n;i++)
{for(int j=1;j<=n;j++)
    {if(redG[i][j]>0)
     cout<<i<<" "<<j<<"\n";}
}

}
int Gmain[100][100];
int main()
{

    cout<<"Enter number of vertices:";
    cin>>n;

    for(int i=1;i<=n;i++)
        visit[i]=0;
    for(int i=1;i<=n;i++)
    { for(int j=1;j<=n;j++)
        {cin>>G[i][j];}
    }

    for(int i=1;i<=n;i++)
    { for(int j=1;j<=n;j++)
        {Gmain[i][j]=G[i][j];}
    }

   start=1;
    DFT(start,visit);
    compnum();
    reverse_graph();
    printall();
    for(int i=1;i<=n;i++)
    { for(int j=1;j<=n;j++)
        {G[i][j]=Gmain[i][j];}
    }
    givered();
}
