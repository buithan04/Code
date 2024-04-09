#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node* next;
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
        L.Head = p;
    }
}
void inputList (List &L , int n)
{
    int x;
    for (int i = 0; i < n ; i++)
    {
        cin>>x;
        AddNodeTail(L,x);
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
    if (L.Head != NULL)
    {
        Node * p = L.Head;
        L.Head = p->next;
        p->next = NULL;
        if (L.Head == NULL) L.Tail = NULL;
        delete p;
    }
}
void RemoveTail (List &L , int &dem)
{
    Node* k = NULL;
    Node* p = L.Head;
    for (int i = 1; i < dem ; i++)
    {
        k = p;
        p = p->next;
    }
    if (k == NULL) RemoveHead(L);
    else
    {
        k->next = NULL;
        L.Tail = k;
        delete p;
    }
    dem--;
}
void AddMidle (List &L , int c , int x)
{
    Node* new_ele = GetNode (x);
    Node* p = L.Head;
    while (p!=NULL)
    {
        if (p->info == c)
        {
            new_ele->next = p->next;
            p->next= new_ele;
            if (new_ele->next == NULL) L.Tail = new_ele;
            break;
        }
        p = p->next;
    }
    if (p == NULL) AddNodeHead (L,x);
}
void RemoveMiddle (List &L , int x)
{
    Node * p = L.Head;
    Node * k = NULL;
    while (p != NULL)
    {
        if (p->info == x)
        {
            break;
        }
        k = p;
        p = p->next;
    }
    if (p)
    {
        if (k == NULL) RemoveHead(L);
        else
        {
            k->next = p->next;
            p->next = NULL;
            if (k->next == NULL) L.Tail = k;
            delete p;
        }
    }
}
void RemoveMiddleX (List &L , int x)
{
    Node * p = L.Head;
    Node * k = NULL;
    while (p != NULL)
    {
        if (p->info == x)
        {
            break;
        }
        k = p;
        p = p->next;
    }
    if (p)
    {
        if (k == NULL) RemoveHead(L);
        else
        {
            k->next = p->next;
            p->next = NULL;
            if (k->next == NULL) L.Tail = k;
            delete p;
        }
        RemoveMiddleX (L,x);
    }
}
int main()
{
    List L;
    Init (L);
    int a,b;
    while (1)
    {
        cin>>a;
        if (a == 6) break;
        else if (a == 0)
        {
            cin>>b;
            AddNodeHead (L,b);
        }
        else if (a == 1)
        {
            cin>>b;
            AddNodeTail (L,b);
        }
        else if (a == 2)
        {
            int c;
            cin>>c>>b;
            AddMidle (L,c,b);
        }
        else if (a == 3)
        {
            cin>>b;
            RemoveMiddle (L,b);
        }
        else if (a == 4)
        {
            cin>>b;
            RemoveMiddleX (L,b);
        }
        else if (a == 5) RemoveHead(L);
    }
    outputList(L);
}
