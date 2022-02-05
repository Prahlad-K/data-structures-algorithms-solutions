#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
typedef struct bnode
{    char data;
    int freq;
    bnode *lc,*mc,*rc;
}*BTPTR;
vector <BTPTR> v;

bool compare(BTPTR &a,BTPTR &b)
{if(a->freq<b->freq)
return true;
else
return false;
}
queue<BTPTR> q;
BTPTR flag,T1;

void level_order(BTPTR T)
{flag=new bnode;
flag->data='*';flag->lc=NULL;flag->mc=NULL;flag->rc=NULL;
    q.push(T);q.push(flag);
   while(q.size()!=1)
   {T1=q.front();
   q.pop();
   if(T1->data!='*')
   {cout<<T1->data;
   if(T1->lc!=NULL)
     q.push(T1->lc);
   if(T1->mc!=NULL)
     q.push(T1->mc);
   if(T1->rc!=NULL)
    q.push(T1->rc);}
   else
   {q.push(T1);cout<<"\n";}
   }
}

void create_huffman()
{BTPTR a,b,c,T;
while(v.size()!=1)
{a=v[0];
b=v[1];
c=v[2];
v.erase(v.begin());
v.erase(v.begin());
v.erase(v.begin());
T=new bnode;
T->lc=a;
T->mc=b;
T->rc=c;
T->data='-';
T->freq=a->freq+b->freq+c->freq;
v.push_back(T);
sort(v.begin(),v.end(),compare);
}
}

string a;
void print_codes(BTPTR T)
{
    if(T!=NULL)
    {
        if(T->lc==NULL&&T->mc==NULL&&T->rc==NULL)
        {   cout<<T->data<<" ";
            cout<<a<<endl;
            a=a.substr(0,a.length()-1);
        }
        else
        {   if(T->lc!=NULL)
            {a=a+"0";print_codes(T->lc);}
            if(T->mc!=NULL)
            {a=a+"1";print_codes(T->mc);}
            if(T->rc!=NULL)
            {a=a+"2";print_codes(T->rc);}
        }
    }
}

int main()
{int n;
    cout<<"Enter the number of characters:";
    cin>>n;
    BTPTR temp;
    for(int i=0;i<n;i++)
    {temp=new bnode;
    cin>>temp->data>>temp->freq;
    temp->lc=NULL;
    temp->mc=NULL;
    temp->rc=NULL;
    v.push_back(temp);
    }
    create_huffman();
    print_codes(v[0]);

}

