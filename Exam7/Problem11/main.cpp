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
void init (List & L)
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

node * findElementFromEnd(List L,int i)
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
        if (i > 0 && i <= dem)
        {
            p = L.pHead;
            int k = dem - i;
            while (k > 0)
            {
                k--;
                p = p->next;
            }
            return p;
        }
        else
        {
            cout<<"The index is invalid";
            p = NULL;
            return p;
        }
    }
    else
    {
        cout<<"List is empty";
        return p;
    }
}
void concate (List &L1, List L2)
{
    if (L1.pHead == NULL)
    {
        L1.pHead = L2.pHead;
        L1.pTail = L2.pTail;
    }
    else
    {
        if (L2.pTail != NULL)
        {
            L1.pTail->next = L2.pHead;
            L1.pTail = L2.pTail;
        }
        else return;
    }
}
node * findVal (List L, int x)
{
    node * p = L.pHead;
    while (p != NULL)
    {
        if (p->info == x) break;
        p = p->next;
    }
    return p;
}
node * swapData (List &L, int x, int y)
{
    node * p = findVal (L,x);
    node * q = findVal (L,y);
    node * k = NULL;
    if (p == NULL || q == NULL) return k;
    else
    {
        int tmp = p->info;
        p->info = q->info;
        q->info = tmp;
        return p;
    }
}
int MaxList (List L)
{
    int dem = 0;
    node * p =L.pHead;
    while (p != NULL)
    {
        dem++;
        p = p->next;
    }
    return dem;
}

void MySort (List &L)
{
    node* p ;
    int dem = MaxList (L);
    int i = 0;
    int j = 0;
    bool k = true;
    while (i < dem - 1 && k)
    {
        k = false;
        p = L.pHead;
        j = 0;
        while (j < dem - i - 1)
        {
            node * q = p->next;
            if (p->info > q->info)
            {
                int tmp = p->info;
                p->info = q->info;
                q->info = tmp;
                k = true;
            }
            j++;
            p = q;
        }
        i++;
    }
}
int MySearch (List L, int x)
{
    int dem = 0;
    node * p = L.pHead;
    while (p != NULL)
    {
        if (p->info == x) return dem;
        dem++;
        p = p->next;
    }
    if (p == NULL) return -1;
}
int main()
{
    int n; cin>>n;
    List L;init (L);
    inputList(L,n);
    MySort(L);
    cout<<"Sorted List: ";
    outputList(L);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = MySearch(L,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}
