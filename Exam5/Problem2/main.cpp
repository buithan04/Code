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
    Node* Head;
    Node* Tail;
};
void Init (List &L)
{
    L.Head = NULL;
    L.Tail = NULL;
}
Node* GetNode (int x)
{
    Node* p = new Node;
    if (p != NULL)
    {
        p->info = x;
        p->next = NULL;
    }
    return p;
}
void AddNode (List &L, int x)
{
    Node* new_ele = GetNode (x);
    if ( L.Tail == NULL)
    {
        L.Head = L.Tail = new_ele;
    }
    else
    {
        L.Tail->next = new_ele;
        L.Tail = new_ele;
    }
}
void inputList (List &L , int n)
{
    for (int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        AddNode (L,x);
    }
}
void outputList (List L)
{
    Node* p = L.Head;
    if (p==NULL) cout<<"List is empty";
    while (p!= NULL)
    {
        cout<<p->info<<" ";
        p = p->next;
    }
}
void outputGreaterThan(List L,int m)
{
    Node* p =L.Head;
    bool kt = true;
    if (p==NULL) cout<<"List is empty";
    else
    {
        while (p!=NULL)
    {
        if (p->info > m)
        {
            cout<<p->info<<" ";
            kt = false;
        }
        p=p->next;
    }
    if (kt) cout<<"None";
    }
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


    cout<<"\nEnter a number: "; int m; cin>>m;
    cout<<"\nValues greater than "<<m<<": ";
    outputGreaterThan(L,m);
    /*Xuat tat ca cac gia tri duoc luu trong ds lon hon m.
     Neu ds rong thi xuat thong bao "List is empty".
     Neu ds khong rong nhung khong co gia tri thoa yeu cau thi xuat "None"*/

    return 0;
}





