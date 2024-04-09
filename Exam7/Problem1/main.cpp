#include <iostream>
#include <cstring>
#include <string>
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
void AddNode (List &L , int x)
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
void inputList (List &L , int n)
{
    int x;
    for (int i = 0; i < n ; i++)
    {
        cin>>x;
        AddNode(L,x);
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
int main()
{
    List L; // Khai bao 1 danh sach
    Init(L); // Khoi tao danh sach
    int n; cout<<"Enter a number: "; cin>>n; // Nhap so luong phan tu cua ds
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n); // Nhap 1 day gom n so va luu vao ds. Phan tu moi duoc them vao cuoi ds
    cout<<"\nThe created Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"

    return 0;
}
