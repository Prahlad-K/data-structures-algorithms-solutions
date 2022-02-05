//a 10 e 15 i 12 s 3 t 4 b 13 n 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct btnode {
	int weight;
	char data;
	btnode *lchild, *rchild;
} *btptr;


bool already(vector<char> &al, char ch)
{
	for(int i=0;i<al.size();i++)
		if(al[i] == ch)
			return true;

	return false;
}

void level_order(btptr& T)
{
	vector<char> al;
	btptr temp = new btnode;
	temp->data = '#';

	queue<btptr> q;
	q.push(T);
	q.push(temp);

	while(!q.empty())
	{
		btptr T1 = q.front();
		q.pop();

		if(T1->data == '#')
		{
			cout<<endl;
			if(!q.empty())
				q.push(temp);
		}
		else
		{
				cout<<T1->data<<" ";
			if(T1->lchild != NULL)
				q.push(T1->lchild);
			if(T1->rchild != NULL)
				q.push(T1->rchild);
        }
	}
}

bool compare(const btptr& a, const btptr& b)
{
    return (a->weight < b->weight);
}

void build_tree(vector<btptr> &v)
{
	if(v.size() == 1)
		return;

	sort(v.begin(), v.end(), compare);

	btptr t = new btnode;
	t->lchild = v[0];
	t->rchild = v[1];
	t->weight = v[0]->weight + v[1]->weight;
	t->data = '-';

	v.erase(v.begin());
	v.erase(v.begin());
	v.push_back(t);

	build_tree(v);
}

void search(string code, btptr t)
{
	static int i = -1;
	i++;

	if(i == code.size())
	{
		cout<<t->weight<<" "<<t->data<<endl;
		i = -1;
		return;
	}

	if(code[i] == 48)
		search(code, t->lchild);
	else if(code[i] == 49)
		search(code, t->rchild);
}
char a[100];
int ctr=0;int pos=0;
void printarray()
{
    for(int i=0;i<pos;i++)
        cout<<a[i];
    cout<<endl;
}
void print_code(btptr T)
{
    if(T==NULL)
        return;

    if(T->lchild==NULL&&T->rchild==NULL)
    {cout<<T->data<<" ";
    printarray();}

    else
    {if(T->lchild!=NULL)
        {a[pos++]='0';print_code(T->lchild);}
     if(T->rchild!=NULL)
        {a[pos++]='1';print_code(T->rchild);}
    }

}

int main()
{
	vector<btptr> v;
	int freq, n, ans;
	char ch;

	cout<<"\nEnter number of characters: ";
	cin>>n;

	cout<<"\nEnter "<<n<<" characters and their frequencies: ";
	for(int i = 0; i < n; i++)
	{
		btptr temp = new btnode;
		temp->lchild=NULL;
		temp->rchild=NULL;
		cin>>temp->data>>temp->weight;
		v.push_back(temp);
	}

	build_tree(v);

	cout<<"\nHuffman Code Tree: \n";
	level_order(v[0]);
	cout<<endl;

	cout<<"The data and code is:\n";
	print_code(v[0]);
	return 0;
}
