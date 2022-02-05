#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char alpha[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

typedef struct ctnode
{
    int flag;
    int count=0;
    union u
    {
      struct ctnode *ptr[27];
        char *data;
    }info;
    struct ctnode *parent;

}*CTPTR;
CTPTR T=NULL,root=NULL;
queue <CTPTR> q;
int n=26;
CTPTR givenode(int f)
{
    CTPTR N=new ctnode;
    if(f==0)
    {
        N->flag=0;
        for(int i=0;i<n;i++)
            N->info.ptr[i]=NULL;
    }
    else
    {
        N->flag=1;
        N->info.data=new char;
        N->info.data[0]='\0';
    }
    return N;
}

int pos(char c)
{
    for(int i=0;i<26;i++)
    {
        if(c==alpha[i])
            return i;
    }
}

int findcommon(char* c1,char* c2)
{
    int ctr=0;
    for(int i=0;i<min(strlen(c1),strlen(c2));i++)
    {
        if(c1[i]==c2[i])
            ctr++;
    }
    cout<<ctr<<" is the number of common letters.\n";
    return ctr;
}

void parentize(CTPTR &T)
{
    if(T!=NULL)
    {
        if(T->flag==0)
       {for(int i=0;i<n;i++)
        {if(T->info.ptr[i]!=NULL)
        T->info.ptr[i]->parent=T;
        }
        for(int i=0;i<n;i++)
        parentize(T->info.ptr[i]);
       }
    }
}
int p=0;
void create(CTPTR &T,char *enter)
{CTPTR leaf;
leaf=givenode(1);
leaf->info.data=strcat(leaf->info.data,enter);
    if(T==NULL)
    {
        CTPTR N=givenode(0);
        T=N;
        if(p==0)
        {root=T;
        root->parent=NULL;p++;}
    }
    if(T!=NULL)
    {
    if(T->info.ptr[pos(enter[0])]==NULL)
         {
        T->info.ptr[pos(enter[0])]=leaf;
         }
    else
        {
            //right-away child.
            CTPTR child=T->info.ptr[pos(enter[0])];
            if(child->flag==1)//which means child is leaf.
            {
            int common=findcommon(enter,child->info.data);

             CTPTR newindex;
             newindex=givenode(0);
             newindex->count=common;//increasing count.

             if(common==strlen(leaf->info.data))//leaf is substring.
            {newindex->info.ptr[pos(child->info.data[common])]=child;//putting the previous child into new index.
             newindex->info.ptr[26]=leaf;}
            if(common==strlen(child->info.data))
             {newindex->info.ptr[pos(leaf->info.data[common])]=leaf;//putting the previous child into new index.
             newindex->info.ptr[26]=child;}

            else if(common<strlen(leaf->info.data))//leaf is bigger.
            {newindex->info.ptr[pos(child->info.data[common])]=child;//putting the previous child into new index.
             newindex->info.ptr[pos(leaf->info.data[common])]=leaf;}//putting the leaf in it's rightful place.

             T->info.ptr[pos(enter[0])]=newindex;
             }
             else if(child->flag==0)
             {

                 int common;
                 common=findcommon(child->info.ptr[26]->info.data,enter);
                 while(child->info.ptr[pos(enter[common])]!=NULL&&common==child->count)
                 {if(child->info.ptr[pos(enter[common])]->flag!=0)
                 {common=findcommon(child->info.ptr[pos(enter[common])]->info.data,enter);
                    CTPTR newindex=givenode(0);
                    newindex->count=common;
                    newindex->info.ptr[26]=child->info.ptr[pos(enter[common])];
                    newindex->info.ptr[pos(enter[common])]=leaf;
                    child->info.ptr[pos(enter[common-1])]=newindex;
                    newindex->parent=child;
                 break;}

                    child=child->info.ptr[pos(enter[common])];
                  common=findcommon(child->info.ptr[26]->info.data,enter);
                 }
                 if(common==child->count)
                 {child->info.ptr[pos(enter[common])]=leaf;}

                 else if(common==strlen(enter))
                 {int wp;
                    CTPTR newindex=givenode(0);
                    newindex->count=common;
                    newindex->info.ptr[26]=leaf;
                    newindex->info.ptr[pos(child->info.ptr[26]->info.data[common])]=child;
                    newindex->parent=child->parent;
                    if(newindex->parent->info.ptr[26]==NULL)
                        wp=0;
                    else
                        wp=strlen(newindex->parent->info.ptr[26]->info.data);
                    newindex->parent->info.ptr[pos(enter[wp])]=newindex;
                    child->parent=newindex;
                 }
             }
        }
    }
}

void level_order(CTPTR T)
{
    q.push(T);
    CTPTR F=new ctnode;
    F->flag=-1;
    q.push(F);
    CTPTR T1;
    while(q.size()!=1)
    {T1=q.front();
    q.pop();
        if(T1->flag!=-1)
        {
            if(T1->flag==0)
            {cout<<T1->count<<"\n";
                for(int i=0;i<n;i++)
                {if(T1->info.ptr[i]!=NULL)
                {cout<<alpha[i]<<" ";
                q.push(T1->info.ptr[i]);}}
            if(T1->info.ptr[26]!=NULL)
                cout<<"node->"<<T1->info.ptr[26]->info.data<<" ";
            }
            else
            cout<<T1->info.data<<" ";
        }
        else
        {
            cout<<endl;
            q.push(F);
        }
    }
}

int main()
{
    char ch;
    char *enter;
    enter=new char;
    do
    {
        cout<<"Enter word:";
        cin>>enter;
        create(T,enter);
        T=root;
        parentize(T);
        cout<<"Enter:";
        cin>>ch;
    }while(ch!='n');
    T=root;
    level_order(T);
}
