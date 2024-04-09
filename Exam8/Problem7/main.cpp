
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct PRO
{
    int id;
    string name;
    int pop;
    double area;
    void Nhap ()
    {
        cin>>this->id;
        cin.ignore();
        getline (cin,this->name);
        cin>>this->pop;
        cin>>this->area;
    }
    void Xuat ()
    {
        cout<<this->id<<" ";
        cout<<this->name<<" ";
        cout<<this->pop<<" ";
        cout<<this->area<<" "<<endl;
    }
};
struct Node
{
    PRO info;
    Node * pNext;
    Node * pPrev;
};
struct List
{
    Node * pHead;
    Node * pTail;
};
Node * GetNode (PRO x)
{
    Node * p = new Node;
    p->info = x;
    p->pNext = p->pPrev = NULL;
    return p;
}
void AddNodeHead (List &L, PRO x)
{
    Node * p = GetNode (x);
    if (L.pHead == NULL && L.pTail == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead->pPrev = p;
        L.pHead = p;
    }
}
void AddNodeTail (List &L, PRO x)
{
    Node * p = GetNode (x);
    if (L.pHead == NULL && L.pTail == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        p->pPrev = L.pTail;
        L.pTail->pNext = p;
        L.pTail = p;
    }
}
void inputListProvinces (List &L)
{
    int n;cin>>n;
    PRO x;
    for (int i = 0; i < n ; i++)
    {
        x.Nhap();
        AddNodeTail (L,x);
    }
}
void outputListProvinces (List L)
{
    Node * p = L.pHead;
    if (p == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    while (p != NULL)
    {
        p->info.Xuat();
        p = p->pNext;
    }
}


void Init (List &L)
{
    L.pHead = L.pTail = NULL;
}


void removeList (List &L)
{
    Node * p = L.pHead;
    Node * tmp = NULL;
    while (p != NULL)
    {
        tmp = p->pNext;
        if (p == L.pHead)
        {
            if (p == L.pTail)
            {
                L.pHead = L.pTail = NULL;
                delete p;
            }
            else
            {
                L.pHead = p->pNext;
                L.pHead->pPrev = NULL;
                p->pNext = NULL;
                delete p;
            }
        }
        else if (p->pNext == NULL)
        {
            L.pTail = p->pPrev;
            L.pTail->pNext = NULL;
            p->pPrev = NULL;
            delete p;

        }
        else
        {
            p->pPrev->pNext = p->pNext;
            p->pNext->pPrev = p->pPrev;
            p->pNext = p->pPrev = NULL;
            delete p;
        }
        p = tmp;
    }
}
int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    if(L.pHead)
    {
        cout<<"Delete all:"<<endl;
        removeList(L);
        outputListProvinces(L);
    }
    return 0;
}
