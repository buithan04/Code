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
    if (q->right == NULL)
    {
        p->info = q->info;
        p = q;
        q = q->left;
    }
    else
    {
        TimNodeTheMang (q->right,p);
    }
}
Node * Search (Tree T, int x)
{
    if (T == NULL) return T;
    else
    {
        if (T->info == x) return T;
        if (T->info < x) return Search (T->right,x);
        if (T->info > x) return Search (T->left,x);
    }
}
void deleteNode (Tree &T , int x)
{
    Node * z = Search(T,x);
    if (z != NULL)
    {
        if (T == NULL) return;
        if (x < T->info) deleteNode(T->left,x);
        else if (x > T->info) deleteNode(T->right,x);
        else
        {
            char k;
            cout<<"\nDo you want to delete "<<x<< "?(y/n):";
            cin>>k;
            if (k == 'y' || k == 'Y')
            {
                Node * p = T;
            if (T->left == NULL) T = T->right;
            else if (T->right == NULL) T = T->left;
            else TimNodeTheMang (T->left,p);
            }
        }
    }
    else  cout<<"Not found";

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

