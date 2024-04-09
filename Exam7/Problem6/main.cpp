#include <iostream>

using namespace std;
struct node
{
    int info;
    node* next;
};
struct List
{
    node * pHead;
    node * pTail;
};
node* GetNode (int x)
{
    node * p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}
void AddNodeTail (List &L , int x)
{
    node * p = GetNode(x);
    if (L.pHead == NULL && L.pTail == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        L.pTail->next = p;
        L.pTail = p;
    }
}
void AddNodeHead (List &L , int x)
{
    node * p = GetNode(x);
    if (L.pHead == NULL && L.pTail == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        p->next = L.pHead;
        L.pHead = p;
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
    node * p = L.pHead;
    if (!p) cout<<"List is empty";
    while (p!= NULL)
    {
        cout<<p->info<<" ";
        p = p->next;
    }
}
void Init (List & L)
{
    L.pHead = L.pTail = NULL;
}
void RemoveHead (List &L)
{
    if (L.pHead != NULL)
    {
        node * p = L.pHead;
        L.pHead = p->next;
        p->next = NULL;
        if (L.pHead == NULL) L.pTail = NULL;
        delete p;
    }
}
void RemoveTail (List &L)
{
    node* k = NULL;
    node* p = L.pHead;
    while (p != NULL)
    {
        if (p->next == NULL)
        {
            break;
        }
        k = p;
        p = p->next;
    }
    if (k == NULL) RemoveHead(L);
    else
    {
        k->next = NULL;
        L.pTail = k;
        delete p;
    }
}
void AddMidle (List &L , int c , int x)
{
    node* new_ele = GetNode (x);
    node* p = L.pHead;
    while (p!=NULL)
    {
        if (p->info == c)
        {
            new_ele->next = p->next;
            p->next= new_ele;
            if (new_ele->next == NULL) L.pTail = new_ele;
            break;
        }
        p = p->next;
    }
    if (p == NULL) AddNodeHead (L,x);
}
void RemoveMiddle (List &L , int x)
{
    node * p = L.pHead;
    node * k = NULL;
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
            if (k->next == NULL) L.pTail = k;
            delete p;
        }
    }
}
void RemoveMiddleX (List &L , int x)
{
    node * p = L.pHead;
    node * k = NULL;
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
            if (k->next == NULL) L.pTail = k;
            delete p;
        }
        RemoveMiddleX (L,x);
    }
}
void SwapHead (List &L)
{
    node* k = NULL;
    node* p = L.pHead;
    while (p != NULL)
    {
        if (p->next == NULL)
        {
            break;
        }
        k = p;
        p = p->next;
    }
    int z = p->info;
    AddNodeHead (L,z);
    k->next = NULL;
    L.pTail = k;
    delete p;
}
void moveLastToFront(List& L)
{
    if (L.pHead == L.pTail) return;
    else
    {
        SwapHead (L);
    }
}

node * findMiddle(List L)
{
    node* p = L.pHead;
    if (p != NULL)
    {
        int dem = 0;
        while (p != NULL)
        {
            dem++;
            p = p->next;
        }
        int k = dem / 2;
        p = L.pHead;
        while (k > 0)
        {
            k--;
            p = p->next;
        }
        return p;
    }
    else return p;
}

int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L);
    cout<<endl;

    node *p=findMiddle(L); //Neu so phan tu chan thi co 2 phan tu chinh giua, chi xuat phan tu chinh giua thu 2
    if(p)cout<<"The middle element is "<<p->info;

    return 0;
}
