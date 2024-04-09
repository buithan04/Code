#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node* next;
    Node* prev;
};
struct List
{
    Node * Head;
    Node * Tail;
};
Node* GetNode (int x)
{
    Node * p = new Node;
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
void AddNodeTail (List &L , int x)
{
    Node * p = GetNode(x);
    if (L.Head == NULL && L.Tail == NULL)
    {
        L.Head = L.Tail = p;
    }
    else
    {
        L.Tail->next = p;
        p->prev = L.Tail;
        L.Tail = p;
    }
}
void AddNodeHead (List &L , int x)
{
    Node * p = GetNode(x);
    if (L.Head == NULL && L.Tail == NULL)
    {
        L.Head = L.Tail = p;
    }
    else
    {
        p->next = L.Head;
        L.Head->prev = p;
        L.Head = p;
    }
}
void inputList (List &L , int n)
{
    for (int i = 1; i <= n ; i++)
    {
        AddNodeTail(L,i);
    }
}
void outputList (List L)
{
    Node * p = L.Head;
    if (!p) cout<<"List is empty";
    while (p!= NULL)
    {
        cout<<p->info<<" ";
        p = p->next;
    }
}
void Init (List & L)
{
    L.Head = L.Tail = NULL;
}
Node * Search (List L, int x)
{
    Node * p = L.Head;
    while (p != NULL)
    {
        if (p->info == x) return p;
        p = p->next;
    }
    return p;
}
void MoveX (List &L, int x)
{
    Node * p = Search (L,x);
    if (p == L.Head) return;
    else if (p == L.Tail)
    {
        L.Tail = p->prev;
        L.Tail->next = NULL;
        p->prev = NULL;
        p->next = L.Head;
        L.Head->prev = p;
        L.Head = p;
    }
    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->prev = NULL;
        p->next = L.Head;
        L.Head->prev = p;
        L.Head = p;
    }
}
int main()
{
    List L;
    Init (L);
    int n,m;
    cin>>n>>m;
    inputList (L,n);
    int x;
    while (m > 0)
    {
        cin>>x;
        MoveX (L,x);
        m--;
        cout<<L.Tail->info<<" ";
    }
}
