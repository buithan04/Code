#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Node
{
    int info;
    int Cot;
    int Muc;
    Node* left;
    Node* right;
};

Node* GetNode(int x, int Cot , int Muc)
{
    Node* p = new Node;
    p->info = x;
    p->Cot = Cot;
    p->Muc = Muc;
    p->left = p->right = NULL;
    return p;
}

typedef Node* Tree;

void Insert(Tree& T, int x, int Cot , int Muc)
{
    if (T != NULL)
    {
        if (x <= T->info)
            Insert(T->left, x, T->Cot - 1 , Muc + 1);
        else
            Insert(T->right, x, T->Cot + 1 , Muc + 1);
    }
    else
    {
        T = GetNode(x, Cot , Muc);
    }
}

void inputTree(Tree& T)
{
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        Insert(T, x, 0,0);
    }
}
void DoNode(Tree T, Node * p , map <int , Node *> &mp , set <int> &s)
{
    if (T != NULL)
    {
        if (s.count(T->Cot) == 0)
        {
            s.insert(T->Cot);
            mp[T->Cot] = T;
        }
        else
        {
            Node * p = mp[T->Cot];
            if (T->Muc < p->Muc) mp[T->Cot] = T;
        }
        DoNode(T->left,p,mp,s);
        DoNode(T->right,p,mp,s);
    }
}

int main()
{
    map <int , Node *> mp;
    set <int> s;
    multiset<int> v;
    Tree T = NULL;
    inputTree(T);
    DoNode(T, T ,mp ,s);
    for (pair<int , Node*> x : mp)
    {
        v.insert(x.second -> info);
    }
    for (auto x : v)
    {
        cout<<x<<" ";
    }

    return 0;
}
