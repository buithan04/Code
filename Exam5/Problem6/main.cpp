#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node* next;
};
struct LIST
{
    Node* Head ;
    Node* Tail ;
};

Node* GetNode (int x)
{
    Node* p = new Node ;
    if (p != NULL)
    {
        p->info = x;
        p->next = NULL;
    }
    return p;
}
void AddHead (LIST &L , int x)
{
    Node* new_ele = GetNode (x);
    if (L.Head==NULL )
    {
        L.Head = L.Tail = new_ele;
    }
    else
    {
        new_ele->next = L.Head;
        L.Head = new_ele;
    }
}
void AddTail (LIST &L , int x)
{
    Node* new_ele = GetNode (x);
    if ( L.Tail== NULL)
    {
        L.Head=L.Tail=new_ele;
    }
    else
    {
        L.Tail->next = new_ele;
        L.Tail = new_ele;
    }
}
Node* vitri (LIST L, int k)
{
    Node* p = L.Head;
    while (p != NULL)
    {
        if (p->info == k) return p;
        p = p->next;
    }
    return p;
}
void AddAfter (LIST &L , int x , int k)
{
    Node* new_ele = GetNode (x);
    if ( L.Head == NULL)
    {
        L.Head=L.Tail=new_ele;
    }
    else
    {
        Node* p = vitri (L,k);
        if (p != NULL)
        {
            if (L.Tail == p)
            {
                L.Tail = new_ele;
            }
            new_ele->next = p->next;
            p->next = new_ele;
        }
        else AddHead (L,x);
    }
}

void RemoveNode (LIST &L )
{
    if (L.Head != NULL)
    {
        Node * p = L.Head;
        L.Head = L.Head->next;
        p->next = NULL;
        delete p;
        if (L.Head == NULL) L.Tail = NULL;
    }
}
void RemoveNode1 (LIST &L,int a)
{
    Node * p = L.Head;
    Node *k = NULL;
    while (p != NULL)
    {
        if (p->info == a) break;
        k = p;
        p = p->next;
    }
    if (p!=NULL)
    {
    if (k==NULL) RemoveNode (L);
    else
    {
        k->next = p->next;
        p->next = NULL;
        if (p==L.Tail) L.Tail = k;
        delete p;
    }
    }
}
void InDS (LIST L)
{
    Node* p = L.Head;
    if (p==NULL) cout<<"blank";
    while (p != NULL)
    {
        cout<<p->info<<" ";
        p = p->next;
    }
}
void Init (LIST &L)
{
    L.Head = L.Tail = NULL;
}
int main()
{

    int a,b,c;
    LIST L;
    Init (L);
    while (1)
    {
        cin>>a;
        if (a==6) break;
        else if (a==0)
        {
            cin>>b;
            AddHead (L,b);
        }
        else if (a==1)
        {
            cin>>b;
            AddTail (L,b);
        }
        else if (a==2)
        {
            cin>>c>>b;
            AddAfter (L,b,c);
        }
        else if (a==3)
        {
            cin>>a;
            RemoveNode1 (L,a);
        }
        else if (a==5)
        {
            RemoveNode (L);
        }
    }
    InDS (L);
    return 0;
}
