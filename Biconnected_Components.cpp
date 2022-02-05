#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
int n,G[100][100];int count=1;
struct edge
{int u,v;
};
stack <edge> s;
int ctr=0;edge e;

void poproper(int x,int y)
{
    edge temp;
    temp=s.top();
    s.pop();
    while(temp.u!=x&&temp.v!=y)
    {
        cout<<temp.u<<" "<<temp.v<<endl;
        temp=s.top();
        s.pop();
    }
    cout<<temp.u<<" "<<temp.v<<endl;
        cout<<endl;
}
void printstack()
{
    while(s.size()!=0)
    {cout<<s.top().u<<" "<<s.top().v<<endl;s.pop();}
}

void DFT(int current,int *visit,int *num,int *low,int *parent)
{
    visit[current]=1;
    num[current]=count++;
    for(int i=1;i<=n;i++)
    {
        if(G[current][i]>0&&visit[i]==0)
        {
            parent[i]=current;
            e.u=current;e.v=i;
            s.push(e);
            DFT(i,visit,num,low,parent);
        }
    }
    low[current]=num[current];
    for(int i=1;i<=n;i++)
    {
        if(G[current][i]>0&&visit[i]==1&&i!=parent[current]&&num[current]>num[i])
        {low[current]=min(num[current],num[i]);e.u=current;e.v=i;s.push(e);}
    }

    for(int i=1;i<=n;i++)
    {
        if(G[current][i]>0&&visit[i]==1&&parent[i]==current)
        low[current]=min(low[current],low[i]);

    }
    if(parent[current]!=0)
    {if(low[current]>=num[parent[current]])
        poproper(parent[current],current);}

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
printstack();
}
