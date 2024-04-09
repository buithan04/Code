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
int depthOfTree (Tree T)
{
    if (T == NULL) return -1;
    if (T->left == NULL && T->right == NULL) return 0;
    return max (depthOfTree (T->left),depthOfTree (T->right)) + 1;
}
int isAVL (Tree T)
{
    if (T == NULL) return 1;
    if (isAVL(T->left) == 0) return 0;
    if (isAVL(T->right) == 0) return 0;
    int A = max (depthOfTree (T->left),depthOfTree (T->right));
    int B = min (depthOfTree (T->left),depthOfTree (T->right));
    if (A - B > 1) return 0;
    else return 1;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<isAVL(T);
	return 0;
}
