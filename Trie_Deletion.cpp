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
        start=T;
        T->parent=NULL;
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
                {if(trav->f==1)
                    trav=trav->info.ptr[pos(enter[i++])];
                else
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
                    else
                    {store=createnode(0);
                    store->info.data=strcat(store->info.data,enter);

                    char* d=new char;
                    d[0]='\0';
                    d=strcat(d,trav->info.data);
                    cout<<d<<" is d\n";

                    j=findj(trav->info.data,enter);
                    cout<<j<<" is j.\n";
                    while(i<=j)
                    {
                        leaf=createnode(0);
                     leaf->info.data=strcat(leaf->info.data,d);
                     newindex=createnode(1);
                     leaf->parent=newindex;
                     newindex->info.ptr[pos(enter[i])]=leaf;
                     cout<<leaf->info.data<<" leaf data\n";
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
                }
            }
        }
    }
}

void deletenode(TRPTR T,char* del,int i)
{
if(i<strlen(del))
   {if(T->info.ptr[pos(del[i])]!=NULL)
   {
       if(T->info.ptr[pos(del[i])]->f==0)
        {
            if(strlen(T->info.ptr[pos(del[i])]->info.data)==strlen(del))
                T->info.ptr[pos(del[i])]=NULL;
            else
                cout<<"Given string does not exist.\n";
        }
        else
        {
          deletenode(T->info.ptr[pos(del[i])],del,i+1);
        }

   }
    else
        cout<<"Given string does not exist.\n";
   }
   else
    cout<<"Given string does not exist.\n";
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
                {q.push(T1->info.ptr[i]);}}
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
{   char* enter; char* del;char ch;
    enter=new char;
    del=new char;
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
    cout<<"Delete?:";
    cin>>ch;
    while(ch!='n')
    {cout<<"Enter the string you want to delete:";
    cin>>del;
    T=start;
    deletenode(T,del,0);
    T=start;
    level_order(T);
    cout<<"Delete?:";
    cin>>ch;}
}
