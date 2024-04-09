#include <iostream>
#include <cstring>
#include <string>
using namespace std;
struct node
{
    int info;
    node* next;
};
struct List
{
    node* Head;
    node* Tail;
};
void Init (List &L)
{
    L.Head = L.Tail = NULL;
}
node* Getnode (int x)
{
    node* p = new node;
    if (p!=NULL)
    {
        p->info=x;
        p->next = NULL;
    }
    return p;
}
void Addnode (List &L, int x)
{
    node* new_ele = Getnode(x);
    if (L.Tail == NULL)
    {
        L.Tail = L.Head = new_ele;
    }
    else
    {
        L.Tail->next = new_ele;
        L.Tail = new_ele;
    }
}
void inputList (List &L, int n)
{
    int x;
    for (int i=0;i<n;i++)
    {
        cin>>x;
        Addnode (L,x);
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
node* findElement (List L,int i)
{
    int k=1;
    node* p =L.Head;
    while (p!=NULL && k<i)
    {
        k++;
        p=p->next;
    }
    if (p==NULL && k==1) cout<<"List is empty";
    if (p==NULL && k <=i && k!=1) cout<<"The index is invalid";
    return p;
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

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<": ";
    node *p = findElement(L,i);
    if(p) cout<<p->info;


    return 0;
}
