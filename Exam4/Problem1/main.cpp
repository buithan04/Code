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
    node* p = L.Head;
    while (p != NULL)
    {
        cout<<p->info.id<<" "<<p->info.name<<" "<<p->info.pop<<" "<<p->info.area<<endl;
        p = p->next;
    }
}
void outputProvincesMore1MillionPop (List L)
{
    node* p = L.Head;
    while (p != NULL)
    {
        if (p->info.pop*1000 > 1000000)
        {
            cout<<p->info.id<<" "<<p->info.name<<" "<<p->info.pop<<" "<<p->info.area<<endl;
        }
        p = p->next;
    }
}
node* findProMaxArea(List L)
{
    node* p = L.Head;
    node* Max = L.Head;
    while (p != NULL)
    {
        if (p->info.area > Max->info.area)
        {
            Max = p;
        }
        p = p->next;
    }
    return Max;
}
void outputProvince (pro p)
{
    cout<<p.id<<" "<<p.name<<" "<<p.pop<<" "<<p.area<<endl;
}
int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    cout<<"Provinces with a population of more than 1 million:"<<endl;
    outputProvincesMore1MillionPop(L);

    cout<<"The largest province:"<<endl;
    node *p = findProMaxArea(L);
    if(p) outputProvince(p->info);

    return 0;
}
