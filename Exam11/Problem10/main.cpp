#include <iostream>

using namespace std;
struct Node
{
    int info;
    Node * left;
    Node * right;
};
typedef Node * Tree;
Node * getNode (int x)
{
    Node * p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}
void Insert (Tree &T , int x)
{
    if (T != NULL)
    {
        if (T->info > x) Insert(T->left,x);
        else if (T->info < x) Insert (T->right,x);
    }
    else
    {
        T = getNode(x);
    }
}
void inputTree (Tree &T)
{
    int n; cin>>n;
    int x;
    for (int i = 0 ; i < n ; i++)
    {
        cin>>x;
        Insert (T,x);
    }
}
void LNR (Tree T)
{
    if (T != NULL)
    {
        LNR (T->left);
        cout<<T->info<<" ";
        LNR (T->right);
    }
}
bool isFullBinaryTree (Tree T)
{
    if (T != NULL)
    {
        if ((T->left != NULL && T->right == NULL) || (T->left == NULL && T->right != NULL)) return false;
        return isFullBinaryTree (T->left) && isFullBinaryTree (T->right);
    }
    return true;
}
int MaxdepthOfTree (Tree T)
{
    if (T == NULL) return -1;
    if (T->left == NULL && T->right == NULL) return 0;
    return max (MaxdepthOfTree (T->left),MaxdepthOfTree (T->right)) + 1;
}
int MindepthOfTree (Tree T)
{
    if (T == NULL) return -1;
    if (T->left == NULL && T->right == NULL) return 0;
    return min (MindepthOfTree (T->left),MindepthOfTree (T->right)) + 1;
}
bool isCompleteBinaryTree (Tree T)
{
    return isFullBinaryTree(T) && (MaxdepthOfTree(T) == MindepthOfTree (T));
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	int i=isCompleteBinaryTree (T);
	if(i==0) cout<<"\nThe tree is not a Complete Binary Tree";
    else cout<<"\nThe tree is a Complete Binary Tree";
	return 0;
}
