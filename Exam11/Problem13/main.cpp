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
void Search (Tree T, int x , int &k , int &Min)
{
    if (T != NULL)
    {
        if (T->info <= x && Min > (x - T->info))
        {
            Min = x - T->info;
            k = T->info;
        }
        Search(T->left,x,k,Min);
        Search(T->right,x,k,Min);
    }
}
int main()
{
    Tree T = NULL;
    inputTree(T);
    int x; cin>>x;
    int Min = 201;
    int k = 1000;
    Search(T,x,k,Min);
    if (k != 1000) cout<<k;
    else cout<<201;
    return 0;
}
