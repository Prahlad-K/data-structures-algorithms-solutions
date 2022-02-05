#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char alpha[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

typedef struct crnode
{
    int ind;
    struct crnode* ptr[26];
}*CRPTR;
CRPTR C=NULL;CRPTR root=NULL;
int n=26;
queue <CRPTR> q;
int pos(char c)
{
    for(int i=0;i<n;i++)
    {
        if(c==alpha[i])
            return i;
    }
    return n+1;
}

void create(CRPTR& C,char *enter)
{
    int i=0;
    if(C==NULL)
    {
        CRPTR N=new crnode;
        for(int i=0;i<n;i++)
            N->ptr[i]=NULL;
        N->ind=0;
        C=N;
        root=C;
    }
    while(i<strlen(enter)-1)
    {
        if(C->ptr[pos(enter[i])]==NULL)
        {CRPTR N=new crnode;
        N->ind=0;
        for(int i=0;i<n;i++)
            N->ptr[i]=NULL;
        C->ptr[pos(enter[i])]=N;
        }
        C=C->ptr[pos(enter[i])];
        i++;
    }
    CRPTR N=new crnode;
    N->ind=1;
    for(int i=0;i<n;i++)
    {
        N->ptr[i]=NULL;
    }
    if(C->ptr[pos(enter[i])]==NULL)
    C->ptr[pos(enter[i])]=N;
    else if(C->ptr[pos(enter[i])]->ind==0)
        C->ptr[pos(enter[i])]->ind=1;
}

void level_order(CRPTR C)
{
    q.push(C);
    CRPTR flag=new crnode;
    flag->ind=-1;
    q.push(flag);
    CRPTR T1;
    while(q.size()!=1)
    {T1=q.front();
    q.pop();
    if(T1->ind!=-1)
    {if(T1->ind==1)
    cout<<T1->ind<<" ";
            for(int i=0;i<n;i++)
                {if(T1->ptr[i]!=NULL)
                {cout<<alpha[i]<<" ";
                q.push(T1->ptr[i]);}
                }
    }
    else
    {cout<<"\n";q.push(flag);}
    }
    q.pop();
}

void printwords(CRPTR C,char *add,int ctr)
{
    if(C!=NULL)
    {
        if(C->ind==1)
           {for(int i=0;i<ctr;i++)
            cout<<add[i];
            cout<<endl;}

        for(int i=0;i<n;i++)
            {
                if(C->ptr[i]!=NULL)
                {add[ctr++]=alpha[i];
                printwords(C->ptr[i],add,ctr);
                    ctr--;
                }
            }
    }
}

bool searchwords(CRPTR C,char* sear,int i)
{
    if(C==NULL)
    return false;
    else
    {if(i<strlen(sear))
    {searchwords(C->ptr[pos(sear[i])],sear,i+1);}
    else
    {
        if(C->ind==1)
            return true;
        else
            return false;
    }}
}

int main()
{   char ch;
    char *enter=new char;
    char *sear=new char;
    do
    {cout<<"Enter the string to be inserted into trie:";
    cin>>enter;
    cout<<strlen(enter)<<" is the str length.\n";
    create(C,enter);
    C=root;
    cout<<"Enter?:";
    cin>>ch;
    }while(ch!='n');
    C=root;
    level_order(C);
    cout<<endl;
    C=root;
    char *add;
    add=new char;
    cout<<"All words are:\n";
    printwords(C,add,0);
    C=root;
    do
    {
    cout<<"Enter the word you want to search:";
    cin>>sear;
    if(searchwords(C,sear,0))
        cout<<"Found!";
    else
        cout<<"Not found!";
        cout<<endl;
    cout<<"Continue?:";
    cin>>ch;
    }while(ch!='n');
}
