#include <iostream>
using namespace std;


typedef struct trnode
{
        bool end=false;
        trnode* ptr[26];

}*TRPTR;


TRPTR getNode()
{
    TRPTR newnode = new trnode;
    newnode->end = false;
    for(int i =0;i<26;i++)
        newnode->ptr[i]=NULL;
    return newnode;
}

void insert(TRPTR T, string s)
{
    for(int i =0;i<s.length();i++)
    {
        if(!T->ptr[s[i]-'a'])
        T->ptr[s[i]-'a'] = getNode();
        T = T->ptr[s[i]-'a'];
    }
    T->end = true;
}

char * ans = new char;int ctr =0;

void printstring()
{
    for(int i=0;i<ctr;i++)
        cout<<ans[i];
    cout<<endl;
}
void print(TRPTR T)
{
    if(T)
    {
        if(T->end)
        {
            printstring();
        }
        for(int i =0;i<26;i++)
        {
            if(T->ptr[i])
            {
                ans[ctr++]=char(i+'a');
                print(T->ptr[i]);
                ctr--;
            }
        }
    }
}

bool search(TRPTR T, string s)
{
        int index;
    for(int i =0;i<s.length();i++)
    {
        index = s[i]-'a';
        if(!T->ptr[index])
            return false;
        T = T->ptr[index];
    }

    if(T->end)
    return true;
    else
    return false;

}


int main()
{
    int T;
    string s;
    cin>>T;

    TRPTR root=getNode();

    for(int i =0;i<T;i++)
    {
        cin>>s;
        insert(root, s);
    }
    print(root);
    while(T--)
    {cout<<"\nEnter search string:";
   cin>>s;

    search(root, s) ? cout<<"y" :cout<<"n";
    }


}
