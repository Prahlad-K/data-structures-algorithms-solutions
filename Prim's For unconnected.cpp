#include <iostream>
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
          {G[i][j]=1000;}
      }
  }


int minedge=100;
int a,b;
int counter=0;
vertex[index++]=1;
int starting=1;
while(index!=n+1)
{minedge=1000;
for(int i=starting;i<index;i++)
    {for(int j=1;j<=n;j++)
    {
        if(G[vertex[i]][j]<=minedge&&vertex[i]!=j)
        {a=vertex[i];b=j;
            minedge=G[vertex[i]][j];
        }
    }
    }
if(minedge==1000)
{
    cout<<"Minimum spanning tree:\n";
for(int i=starting;i<index;i++)
    cout<<i<<" "<<setarray[i]<<endl;
    starting=index;
}

if(!check(a,b))
{if(minedge!=1000)
union_nums(a,b);
if(!present(a)&&!present(b))
    {vertex[index++]=a;
    vertex[index++]=b;
    }
else if(present(a)&&!present(b))
{vertex[index++]=b;}
else if(present(b)&&!present(a))
{vertex[index++]=a;}
}
G[a][b]=1000;
G[b][a]=1000;
}
cout<<"Minimum spanning tree:\n";
for(int i=starting;i<index;i++)
    cout<<i<<" "<<setarray[i]<<endl;
    starting=index;
}
