#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

const int n=26;

struct trnode{
	int tag;
	trnode* child[n];
	char* ch;
};

trnode* getnode()
{	trnode* newnode= new trnode;
	newnode->tag=0;
	newnode->ch=new char;
	for(int i=0;i<n;i++)
	newnode->child[i]=NULL;
	return newnode;
}

void insert(trnode* root, char* ch)
{	trnode* t=root;
	int i,j,k=0;
	while(k<strlen(ch))
	{	int index=ch[k]-'a';
		if(!t->child[index])
		{	t->child[index]=getnode();
			for(j=k;j<strlen(ch);j++)
			t->child[index]->ch[j-k]=ch[j];
			t->child[index]->ch[j-k]='\0';
			t->child[index]->tag=1;
			return;
		}
		else
		{	for(i=k;i<k+strlen(ch);i++)
			{	if(ch[i]==t->child[index]->ch[i-k])
				continue;
				break;
			}
			if(i-k!=strlen(t->child[index]->ch))
			{	//splitting original
				int a=t->child[index]->ch[i]-'a';	
				t->child[index]->child[a]=getnode();
				//new one
				for(j=i;j<strlen(t->child[index]->ch);j++)
				t->child[index]->child[a]->ch[j-i]=t->child[index]->ch[j];
				t->child[index]->child[a]->ch[j-i]='\0';
				t->child[index]->child[a]->tag=1;
				//original one
				t->child[index]->ch[i]='\0';
				t->child[index]->tag=0;
				
				//added one
				t->child[index]->child[ch[i]-'a']=getnode();
				for(j=i;j<strlen(ch);j++)
				t->child[index]->child[ch[i]-'a']->ch[j-i]=ch[j];
				t->child[index]->child[ch[i]-'a']->ch[j-i]='\0';
				t->child[index]->child[ch[i]-'a']->tag=1;
				return;	
			}
			else
			{	t=t->child[index];
				k=i;
			}
		}
	}
}
void del(trnode* root,char* ch)
{	trnode* t=root;
	stack<trnode*> s;
	int i=0;
	while(i<strlen(ch))
	{	s.push(t);
		int index=ch[i]-'a';
		if(!t->child[index])
		{	cout<<"not found\n";
			return;	
		}
		int j;
		for(j=0;j<strlen(t->child[index]->ch);j++)
		{	if(ch[i+j]==t->child[index]->ch[j])
			continue;
			else
			{	cout<<"not found\n";
				return;
			}
	    }
		if(i+j==strlen(ch))
		{	t->child[index]->tag=0;
			int cnt=0,ind,k;
			for(k=0;k<n;k++)
			if(t->child[index]->child[k])
			cnt++,ind=k;
			if(cnt==0)
			t->child[index]=NULL;
			if(cnt==1)
			{	strcat(t->child[index]->ch,t->child[index]->child[ind]->ch);
				t->child[index]->tag=1;
				t=t->child[index];
				for(k=0;k<n;k++)
				if(t->child[ind]->child[k])
				t->child[k]=t->child[ind]->child[k];
				t->child[ind]=NULL;
				return;
			}
			return;
		}
		else	
		{	i=i+j;
			t=t->child[index];
		}
	}
}
int search(trnode* root,char* ch)
{	int i=0,j;
	while(i<strlen(ch))
	{	int index=ch[i]-'a';
		if(!root->child[index])
		return 0;
		else
		{	for(j=0;j<strlen(root->child[index]->ch);j++)
			{	if(ch[i+j]==root->child[index]->ch[j])
				continue;
				else
				return 0;
		    }
			if(j==strlen(root->child[index]->ch) && root->tag)
			return 1;	
			i=i+j;
			root=root->child[index];	
		}
	}
	return 1;
}
void print(trnode* t)
{	int i;
	if(!t)
	return;
	cout<<"( ";
	for(i=0;i<n;i++)
	{	if(t->child[i])
		{	cout<<t->child[i]->ch<<": "<<t->child[i]->tag;
			print(t->child[i]);
		}
	}
	cout<<") ";	
}

int main()
{	cout<<"Number:";
	int num,i;
	cin>>num;
	char* ch[num];
	for(i=0;i<num;i++)
	{	ch[i]=new char;
		cin>>ch[i];
	}
	trnode* root=getnode();
	
	for(i=0;i<num;i++)
	{	insert(root,ch[i]);
	}
	print(root);
	int flag=1;
	while(flag)
	{	char* c=new char;
		cin>>c;
		del(root,c);
		print(root);
		cin>>flag;
	}
	return 0;
}
