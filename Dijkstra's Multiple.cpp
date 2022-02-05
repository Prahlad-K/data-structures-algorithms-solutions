#include <iostream>
#include <stack>
using namespace std;

    int n;
    int v;
int c[100];
int ctr=0;

struct vertex
{int dis=100;
int via=0;
int visit=0;
};
stack <int> S;
int main()
{
    cout<<"Enter number of vertices:";
    cin>>n;
     struct vertex V[10];
     int G[10][10];
    for(int i=1;i<=n;i++)
    { for(int j=1;j<=n;j++)
        {cin>>G[i][j];}
    }
    int s,d;
    cout<<"Enter the source vertex:";
    cin>>s;
    cout<<"Enter destination vertex:";
    cin>>d;
    int c;
    c=s;
    int alt[100][3];
    int ind=1;
    while(c!=d)
    {
        for(int i=1;i<=n;i++)
        {if(G[c][i]>0)
        {
        if(V[i].visit==0)
        {
            if(c==s)
            {V[i].dis=G[c][i];
                V[i].via=c;}
        else if(V[i].dis>(V[c].dis+G[c][i]))
        {V[i].dis=V[c].dis+G[c][i];
        V[i].via=c;}
        else if(V[i].dis==(V[c].dis+G[c][i]))
        {alt[ind][1]=i;
        alt[ind][2]=c;
        ind++;
        }
        }}
        }

 V[c].visit=1;
 int m=V[1].dis;int index;
 for(int i=1;i<=n;i++)
 {
     if(V[i].dis<=m&&V[i].visit==0)
     {
         m=V[i].dis;
         index=i;
     }
 }
 c=index;
}
//shortest path will be in reverse order.
cout<<"Shortest path:\n";
while(c!=s)
{S.push(c);
c=V[c].via;
}
S.push(s);
while(S.size()!=0)
{cout<<S.top()<<" ";
S.pop();
}
cout<<endl;
for(int i=1;i<ind;i++)
{if(d==alt[i][1])
{
V[alt[i][1]].via=alt[i][2];
cout<<"Shortest path:\n";
c=d;
while(c!=s)
{S.push(c);
c=V[c].via;
}
S.push(s);
while(S.size()!=0)
{cout<<S.top()<<" ";
S.pop();
}
cout<<endl;
}}
}
