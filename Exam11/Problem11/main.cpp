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
int nodesWithLevel(Tree T, int k, int c);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    int k; cout<<"\nEnter k: "; cin >>k;
    cout<<nodesWithLevel(T,k,0); //neu tham so thu 3 khong can dung thi trong ham khong can xu ly

    return 0;
}
Node * NodeFather (Node * p , Tree T)
{
    if (T->pLeft == p || T->pRight == p) return T;
    else
    {
        if (T->info < p->info) return NodeFather (p,T->pRight);
        else if (T->info > p->info) return NodeFather (p,T->pLeft);
    }
}
int TinhMuc (Node * p, Tree T)
{
    if (p == T) return 0;
    else
    {
        return 1 + TinhMuc(NodeFather(p,T),T);
    }
}
void Output (Tree T , int k , int &c , Node * p)
{
    if (T != NULL)
    {
        Output(T->pRight,k,c,p);
        if (TinhMuc(T,p) == k)
        {
            c++;
            cout<<T->info<<" ";
        }
        Output(T->pLeft,k,c,p);
    }
}
int nodesWithLevel(Tree T, int k, int c)
{
    cout<<"List of nodes with level "<<k<<" (R->L): ";
    Output (T,k,c,T);
    cout<<endl;
    cout<<"\nNumber of nodes with level "<<k<<": ";
    return c;

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
