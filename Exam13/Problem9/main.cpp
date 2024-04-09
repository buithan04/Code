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
void Search (Tree T , int x)
{
    Node *  p = T;
    while (p != NULL)
    {
        if (p->info == x)
        {
            cout<<1<<endl;
            return;
        }
        else if (p->info < x) p = p->right;
        else p = p->left;
    }
    cout<<0<<endl;
}


int main()
{
    Tree T;
    T = NULL;
    int choice;
    int x;
    while (1)
    {
        cin>>choice;
        if (choice == 1)
        {
            cin>>x;
            Insert (T,x);
        }
        else if (choice == 2)
        {
            cin>>x;
            Search(T,x);
        }
        else if (choice == 0) break;
    }
    return 0;
}
