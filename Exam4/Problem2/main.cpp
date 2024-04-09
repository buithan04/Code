
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef struct PROVINCE
{
    int id;
    string name;
    int pop;
    float area;
}pro;
struct node
{
    pro info;
    node* next;
};
struct List
{
    node * Head;
    node * Tail;
};

void Input1Pro (pro &a)
{
    cin>>a.id;
    cin.ignore();
    getline (cin,a.name);
    cin>>a.pop;
    cin>>a.area;
    cin.ignore();
}
node* GetNode (pro a)
{
    node* p = new node;
    if (p != NULL)
    {
        p->info = a;
        p->next = NULL;
    }
    return p;
}
void AddProvince (List &L , pro a)
{
    node* new_ele = GetNode(a);
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
void Init (List &L)
{
    L.Head = NULL;
    L.Tail = NULL;
}
void inputListProvinces (List &L)
{
    int n;cin>>n;
    pro a;
    for (int i = 0;i < n; i++)
    {
        Input1Pro (a);
        AddProvince (L,a);
    }
}
void outputListProvinces(List L)
{
    cout<<"ID |Province    |Population    |Area"<<endl;
    node* p = L.Head;
    while (p != NULL)
    {
        cout<<p->info.id<<" "<<p->info.name<<" "<<p->info.pop<<" "<<p->info.area<<endl;
        p = p->next;
    }
}
node* TimKiem (List L,string s)
{
    node* p = L.Head;
    while (p != NULL)
    {
        if (p->info.name == s) return p;
        p = p->next;
    }
    return p;
}
int main()
{
    string s;
    List L;
    Init (L);
    inputListProvinces (L);
    cout<<"List of provinces:"<<endl;
    outputListProvinces(L);
    cout<<"Enter the name to search:"<<endl;
    getline (cin,s);
    if (TimKiem(L,s)!=NULL)
    {
        node* p = TimKiem(L,s);
        pro x;
        cout<<"Input a new province:"<<endl;
        Input1Pro (x);
        node* new_ele = GetNode(x);
        new_ele->next = p->next;
        p->next = new_ele;
        cout<<"Updated List:"<<endl;
        outputListProvinces(L);
    }
    else cout<<"Not found"<<endl;

    return 0;
}
