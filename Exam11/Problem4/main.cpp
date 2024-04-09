#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node* Tree;

Node *getNode(int x);
void insertNode(Tree & T, int x);
void inputTree(Tree &T);
void NLR(Tree T);
bool isSquare (int n);
void SearchStandFor(Node* &p, Node* &q); //Chon node phai nhat tren nhanh con ben trai
void deleteSquareNumbers(Tree &T);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    cout<<"\nDelete all square numbers:";
    deleteSquareNumbers(T);
    cout<<"\nNLR: "; NLR(T);
    return 0;
}

Node * getNode (int x)
{
    Node * p = new Node;
    p->info = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void insertNode (Tree &T , int x)
{
    if (T != NULL)
    {
        if (x < T->info) insertNode (T->pLeft,x);
        else if (x > T->info) insertNode (T->pRight,x);
    }
    else
    {
        T = getNode (x);
    }
}
void NLR (Tree T)
{
    if (T!= NULL)
    {
        cout<<T->info<<" ";
        NLR (T->pLeft);
        NLR(T->pRight);
    }
}

void inputTree (Tree &T)
{
    int n;cin>>n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        insertNode(T,x);
    }
}
bool isSquare (int n)
{
    int i = 0;
    while( i*i <= n)
    {
        if (i*i == n) return true;
        ++i;
    }
    return false;
}
void SearchStandFor(Node* &p, Node* &q)
{
    if (p->pRight == NULL)
    {
        q->info = p->info;
        q = p;
        p = p->pLeft;
        delete q;
    }
    else
    {
        SearchStandFor (p->pRight,q);
    }
}
void deleteSquareNumbers(Tree &T)
{
    if (T == NULL) return;
    if (isSquare(T->info))
    {
        Node * p = T;
        if (T->pLeft == NULL) T = T->pRight;
        else if (T->pRight == NULL) T = T->pLeft;
        else SearchStandFor (T->pLeft,p);
        deleteSquareNumbers(T);
    }
    else
    {
        deleteSquareNumbers(T->pLeft);
        deleteSquareNumbers(T->pRight);
    }
}
