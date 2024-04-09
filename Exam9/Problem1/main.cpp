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
Node * Search (Tree T, int x)
{

    if (T == NULL) return T;
    else
    {
        if (T->info == x) return T;
        else if (x < T->info) return Search (T->left,x);
        else return Search (T->right,x);
    }
}
int maxValue (Tree T)
{
    if (T->right == NULL) return T->info;
    else return maxValue(T->right);
}
int minValue (Tree T)
{
    if (T->left == NULL) return T->info;
    else return minValue(T->left);
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T); cout<<endl;


    int x; cout<<"\nEnter the element you want to find: ";cin>>x;
    Node *p=Search(T,x);
    if (p) cout<< "Found";
    else cout<<"Not found";
    cout<<"\nMinimum value in BTS is "<<minValue(T);
    cout<<"\nMinimax value in BTS is "<<maxValue(T);


	return 0;
}
