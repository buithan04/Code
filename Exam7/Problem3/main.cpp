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
    Node * p = L.Head;
    L.Head = p->next;
    p->next = NULL;
    if (L.Head == NULL) L.Tail = NULL;
    delete p;
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
int main()
{
    List L;
    Init (L);
    int dem = 0;
    int n ; cin>>n;
    char x,y;
    int z;
    for (int i = 0 ; i < n ; i++)
    {
        cin>>x;
        cin>>y;
        if (x == '-')
        {
            cin>>z;
            if (dem)
            {
                if (y == 'H')
                {
                    dem--;
                    RemoveHead (L);
                }
                if (y == 'T')
                {
                    RemoveTail(L,dem);
                }
            }


        }
        if (x == '+')
        {
            cin>>z;
            dem++;
            if (y == 'H') AddNodeHead (L,z);
            if (y == 'T') AddNodeTail (L,z);
        }
    }
    outputList(L);
}
