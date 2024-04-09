#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;
struct Node
{
    int info;
    Node * next;
};
struct List
{
    Node * head;
    Node * tail;
};
Node * GetNode (int x)
{
    Node * p = new Node;
    p->info = x;
    p->next =  NULL;
    return p;
}
void Init (List &L)
{
    L.head = L.tail = NULL;
}
void AddNodeHead (List &L, int x)
{
    Node * new_ele = GetNode (x);
    if (L.head == NULL)
    {
        L.head = L.tail = new_ele;
    }
    else
    {
        new_ele->next= L.head;
        L.head = new_ele;
    }
}
void AddNodeTail (List &L, int x)
{
    Node * new_ele = GetNode (x);
    if (L.head == NULL)
    {
        L.head = L.tail = new_ele;
    }
    else
    {
        L.tail->next = new_ele;
        L.tail = new_ele;
    }
}
void MoveK (List &L, int k)
{
    Node * p = L.head;
    Node * q = L.tail;
    while (p != q && k > 0)
    {
        k--;
        L.head = L.head->next;
        p->next = NULL;
        L.tail->next = p;
        L.tail = p;
        p = L.head;
    }

}
void inputList (List L)
{
    Node * p = L.head;
    while (p != NULL)
    {
        cout<<p->info<<" ";
        p = p->next;
    }
    cout<<endl;
}
void AddAfter (List &L , int b,int c)
{
    Node * p = L.head;
    while (p != NULL)
    {
        if (p->info == b) break;
        p = p->next;
    }
    if (p == NULL) AddNodeHead (L,c);
    else
    {
        if (p == L.tail) AddNodeTail (L,c);
        else
        {
            Node * q = GetNode (c);
            q->next = p->next;
            p->next = q;
        }
    }
}
int main()
{
    List L;
    Init(L);
    int a,b,c;
    while (1)
    {
        cin>>a;
        if (a == 4) break;
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
        else if (a == 3)
        {
            cin>>b;
            MoveK (L,b);
        }
        else if (a == 2)
        {
            cin>>b>>c;
            AddAfter (L,b,c);
        }
    }
    inputList (L);
    return 0;
}
