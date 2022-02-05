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
int p=0;int flagc=0;
void create(TRPTR &T,char* enter)
{TRPTR leaf;
 cout<<flagc<<" flagc.\n";
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
                    {leaf=createnode(0);flagc=1;
                    leaf->info.data=strcat(leaf->info.data,enter);
                    trav->info.ptr[pos(enter[i])]=leaf;
                    leaf->parent=trav;
                    break;}
                    }
                if(trav->f==0)
                {flagc=1;
                    if(strlen(trav->info.data)<strlen(enter))
                    {store=createnode(0);
                    store->info.data=strcat(store->info.data,trav->info.data);

                    j=findj(trav->info.data,enter);

                    cout<<j<<" is j.\n";
                    TRPTR mem;

                    while(i<=j)
                    {leaf=createnode(0);
                     leaf->info.data=strcat(leaf->info.data,enter);
                     newindex=createnode(1);
                     leaf->parent=newindex;
                     newindex->info.ptr[pos(enter[i])]=leaf;
                     trav->parent->info.ptr[pos(enter[i-1])]=newindex;
                     if(i==j&&j==strlen(store->info.data))
                        {newindex->info.ptr[n]=store;
                        cout<<store->info.data<<" store data.\n";}
                     newindex->parent=trav->parent;
                     trav=newindex->info.ptr[pos(enter[i])];
                     cout<<trav->info.data<<" trav data.\n";
                     cout<<i<<"i\n";
                     i++;
                    cout<<"Created\n";
                    mem=leaf->parent;
                    }
                    while(j<strlen(store->info.data))
                    {mem->info.ptr[pos(store->info.data[j])]=store;
                    store->parent=mem;
                    j++;
                    }
                    break;
                    }
                    else if(strlen(trav->info.data)>strlen(enter))
                    {cout<<"My case:\n";
                    store=createnode(0);
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
                     if(i==j)
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

            if(trav->info.ptr[n]==NULL&&flagc==0)
            {cout<<"Incomplete creation.\n";
             TRPTR temp=start;
                for(int j=0;j<strlen(enter);j++)
                    temp=temp->info.ptr[pos(enter[j])];
                leaf=createnode(0);
                leaf->info.data=strcat(leaf->info.data,enter);
                temp->info.ptr[n]=leaf;
                leaf->parent=temp;
            }
        }
    }
}
bool siblings(TRPTR temp)
{TRPTR P=temp->parent;
int ctr=0;
    for(int i=0;i<n;i++)
    {
        if(P->info.ptr[i]!=NULL)
            ctr++;
    }
    if(ctr>=2)
        return true;
    else
        return false;
}
void parentize(TRPTR &T)
{if(T!=NULL&&T->f!=0)
{
    for(int i=0;i<n+1;i++)
    {
        if(T->info.ptr[i]!=NULL)
            T->info.ptr[i]->parent=T;
    }

for(int i=0;i<n+1;i++)
    parentize(T->info.ptr[i]);
}

}

int flag=0,ctr=0;TRPTR rem,temp;int index;
void deletenode(TRPTR T,char* del,int i)
{
if(i<strlen(del))
   {if(T->info.ptr[pos(del[i])]!=NULL)
   {
       if(T->info.ptr[pos(del[i])]->f==0)
        {
            if(strcmp(T->info.ptr[pos(del[i])]->info.data,del)==0)
                {T->info.ptr[pos(del[i])]=NULL;
                ctr=0;
                for(int j=0;j<n+1;j++)
                {if(T->info.ptr[j]!=NULL)
                        ctr++;}
                if(ctr==0)
                {
                    T->parent->info.ptr[pos(del[i-1])]=NULL;
                }
                else if(ctr==1&&T->info.ptr[n]!=NULL)
                {cout<<"Side node remains.\n";
                    rem=T->info.ptr[n];//definitely a leafy.
                    temp=T;
                    index=strlen(rem->info.data)-1;
                while(temp->parent->info.ptr[n]==NULL&&index>=1&&temp->parent!=start&&!siblings(temp))
                    {temp=temp->parent;index--;}
                    cout<<index<<" index.\n";
                    if(temp->parent!=start)
                {temp->parent->info.ptr[pos(rem->info.data[index])]=rem;
                rem->parent=temp->parent;}
                    else
                {temp->parent->info.ptr[pos(rem->info.data[index-1])]=rem;
                rem->parent=temp->parent;}

                }
                else if(ctr==1&&T->info.ptr[n]==NULL&&T!=start)
                {cout<<"Sibling node remains.\n";
                for(int j=0;j<n+1;j++)
                {if(T->info.ptr[j]!=NULL)
                        rem=T->info.ptr[j];}

                if(rem->f!=1)
                {int p=findj(rem->info.data,del);
                 TRPTR temp=rem;
                 int k=0;
                 parentize(start);
                 while(k<=p&&temp->parent->info.ptr[n]==NULL&&!siblings(temp))
                 {temp=temp->parent;
                 k++;
                 }

                 TRPTR f=start;int position=0;
                 while(f!=temp)
                    f=f->info.ptr[pos(rem->info.data[position++])];
                 temp->parent->info.ptr[pos(rem->info.data[position-1])]=rem;
                 rem->parent=temp->parent;}
                }
                }
            else
                {cout<<"Given string does not exist.\n";flag=1;}
        }
        else
        {
          deletenode(T->info.ptr[pos(del[i])],del,i+1);
        }
   }
    else
        {cout<<"Given string does not exist.\n";flag=1;}
   }
   else
    {if(flag==0)
    {cout<<"Deletion incomplete.\n";
    TRPTR trav=start;
    int j=0;
    while(j<i)
        trav=trav->info.ptr[pos(del[j++])];
   ctr=0;
    if(trav->info.ptr[n]!=NULL)
        {index=strlen(trav->info.ptr[n]->info.data);
        trav->info.ptr[n]=NULL;
         for(int j=0;j<n;j++)
         {if(trav->info.ptr[j]!=NULL)
                ctr++;}

            if(ctr==1)
            {
                for(int j=0;j<n;j++)
                {
                    if(trav->info.ptr[j]!=NULL)
                        rem=trav->info.ptr[j];
                }
                 temp=trav;
                if(rem->f==0)
                {j=strlen(rem->info.data)-1;
                while(temp->parent->info.ptr[n]==NULL&&temp->parent!=start&&!siblings(temp))
                    {temp=temp->parent;}
                if(temp->parent!=start)
                temp->parent->info.ptr[pos(rem->info.data[index])]=rem;
                else
                temp->parent->info.ptr[pos(rem->info.data[0])]=rem;
                rem->parent=temp->parent;}
            }
         }
    else
    cout<<"Given string does not exist.\n";}
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
        {
            for(int i=0;i<n;i++)
                {if(T1->info.ptr[i]!=NULL)
                {cout<<i<<" ";
                q.push(T1->info.ptr[i]);}
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
{   char* enter;char* del;char ch;
    del=new char;
    enter=new char;
    cout<<"Enter?:";
    cin>>ch;
    while(ch!='n')
    {cout<<"Enter the string to be inserted into trie:";
    cin>>enter;
    cout<<strlen(enter)<<" is the str length.\n";
    create(T,enter);
    T=start;
    flagc=0;
    cout<<"Enter?:";
    cin>>ch;
    }
    level_order(T);
    cout<<endl;
      cout<<"Delete?:";
    cin>>ch;
    while(ch!='n')
    {cout<<"Enter the string you want to delete:";
    cin>>del;
    T=start;
    deletenode(T,del,0);
    T=start;
    level_order(T);
cout<<endl;
    cout<<"Delete?:";
    cin>>ch;}
}
