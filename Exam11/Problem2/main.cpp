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
Node * rotateRight (Tree &T)
{
    Node * p = T;
    if (T == NULL) cout<< "\nKhong the xoay vi cay rong";
    else if (T->left == NULL) cout<< "\nKhong the xoay phai vi khong co nut con ben trai";
    else
    {
        p = p->left;
        T->left = p->right;
        p->right = T;
    }
    return p;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
	T=rotateRight(T);
	cout<<"\nUpdated Tree: \n";
	cout<<"NLR: "; NLR(T);
	return 0;
}
