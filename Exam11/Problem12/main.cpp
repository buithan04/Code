
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
Node * NodeFather (Node * p , Tree T)
{
    if (T->left == p || T->right == p) return T;
    else
    {
        if (T->info < p->info) return NodeFather (p,T->right);
        else if (T->info > p->info) return NodeFather (p,T->left);
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
int Second (Tree T )
{
    Node * p ;
    Node * q ;
    p = T;
    while (p->right != NULL) p = p->right;
    if (p->left != NULL)
    {
        q = p->left;
        while (q->right != NULL) q = q->right;
        return q->info;
    }
    else  q = NodeFather (p,T);
    return q->info;

}
void secondLargest (Tree T)
{
    if (T != NULL)
    {
        if (T->left != NULL || T->right != NULL)
        {
            cout<<"\n2nd largest value is "<<Second(T);
        }
    }
}
int main()
{
	Tree T = NULL;
	inputTree(T);
    secondLargest(T);
	return 0;
}


