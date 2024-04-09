#include <iostream>
using namespace std;

/*Cach 1: Khi da cai dat List roi, dinh nghia Stack dua tren List
struct Stack
{
	List L;
};

Cach 2: Cai dat lai Stack tu dau, giong nhu List
struct node
{
    int info;
    node *next;
};
struct Stack
{
    node *pHead; // pTail khong co cung duoc

};*/
struct Node
{
    int info;
    Node * next;
};
struct Stack
{
    Node * pHead;
};
Node * GetNode (int x)
{
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}
void AddNode (Stack &S , int x)
{
    Node* p = GetNode (x);
    if (S.pHead == NULL) S.pHead = p;
    else
    {
        p->next = S.pHead;
        S.pHead = p;
    }
}
void Init (Stack &S)
{
    S.pHead = NULL;
}
void DecimaltoBinary1 (int n , Stack &S)
{
    while (n!=0)
    {
        AddNode (S,n%2);
        n/=2;
    }
}
void printStack (Stack S)
{
    Node* p = S.pHead;
    if (p == NULL) cout<<0;
    while (p!=NULL)
    {
        cout<<p->info;
        p = p->next;
    }
}
int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary1(n,S);
    printStack(S);
    return 0;
}
