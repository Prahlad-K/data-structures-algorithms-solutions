#include <iostream>
#include <cmath>
using namespace std;
int n,G[100][100];int count=1;
int ctr=0;
void DFT(int current,int *visit,int *num,int *low,int *parent)
{
    visit[current]=1;
    num[current]=count++;
    for(int i=1;i<=n;i++)
    {
        if(G[current][i]>0&&visit[i]==0)
        {
            parent[i]=current;
            DFT(i,visit,num,low,parent);
        }
    }
    low[current]=num[current];
    //all back edges.
    for(int i=1;i<=n;i++)
    {
        if(G[current][i]>0&&visit[i]==1&&i!=parent[current]&&num[current]>num[i])
        low[current]=min(num[current],num[i]);
    }

    //all tree edges.
    for(int i=1;i<=n;i++)
    {
        if(G[current][i]>0&&visit[i]==1&&parent[i]==current)
        low[current]=min(low[current],low[i]);

    }

    if(parent[current]!=0)
    {if(low[current]>=num[parent[current]]&&parent[parent[current]]!=0)
        cout<<parent[current]<<" ";}
    else
    {
        for(int j=1;j<=n;j++)
            if(parent[j]==current)
                ctr++;

        if(ctr>1)
            cout<<current<<" ";
    }

}

int main()
{
 cout<<"Enter number of vertices:";
    cin>>n;
    int num[n];
    int parent[n];
    int visit[n];
    for(int i=1;i<=n;i++)
        visit[i]=0;
        //initially no vertex is visited.
int low[n];
for(int i=1;i<=n;i++)
{
    low[i]=1000;
}//making all low values to infinity.
for(int i=1;i<=n;i++)
    parent[i]=0;
//making all parent values as zeros.
for(int i=1;i<=n;i++)
{for(int j=1;j<=n;j++)
cin>>G[i][j];
}
DFT(1,visit,num,low,parent);

}
