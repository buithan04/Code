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
    p->next = p->prev = NULL;
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
void RemoveHead (List &L)
{
    Node* p = L.Head;
    if (p != NULL)
    {
        L.Head = p->next;
        L.Head->prev = NULL;
        p->next = NULL;
        delete p;
        if (L.Head == NULL) L.Tail = L.Head;
    }
}
void RemoveTail (List &L )
{
    Node* p = L.Tail;
    if (p != NULL)
    {
        p->prev->next = NULL;
        L.Tail = p->prev;
        p->prev = NULL;
        delete p;
        if (L.Tail == NULL) L.Head = L.Tail;
    }
}

void RemoveMiddle (List &L , int x)
{
    Node * p = L.Head;
    while (p != NULL)
    {
        if (p->info == x)
        {
            if (p == L.Head) RemoveHead(L);
            else if (p == L.Tail) RemoveTail(L);
            else
            {
                p->next->prev = p->prev;
                p->prev->next = p->next;
                p->next = p->prev = NULL;
                delete p;
            }
            break;
        }
        p = p->next;
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
        RemoveMiddle (L,x);
        AddNodeHead (L,x);
        m--;
    }
    outputList(L);
}
