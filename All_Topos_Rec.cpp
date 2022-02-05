#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef struct mnode
{
    int key[50];
    struct mnode* ptr[10];
    int size;
}*MTPTR;
MTPTR T=NULL,root=NULL;
queue <MTPTR> q;

typedef struct node
{
    int a[100];
    int siz;
}*NPTR;

stack <NPTR> s;
int n;
int v;
int c[100];
int ctr=0;
int courses[100];

int size;
int last;
 int G[10][10];
int indegree(int i)
{int s=0;
    for(int j=1;j<=n;j++)
    {if(G[j][i]!=-1)
        s=s+G[j][i];
     else
        s=s+0;
    }
    return s;
}

int outdegree(int i)
{int s=0;
    for(int j=1;j<=n;j++)
    {
        s=s+G[i][j];
    }
    return s;
}

void remove_edge(int i)
{
    for(int j=1;j<=n;j++)
    {
        if(G[i][j]>0)
            G[i][j]=-1;
    }
}

void revive_edge(int i)
{
    for(int j=1;j<=n;j++)
    {
        if(G[i][j]==-1)
            G[i][j]=1;
    }
}

int p=0;
void create(MTPTR &T)
{
    if(T==NULL)
    {
        MTPTR N=new mnode;
        int index=1;
        for(int i=1;i<=n;i++)
        {
        if(indegree(i)==0&&outdegree(i)>0)
                N->key[index++]=i;
        }
        //index is the size of the current node.
        for(int i=1;i<index;i++)
            N->ptr[i]=NULL;
        N->size=index;
        T=N;
        if(p==0)
        {
            root=T;p++;
        }
    }

    if(T!=NULL)
    {
        for(int i=1;i<T->size;i++)
        {
            remove_edge(T->key[i]);
            create(T->ptr[i]);
            revive_edge(T->key[i]);
        }

    }
}

/*void level_order(MTPTR T)
{
    MTPTR flag=new mnode;
    flag->key[1]=-1;
    for(int i=1;i<10;i++)
        flag->ptr[i]=NULL;
    q.push(T);
    q.push(flag);
    MTPTR T1;
    while(q.size()!=1)
    {T1=q.front();
    q.pop();
    if(T1->key[1]!=-1)
        {
            for(int i=1;i<T1->size;i++)
                cout<<T1->key[i]<<" ";
            cout<<" ";
            for(int i=1;i<T1->size;i++)
            {if(T1->ptr[i]!=NULL)
                q.push(T1->ptr[i]);
            }
        }
    else
    {cout<<endl;
        q.push(flag);
    }
    }
    q.pop();
}
*/
void print(int *a,int n)
{
    for(int i=1;i<n;i++)
        cout<<a[i]<<" ";
        cout<<last<<" ";
        cout<<endl;

}

bool is_leaf(MTPTR T)
{
    for(int i=1;i<T->size;i++)
    {
        if(T->ptr[i]!=NULL)
            return false;
    }
    return true;
}

int path[100];int ind=1;
void paths(MTPTR T)
{
    if(is_leaf(T))
    {
    print(path,ind);
    }
    else
    {
        for(int i=1;i<T->size;i++)
        {path[ind++]=T->key[i];
        paths(T->ptr[i]);
        ind--;
        }
    }
}
int store[100],index=1;
int res[100],rind=1;
int sizes[100],sizind=1;
void toposort()
{
    if(rind==n+1)
    {for(int i=1;i<rind;i++)
    cout<<res[i]<<" ";
        cout<<endl;
        rind--;
    }
    for(int i=1;i<=n;i++)
    {
        if(indegree(i)==0&&outdegree(i)>0)
            store[index++]=i;
    }
    s.push(store);
    sizes[sizind++]=index;
    for(int i=1;i<index;i++)
    {res[rind++]=i;
    remove_edge(store[i]);
    index=1;
    toposort();
    store=s.top();s.pop();
    index=sizes[--sizeind];
    revive_edge(store[i]);
    }
}

int main()
{cout<<"Enter number of vertices:";
    cin>>n;
    size=n;
    for(int i=1;i<=n;i++)
    { for(int j=1;j<=n;j++)
        {cin>>G[i][j];}
    }

    for(int i=1;i<=n;i++)
    {
        if(outdegree(i)==0)
            last=i;
    }
     //cout<<"Topological sort is:\n";
    //toposort();
    //T=root;
    //level_order(T);
    cout<<endl;
    cout<<"All Topological sorts:"<<endl;
    toposort();
    //T=root;
    //paths(T);
}
