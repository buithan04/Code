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
void NLR (Tree T)
{
    if (T!= NULL)
    {
        cout<<T->info<<" ";
        NLR (T->left);
        NLR(T->right);
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

void TimNodeTheMang (Node * &q, Node * p)
{
    if (q->left == NULL)
    {
        p->info = q->info;
        p = q;
        q = q->right;
    }
    else
    {
        TimNodeTheMang (q->left,p);
    }
}
void deleteNode (Tree &T , int x)
{
    if (T == NULL) return;
    if (x < T->info) deleteNode(T->left,x);
    else if (x > T->info) deleteNode(T->right,x);
    else
    {
        Node * p = T;
        if (T->left == NULL) T = T->right;
        else if (T->right == NULL) T = T->left;
        else TimNodeTheMang (T->right,p);
    }
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
    int x; cout<<"\nEnter the element you want to delete: ";cin>>x;
    deleteNode(T,x);
    cout<<"\nNLR: "; NLR(T);

	return 0;
}
