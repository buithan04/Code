#include <iostream>

using namespace std;
struct Node
{
    int info;
    Node * left;
    Node * right;
};
Node * GetNode (int x)
{
    Node * p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}
typedef Node * Tree;
void Insert (Tree &T , int x)
{
    if (T != NULL)
    {
        if (x < T->info) Insert (T->left,x);
        else if (x > T->info) Insert (T->right,x);
    }
    else
    {
        T = GetNode (x);
    }
}
void LNR (Tree T)
{
    if (T!= NULL)
    {
        LNR (T->left);
        cout<<T->info<<" ";
        LNR(T->right);
    }
}

void inputTree (Tree &T)
{
    int n;cin>>n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        Insert(T,x);
    }
}
void DeleteNode (Tree &T)
{
    if (T != NULL)
    {
        if (T->left == NULL && T->right == NULL)
        {
            delete T;
            T = NULL;
            return ;
        }
        else
        {
            DeleteNode(T->left);
            DeleteNode(T->right);
        }
    }
}
Node * removeLeafs (Tree &T)
{
    if (T != NULL)
    {
        if (T->left == NULL && T->right == NULL)
        {
            delete T;
            T = NULL;
            return T;
        }
        else
        {
            DeleteNode(T);
            return T;
        }
    }
    else return T;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	T = removeLeafs(T);
	cout<<"\nUpdated Tree: \n";
	cout<<"LNR: "; LNR(T);
	return 0;
}
