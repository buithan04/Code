#include  <iostream>
using namespace std;

struct DNode
{
	int info;
	DNode *pNext, *pPrev;
};

struct DList
{
	DNode *pHead, *pTail;
};

DNode* GetNode (int x)
{
    DNode* p = new DNode;
    if (p!=NULL)
    {
        p->info = x;
        p->pNext = p->pPrev = NULL;
    }
    return p;
}
void AddNode (DList &L , int x)
{
    DNode * new_ele = GetNode(x);
    if (L.pHead == NULL && L.pTail == NULL)
    {
        L.pHead = L.pTail = new_ele;
    }
    else
    {
        new_ele->pPrev = L.pTail;
        L.pTail->pNext=new_ele;
        L.pTail =new_ele;
    }
}
void init (DList &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
void createList (DList &L)
{
    int x;
    while (1)
    {
        cin>>x;
        if (x==-1) break;
        else AddNode (L,x);
    }
}
void printList (DList L)
{
    DNode* p = L.pHead;
    if (p==NULL) cout<<"List is empty";
    while (p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->pNext;
    }
}
int main()
{
	DList L;
	init(L);
	int x,y,choice;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n20. Exit"<<endl;

	while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
