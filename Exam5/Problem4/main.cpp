#include <iostream>
#include <cstring>
#include <string>
using namespace std;
struct node
{
    int info;
    node * next;
};
struct List
{
    node* Head;
    node* Tail;
};
node* GetNode (int x)
{
    node *p = new node;
    if (p!=NULL)
    {
        p->info = x;
        p->next = NULL;
    }
    return p;
}
void AddNode (List &L, int x)
{
    node* new_ele = GetNode (x);
    if (L.Tail == NULL)
    {
        L.Head = L.Tail = new_ele;
    }
    else
    {
        L.Tail->next = new_ele;
        L.Tail = new_ele;
    }
}void inputList (List &L, int n)
{
    int x;
    for (int i=0;i<n;i++)
    {
        cin>>x;
        AddNode (L,x);
    }
}
void outputList (List L)
{
    node* p = L.Head;
    if (p==NULL) cout<<"List is empty";
    while (p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
}
node* findMax (List L)
{
    node* p = L.Head;
    node *Max = L.Head;
    while (p!=NULL)
    {
        if (p->info > Max->info) Max = p;
        p=p->next;
    }
    if (Max==NULL) cout<<"List is empty";
    return Max;
}
void Init (List &L)
{
    L.Head = L.Tail = NULL;
}
int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);
    cout<<"\nThe maximum value: ";
    node *p = findMax(L);
    if(p) cout<<p->info;

    return 0;
}
