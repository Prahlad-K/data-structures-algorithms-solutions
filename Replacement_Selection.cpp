#include <iostream>
#include <queue>
using namespace std;

typedef struct snode
{
    int data;
    bool star=false;
   struct snode *lchild;
   struct snode *rchild;
 }*SPTR;
 queue <SPTR> q;
 int n;

 bool allstar()
 {
     if(q.front()->star==true)
        return true;
     else
        return false;
 }
 int A[100];
int minarray[100];
int index=1;

 void make_tree(SPTR m)
 {
     int j=1;
      while(j<=4)
      {
          SPTR S=new snode;
          S->data=A[j];
          for(int i=1;i<index;i++)
          {if(A[j]==minarray[i])
          S->star=true;
          }
          S->lchild=NULL;
          S->rchild=NULL;
          q.push(S);
          j++;
      }

     while(q.size()!=1)
      {
          SPTR A,B,res;
          A=q.front();q.pop();
          B=q.front();q.pop();
          res=new snode;
          if(!A->star&&!B->star)
          res->data=min(A->data,B->data);
          else if(A->star&&!B->star)
            res->data=B->data;
          else if(B->star&&!A->star)
            res->data=A->data;
          else
            res->star=true;
        q.push(res);
      }
      m=q.front();q.pop();
      cout<<m->data<<" ";
      minarray[index++]=m->data;
      if(m->star!=true)
      make_tree(m);
    }

 int main()
 {

     cout<<"Enter the number of elements:";
     cin>>n;
     for(int i=1;i<=n;i++)
        cin>>A[i];

      SPTR m=new snode;
      m->data=0;
     make_tree(m);
 }
