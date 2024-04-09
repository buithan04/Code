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
void Init (List & L)
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
node * findValX (List L , int x , node*& z)
{
    node * p = L.pHead;
    while (p != NULL)
    {
        if (p->info == x) break;
        z = p;
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
node * swapNode (List &L , int x , int y)
{
    node * p1 = NULL;
    node * q1 = NULL;
    node * p = findValX (L,x,p1);
    node * q = findValX (L,y,q1);
    node * k = NULL;
    if (p == NULL || q == NULL) return k;
    else
    {
        if (p1 == NULL)
        {
            q1->next = p;
            node * tmp = p->next;
            p->next = q->next;
            q->next = tmp;
            if (p->next == NULL) L.pTail = p;
            L.pHead = q;
        }
        else
        {
            if (q1 == NULL)
            {
                p1->next = q;
                node * tmp = q->next;
                q->next = p->next;
                p->next = tmp;
                if (q->next == NULL) L.pTail = q;
                L.pHead = p;
            }
            else
            {
                p1->next = q;
                q1->next = p;
                node *tmp = p->next;
                p->next = q->next;
                q->next = tmp;
                if (q->next == NULL) L.pTail = q;
                if (p->next == NULL) L.pTail = p;
            }
        }
    }
    return p;
}
int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L);
    cout<<endl;

    int x, y; cin>>x>>y;
    node *p = swapNode(L,x,y); // Tim 2 node chua x va y, Hoan vi 2 node, thay doi cac moi lien ket giua cac node
    /* Tim 2 node chua x va y,
    Hoan vi 2 node do,
    nghia la: Thay doi moi lien ket giua cac node co lien quan, doi cho cac node, gia tri chua trong cac node khong thay doi
    Ham return node chua x ban dau, luc chua hoan vi*/

    cout<<"Updated List after swapping "<<x<<" and "<<y<<": "<<endl;
    outputList(L);
    cout<<endl;

    /* Kiem tra xem co that su hoan vi 2 node khong
    Neu hoan vi node thi node chua x ban dau cung van chua x, gia tri cua node khong thay doi*/
    if(p) // co doi cho
    {
        cout<<"At the address of "<<x<< ": ";
        cout<<p->info;
    }
    else cout<<"Can not swap";
    return 0;
}
