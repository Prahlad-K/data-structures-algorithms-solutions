#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

const int n=26;

struct trnode{
	int tag;
	union un{
		char* str;
		trnode* child[n+1];
	}u;
};
trnode* getnode(int tag)
{	trnode* newnode= new trnode;
	newnode->tag=tag;
	if(tag)
	for(int i=0;i<n+1;i++)
	newnode->u.child[i]=NULL;
	else
	newnode->u.str=new char;
	return newnode;
}
void print(trnode*& root)
{	if(!root)
	return;
	int i;
	cout<<"(";
	if(root->tag)
	for(i=0;i<n+1;i++)
	{	if(root->u.child[i])
		if(i==26)
		cout<<"NULL:";
		else
		cout<<char(i+97)<<" ";
		print(root->u.child[i]);
	}
	else
	cout<<" "<<root->u.str<<" ";
	cout<<")";
}
void insert(trnode* root,char* ch)
{	trnode* t=root;
	int i;
	for(i=0;i<strlen(ch);i++)
	{	int index=ch[i]-'a';
		if(!t->u.child[index])
		{	t->u.child[index]=getnode(0);
			strcpy(t->u.child[index]->u.str,ch);
			break;
		}
		else
		{	trnode* temp=t->u.child[index];
			if(temp->tag==0)
			{	trnode* a=getnode(1);
				if(i==strlen(ch)-1)
				{	a->u.child[ temp->u.str[i+1]-'a' ]=temp;
					a->u.child[n]=getnode(0);
					strcpy(a->u.child[n]->u.str,ch);
					t->u.child[index]=a;
				}	
				else
				{	if(i+1>=strlen(temp->u.str))
				  	a->u.child[n]=temp;
				  	else
					a->u.child[ temp->u.str[i+1]-'a' ]=temp;
					t->u.child[index]=a;
				}	
			}
			t=t->u.child[index];
		}
	}
}
int cnt(trnode* t,int& a)
{	int c=0,i;
	for(i=0;i<n+1;i++)
	if(t->u.child[i])
	c++,a=i;
	return c;
}
void del(trnode* root,char* ch)
{	trnode* t=root;
	trnode* b;	
	int i,j;
	stack<trnode*> s;
	for(i=0;i<strlen(ch);i++)
	{	int index=ch[i]-'a';
		s.push(t);
		if(!t->u.child[index])
		{	 cout<<"not found";
			 return;
		}
		else
		{	if(t->u.child[index]->tag==0 || (t->u.child[index]->u.child[n]!=NULL && i==strlen(ch)-1))
			{	if(t->u.child[index]->u.child[n]!=NULL && i==strlen(ch)-1)
				{	s.push(t->u.child[index]);
					t=t->u.child[index];
					index=n;		
				}
				t->u.child[index]=NULL;	
				while(s.size()!=1)
				{	trnode* temp=s.top();
					s.pop();
					int ind=-1, c;
					c=cnt(temp,ind);
					if(c==0)
					{	t=NULL;
						return;	
					}
					if(c==1)
					{	char* tem=new char;
						strcpy(tem,temp->u.child[ind]->u.str);
						temp->u.child[ind]=NULL;
						temp->tag=0;
						temp->u.str=new char;
						strcpy(temp->u.str,tem);			
					}	
					if(c>1)
					{	return;
					}	
				}
				return;
			}
			else
			t=t->u.child[index];	
		}
	}
}
void search(trnode* root,char* ch)
{	trnode* t=root;
	int i;
	for(i=0;i<strlen(ch);i++)
	{	int index=ch[i]-'a';
		if(t->tag==0)
		{	if(!strcmp(t->u.str,ch))
			cout<<"found: "<<t->u.str<<endl;
			return;
		}
		if(!t->u.child[index])
		{	cout<<"not found";
			return;
		}
		if(t->u.child[index]->tag==0 || (t->u.child[index]->u.child[n]!=NULL && i==strlen(ch)-1))
		{	if(t->u.child[index]->u.child[n]!=NULL && i==strlen(ch)-1)
			{	cout<<"Found: "<<t->u.child[index]->u.child[n]->u.str<<endl;
				return;
			}
			if(!strcmp(t->u.child[index]->u.str,ch))
			cout<<"found: "<<t->u.child[index]->u.str<<endl;
			else
			cout<<"not found";
			return;
		}
		t=t->u.child[index];
	}
}
int main()
{	trnode* root=getnode(1);
	cout<<"Number:";
	int num,i;
	cin>>num;
	char* ch[num];
	for(i=0;i<num;i++)
	{	ch[i]=new char;
		cin>>ch[i];
	}
	for(i=0;i<num;i++)
	insert(root,ch[i]);
	print(root);
	char* c=new char;
	cout<<"\nDeletion\n";
	cin>>c;
	del(root,c);
	print(root);
	cout<<"\nsearch:";
	c=new char;
	cin>>c;
	search(root,c);
	return 0;
}
