#include <iostream>
#include <cmath>
using namespace std;
int n;
int G[100][100];
int setarray[100];
int vertex[100];
int index=1;
int findroot(int i)
{
    if(setarray[i]==0)
        return i;
    else
        return findroot(setarray[i]);
}

void union_nums(int a,int b)
{
    if(setarray[a]==0)
        setarray[a]=b;
    else if(setarray[b]==0)
        setarray[b]=a;
}

void deunion(int a,int b)
{for(int i=1;i<=n;i++)
{   if(i==a&&setarray[i]==b)
    setarray[i]=0;
    else if(i==b&&setarray[i]==a)
    setarray[i]=0;}
}

bool check(int i,int j)
{
    if(findroot(i)==findroot(j))
        return true;
    else
        return false;
}
bool present(int x)
{
    for(int i=1;i<index;i++)
    {
        if(vertex[i]==x)
            return true;
    }
    return false;
}
int Gmain[100][100];
int main()
{cout<<"Enter the number of vertices:";
cin>>n;
for(int i=1;i<=n;i++)
setarray[i]=0;

for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
        cin>>G[i][j];

  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=n;j++)
      {
          if(G[i][j]==0)
          {G[i][j]=1000;
          G[j][i]=1000;}
      }
  }
for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
        Gmain[i][j]=G[i][j];


int minedge;
int a,b;
int counter=0;
while(counter!=n+1)
{minedge=1000;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        if(G[i][j]<minedge)
        {a=i;b=j;
            minedge=G[i][j];
        }
    }
}
if(!check(a,b))
{union_nums(a,b);
if(!present(a)&&!present(b))
    counter=counter+2;
else
    counter=counter+1;
}
vertex[index++]=a;
vertex[index++]=b;

G[a][b]=1000;
G[b][a]=1000;
}
for(int i=1;i<=n;i++)
    cout<<i<<" "<<setarray[i]<<" "<<Gmain[i][setarray[i]]<<endl;
    int weights[100];int w=1;

for(int i=1;i<=n;i++)
{if(setarray[i]!=0)
weights[w++]=Gmain[i][setarray[i]];}

int MST[100][4];
int mind=1;
for(int i=1;i<=n;i++)
{MST[mind][1]=i;
MST[mind][2]=setarray[i];
MST[mind++][3]=Gmain[i][setarray[i]];
Gmain[i][setarray[i]]=0;
Gmain[setarray[i]][i]=0;}

int mindiff=1000;int p,q,ind,val;
for(int i=1;i<=n;i++)
{for(int j=1;j<=n;j++)
    {if(Gmain[i][j]!=0||Gmain[i][j]!=1000)
        {for(int k=1;k<w;k++)
        {if(abs(Gmain[i][j]-weights[k])<=mindiff)
        {mindiff=abs(Gmain[i][j]-weights[k]);
        p=i;
        q=j;
        val=Gmain[i][j];
        ind=weights[k];
        }}
        }
    }
}
cout<<endl;int prev;
for(int i=1;i<mind;i++)
{
    if(MST[i][3]==ind)
    {a=MST[i][1];
    b=MST[i][2];
    MST[i][3]=val;
    }
}
cout<<a<<"a "<<b<<"b \n";
deunion(a,b);
union_nums(p,q);
cout<<"Second minimum spanning tree:\n";
for(int i=1;i<mind;i++)
cout<<i<<" "<<setarray[i]<<" "<<MST[i][3]<<endl;

}

