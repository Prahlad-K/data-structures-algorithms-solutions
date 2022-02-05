#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct btnode {
	int data;
	btnode *lchild, *rchild;
} *btptr;


void tour(queue<btptr> &q)
{
	if(q.size() < 2)
		return;

	btptr t = new btnode;
	btptr t1 = q.front();
	q.pop();
	btptr t2 = q.front();
	q.pop();

	t->lchild = t1;
	t->rchild = t2;
	t->data = max(t1->data, t2->data);
	q.push(t);

	tour(q);
}

int main()
{
	int n;
	cout<<"\nEnter size: ";
	cin>>n;

	int a[n],result[n];

	cout<<"\nEnter "<<n<<" numbers: ";
	for(int i=0;i<n;i++)
		cin>>a[i];

	for(int i=0;i<n;i++)
	{
		queue <btptr> q;

		for(int j=0;j<n;j++)
        {int t=a[j];
			if(a[j] != -1)
			{
				btptr temp = new btnode;
				temp->data = a[j];
				q.push(temp);
			}
		}

		tour(q);
        result[n-i-1]=q.front()->data;

		for(int k=0;k<n;k++)
        {if(a[k]==q.front()->data)
        a[k]=-1;
        }
	}

	cout<<"\nSorted list is: ";
	for(int i=0;i<n;i++)
		cout<<result[i]<<" ";
	cout<<endl;

	return 0;
}
