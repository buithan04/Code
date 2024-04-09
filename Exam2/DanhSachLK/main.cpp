#include <iostream>

using namespace std;
struct Node
{
    int info;
    Node* next;

};
struct LIST
{
    Node* Head = NULL;
    Node* Tail = NULL;
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
void AddNode (LIST &L , int x)
{
    Node* new_ele = GetNode (x);
    if (L.Head==NULL )
    {
        L.Head = L.Tail = new_ele;
    }
    else
    {
        L.Tail->next = new_ele;
        L.Tail = new_ele;
    }
}

void InDS (LIST L)
{
    Node* p = L.Head;
    while (p != NULL)
    {
        cout<<p->info<<" ";
        p = p->next;
    }
}
void Chen (LIST &L ,int a ,int x)
{
    Node* p = L.Head;
    while (p != NULL)
    {
        if (p->info == a)
        {
            if (p == L.Tail) AddNode(L,x);
            else
            {
                Node * new_ele = GetNode(x);
                new_ele->next = p->next;
                p->next = new_ele;
            }
            return;
        }
        p = p->next;
    }
    cout<<"Khong Tim Thay Vi Tri"<<endl;
}
void Remove (LIST &L , int x)
{
    Node * p = L.Head;
    Node * k = NULL;
    while (p != NULL)
    {
        if (p->info == x)
        {
            if (p == L.Head )
            {
                if (p == L.Tail)
                {
                    L.Head = L.Tail = NULL;
                }
                else
                {
                    L.Head = L.Head->next;
                    p->next = NULL;
                }
                delete p;
            }
            else
            {
                k->next = p->next;
                if (p == L.Tail) L.Tail = k;
                p->next = NULL;
                delete p;
            }
            return;
        }
        k = p;
        p = p->next;
    }
    cout<<"Khong Tim Thay Vi Tri"<<endl;
}
int main()
{
    int n;
    cin >> n;
    LIST L;
    int x;
    for (int i = 0 ; i < n; i++)
    {
        cin >> x;
        AddNode(L,x);
    }
    InDS (L);
    int a;
    cout << "\nNhap vi tri can chen : " ;
    cin >> a;
    cout<< "Nhap Gia Tri Can Chen : ";
    cin>>x;
    Chen(L,a,x);
    InDS(L);
    cout<< "\nNhap Gia Tri Can Xoa :";
    cin>>x;
    Remove(L,x);
    InDS(L);


    return 0;
}
