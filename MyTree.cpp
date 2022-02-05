#include <iostream>
using namespace std;

typedef struct bnode
{
  int n;
  bnode* l;
  bnode* r;
}*BTPTR;

BTPTR root = NULL; int flag = 0;
void create(BTPTR &T, int num)
{
    if(T==NULL)
    {
        BTPTR N = new bnode;
        N->l = NULL;
        N->r = NULL;
        N->n = num;

        T=N;

        if(flag++==0)
        root = T;
    }
    else{
    if(num>=T->n)
        create(T->r, num);
    else
        create(T->l, num);}

}

void inorder(BTPTR &T)
{
    if(T!=NULL)
    {
        inorder(T->l);
        cout<<T->n<<" ";
        inorder(T->r);
    }

}


int main()
{
    int T, n;
    cin>>T;
    BTPTR node = NULL;
    while(T--)
    {
        cin>>n;
        create(node, n);
        node = root;
    }

    inorder(root);

}
