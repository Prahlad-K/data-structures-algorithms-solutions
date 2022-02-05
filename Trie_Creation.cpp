#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

char alpha[5]={'a','b','c'};

typedef struct trnode
{    int f;
    union u
    {
        struct trnode* ptr[100];
        char* data;
    }info;
struct trnode* parent;
}*TRPTR;
TRPTR T=NULL;
TRPTR start=NULL;

queue <TRPTR> q;
int n=3;
int pos(char c)
{
    for(int i=0;i<n;i++)
    {
        if(c==alpha[i])
            return i;
    }
    return n+1;
}

int findj(char *chi,char *text)
{int ctr=0;
    for(int i=0;i<min(strlen(text),strlen(chi));i++)
    {if(chi[i]==text[i])
    ctr++;
    }
    return ctr;
}

TRPTR createnode(int flag)
{
        TRPTR N=new trnode;
    if(flag==1)
    {
        N->f=1;
        for(int i=0;i<n+1;i++)
            N->info.ptr[i]=NULL;
        return N;
    }
    else
    {N->f=0;
    N->info.data=new char;
    N->info.data[0]='\0';
    return N;
    }

}


int p=0;
void create(TRPTR &T,char* enter)
{TRPTR leaf;
    if(T==NULL)
    {
        T=createnode(1);
        if(p==0)
        {start=T;p++;
        T->parent=NULL;}
    }
    if(T!=NULL)
    {
        if(T->info.ptr[pos(enter[0])]==NULL)
         {leaf=createnode(0);
        leaf->info.data=strcat(leaf->info.data,enter);
        T->info.ptr[pos(enter[0])]=leaf;
        leaf->parent=T;}

        else
        {
            TRPTR trav=T,newindex,store;int i=0;int j;
            while(i<strlen(enter))
                {
                if(trav->f==1)
                    {if(trav->info.ptr[pos(enter[i])]!=NULL)
                    trav=trav->info.ptr[pos(enter[i++])];
                    else
                    {leaf=createnode(0);
                    leaf->info.data=strcat(leaf->info.data,enter);
                    trav->info.ptr[pos(enter[i])]=leaf;
                    leaf->parent=trav;
                    break;}
                    }
                if(trav->f==0)
                {
                    if(strlen(trav->info.data)<strlen(enter))
                    {store=createnode(0);
                    store->info.data=strcat(store->info.data,trav->info.data);

                    j=findj(trav->info.data,enter);

                    cout<<j<<" is j.\n";
                    while(i<=j)
                    {leaf=createnode(0);
                     leaf->info.data=strcat(leaf->info.data,enter);
                     newindex=createnode(1);
                     leaf->parent=newindex;
                     newindex->info.ptr[pos(enter[i])]=leaf;
                     trav->parent->info.ptr[pos(enter[i-1])]=newindex;
                     if(i==strlen(store->info.data))
                        {newindex->info.ptr[n]=store;
                        cout<<store->info.data<<" store data.\n";}
                     newindex->parent=trav->parent;
                     trav=newindex->info.ptr[pos(enter[i])];
                     cout<<trav->info.data<<" trav data.\n";
                     cout<<i<<"i\n";
                     i++;
                    cout<<"Created\n";
                    }
                    break;
                    }
                    else if(strlen(trav->info.data)>strlen(enter))
                    {store=createnode(0);
                    store->info.data=strcat(store->info.data,enter);

                    j=findj(trav->info.data,enter);

                    cout<<j<<" is j.\n";
                    while(i<=j)
                    {leaf=createnode(0);
                     leaf->info.data=strcat(leaf->info.data,trav->info.data);
                     newindex=createnode(1);
                     leaf->parent=newindex;
                     newindex->info.ptr[pos(trav->info.data[i])]=leaf;
                     trav->parent->info.ptr[pos(trav->info.data[i-1])]=newindex;
                     if(i==strlen(store->info.data))
                        {newindex->info.ptr[n]=store;
                        cout<<store->info.data<<" store data.\n";}
                     newindex->parent=trav->parent;
                     trav=newindex->info.ptr[pos(trav->info.data[i])];
                     cout<<trav->info.data<<" trav data.\n";
                     cout<<i<<"i\n";
                     i++;
                    cout<<"Created\n";
                    }
                    cout<<trav->info.data<<"\n";
                    break;
                    }
                    else
                    {store=createnode(0);
                    store->info.data=strcat(store->info.data,trav->info.data);

                    j=findj(trav->info.data,enter);

                    cout<<j<<" is j.\n";
                    while(i<=j)
                    {leaf=createnode(0);
                     leaf->info.data=strcat(leaf->info.data,enter);
                     newindex=createnode(1);
                     leaf->parent=newindex;
                     newindex->info.ptr[pos(enter[i])]=leaf;
                     trav->parent->info.ptr[pos(enter[i-1])]=newindex;
                     if(i==j)
                        {newindex->info.ptr[pos(store->info.data[i])]=store;
                        cout<<store->info.data<<" store data.\n";}
                     newindex->parent=trav->parent;
                     trav=newindex->info.ptr[pos(enter[i])];
                     cout<<trav->info.data<<" trav data.\n";
                     cout<<i<<"i\n";
                     i++;
                    cout<<"Created\n";
                    }
                    break;
                    }
                }
            }
        }
    }
}

void level_order(TRPTR T)
{
    q.push(T);
    TRPTR flag=new trnode;
    flag->f=-1;
    q.push(flag);
    TRPTR T1;
    while(q.size()!=1)
    {T1=q.front();
    q.pop();
    if(T1->f!=-1)
    {
        if(T1->f==1)
        {cout<<"Index node. ";
            for(int i=0;i<n;i++)
                {if(T1->info.ptr[i]!=NULL)
                {q.push(T1->info.ptr[i]);}
                }
        if(T1->info.ptr[n]!=NULL)
            cout<<T1->info.ptr[n]->info.data<<" ";
        }
        else
        cout<<T1->info.data<<" ";
    }
    else
    {cout<<"\n";q.push(flag);}
    }
    q.pop();
}
int main()
{   char* enter;char ch;
    enter=new char;
    cout<<"Enter?:";
    cin>>ch;
    while(ch!='n')
    {cout<<"Enter the string to be inserted into trie:";
    cin>>enter;
    cout<<strlen(enter)<<" is the str length.\n";
    create(T,enter);
    T=start;
    cout<<"Enter?:";
    cin>>ch;
    }
    level_order(T);
}
