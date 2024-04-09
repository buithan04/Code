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
    Node * Head;
    Node * Tail;
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
    if (L.Head == NULL && L.Tail == NULL)
    {
        L.Head = L.Tail = p;
    }
    else
    {
        p->pNext = L.Head;
        L.Head->pPrev = p;
        L.Head = p;
    }
}
void AddNodeTail (List &L, PRO x)
{
    Node * p = GetNode (x);
    if (L.Head == NULL && L.Tail == NULL)
    {
        L.Head = L.Tail = p;
    }
    else
    {
        p->pPrev = L.Tail;
        L.Tail->pNext = p;
        L.Tail = p;
    }
}
void inputList (List &L, int n)
{
    PRO x;
    for (int i = 0; i < n ; i++)
    {
        x.Nhap();
        AddNodeTail (L,x);
    }
}
void Printf (List L)
{
    cout<<"ID |Province |Population |Area"<<endl;
    Node * p = L.Head;
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

void RemoveX (List &L, string s, bool &k)
{
    Node * p = L.Head;
    while (p != NULL)
    {
        if (p->info.name == s)
        {
            k = true;
            if (p == L.Head)
            {
                if (p == L.Tail)
                {
                    L.Head = L.Tail = NULL;
                    delete p;
                }
                else
                {
                    L.Head = p->pNext;
                    L.Head->pPrev = NULL;
                    p->pNext = NULL;
                    delete p;
                }

                return;
            }
            else if (p->pNext == NULL)
            {
                L.Tail = p->pPrev;
                L.Tail->pNext = NULL;
                p->pPrev = NULL;
                delete p;
                return;
            }
            else
            {
                p->pPrev->pNext = p->pNext;
                p->pNext->pPrev = p->pPrev;
                p->pNext = p->pPrev = NULL;
                delete p;
                return;
            }
        }
        p = p->pNext;
    }
    if (p == NULL) cout<<"Not found"<<endl;
}
void Init (List &L)
{
    L.Head = L.Tail = NULL;
}
void DaoChuoi (string &s)
{
    char k;
    for (int i = 0; i < s.length()/2 ; i++)
    {
        k = s[i];
        s[i] = s[s.length() - 1 - i];
        s[s.length() - 1 - i] = k;
    }
}
bool Ktra (string s, string k)
{
    string token = "";
    for (int i = s.length()-1; i >=0 ; i--)
    {
        if (s[i] == ' ') break;
        else token += s[i];
    }
    DaoChuoi (token);
    return token == k;
}
void RemoveX2 (List &L, string k, bool &f)
{
    Node * p = L.Head;
    Node * tmp = NULL;
    while (p != NULL)
    {
        if (Ktra(p->info.name,k))
        {
            tmp = p->pNext;
            f = true;
            if (p == L.Head)
            {
                if (p == L.Tail)
                {
                    L.Head = L.Tail = NULL;
                    delete p;
                }
                else
                {
                    L.Head = p->pNext;
                    L.Head->pPrev = NULL;
                    p->pNext = NULL;
                    delete p;
                }
            }
            else if (p->pNext == NULL)
            {
                L.Tail = p->pPrev;
                L.Tail->pNext = NULL;
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
        else p = p->pNext;
    }
    if (!(f)) cout<<"Not found"<<endl;
}
int main()
{

    bool f = false;
    List L;
    Init (L);
    int n;cin>>n;

    string z;
    inputList (L,n);
    cout<<"List of provinces:"<<endl;
    Printf (L);
    if (n > 0)
    {

        cout<<"Enter the last word of name to search:"<<endl;
        cin>>z;
        RemoveX2 (L,z,f);
        if (f)
        {
            cout<<"Updated List:"<<endl;
            Printf (L);
        }

    }
    return 0;
}
