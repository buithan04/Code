
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
DNode * GetNode (int x)
{
    DNode * p = new DNode;
    p->info = x;
    p->pNext = p->pPrev = NULL;
    return p;
}
void addTail (DList& L, int x)
{
    DNode * new_ele = GetNode(x);
    if (L.pTail == NULL)
    {
        L.pHead = L.pTail = new_ele;
    }
    else
    {
        new_ele->pPrev = L.pTail;
        L.pTail->pNext = new_ele;
        L.pTail = new_ele;
    }
}
void addHead (DList& L, int x)
{
    DNode * new_ele = GetNode(x);
    if (L.pHead == NULL)
    {
        L.pHead = L.pTail = new_ele;
    }
    else
    {
        new_ele->pNext = L.pHead;
        L.pHead->pPrev = new_ele;
        L.pHead = new_ele;
    }
}
void createList(DList &L)
{
    int x;
    while (1)
    {
        cin>>x;
        if (x == -1) break;
        else addTail (L,x);
    }
}
void printList(DList L)
{
    DNode * p = L.pHead;
    if (p == NULL) cout<<"List is empty";
    while (p != NULL)
    {
        cout<<p->info<<" ";
        p = p->pNext;
    }

}
void addAfter(DList &L,int x,int y)
{
    DNode * p = L.pHead;
    while (p != NULL)
    {
        if (p->info == x)
        {
            if (p->pNext == NULL) addTail(L,y);
            else
            {
                DNode * new_ele = GetNode(y);
                new_ele->pNext = p->pNext;
                new_ele->pPrev = p;
                p->pNext->pPrev = new_ele;
                p->pNext = new_ele;
            }
            return;
        }
        p = p->pNext;
    }
    if (p == NULL) cout << "\nCan't find the value "<<x;
}

void addBefore(DList &L,int x,int y)
{
    DNode * p = L.pHead;
    while (p != NULL)
    {
        if (p->info == x)
        {
            if (p->pPrev == NULL) addHead(L,y);
            else
            {
                DNode * new_ele = GetNode(y);
                new_ele->pNext = p;
                new_ele->pPrev = p->pPrev;
                p->pPrev->pNext = new_ele;
                p->pPrev = new_ele;
            }
            return;
        }
        p = p->pNext;
    }
    if (p == NULL) cout << "\nCan't find the value "<<x;
}

void addAfterMulti (DList &L,int x,int y)
{
    int dem = 0;
    DNode * p = L.pTail;
    DNode * new_ele = NULL;
    while (p != NULL)
    {
        if (p->info == x)
        {
            dem++;
            if (p->pNext == NULL) addTail(L,y);
            else
            {
                new_ele = GetNode(y);
                new_ele->pNext = p->pNext;
                new_ele->pPrev = p;
                p->pNext->pPrev = new_ele;
                p->pNext = new_ele;
            }
        }
        p = p->pPrev;
    }
    if (dem == 0 || L.pHead == NULL) cout << "\nCan't find the value "<<x;
}
void addBeforeMulti (DList &L,int x,int y)
{
    int dem = 0;
    DNode * p = L.pHead;
    DNode * new_ele = NULL;
    while (p != NULL)
    {
        if (p->info == x)
        {
            dem++;
            if (p == L.pHead)
            {
                addHead(L,y);
            }
            else
            {
                new_ele = GetNode(y);
                new_ele->pNext = p;
                new_ele->pPrev = p->pPrev;
                p->pPrev->pNext = new_ele;
                p->pPrev = new_ele;
            }
        }
        p = p->pNext;
    }
    if (dem == 0 || L.pHead == NULL) cout << "\nCan't find the value "<<x;
}
void init (DList &L)
{
    L.pHead = L.pTail = NULL;
}
void removeHead(DList &L )
{
    char k;
    DNode * p = L.pHead;
    if (p == NULL) cout<<"\nList is empty. Can't delete";
    else
    {
        cout<<"\nDo you want to delete the first element?(y/n): ";
        cin>>k;
        if (k == 'Y' || k == 'y')
        {
            if (p == L.pTail)
            {
                L.pHead = L.pTail = NULL;
                delete p;
                cout<<"\nThe list becomes empty";
            }
            else
            {
                L.pHead = p->pNext;
                L.pHead->pPrev = NULL;
                delete p;
            }
        }
    }

}

void removeTail(DList &L )
{
        char k;
        DNode * p = L.pTail;
        if (p == NULL) cout<<"\nList is empty. Can't delete";
        else
        {
            cout<<"\nDo you want to delete the last element?(y/n): ";
            cin>>k;
            if (k == 'Y' || k == 'y')
            {
                if (p == L.pHead)
                {
                    L.pHead = L.pTail = NULL;
                    delete p;
                    cout<<"\nThe list becomes empty";
                }
                else
                {
                    L.pTail = p->pPrev;
                    L.pTail->pNext = NULL;
                    delete p;
                }
            }
        }
}

DNode * Search (DList L, int x)
{
    DNode * p = L.pHead;
    while (p != NULL)
    {
        if (p->info == x) return p;
        p = p->pNext;
    }
    return p;
}
void removeNode (DList &L, int x)
{
    DNode * p = Search (L,x);
    if (p)
    {
        char k;
        cout<<"\nDo you want to delete "<<x<<" ?(y/n): ";
        cin>>k;
        if (k == 'y' || k == 'Y')
        {
            if (p->pPrev == NULL)
            {
                if (p == L.pTail)
                {
                    L.pHead = L.pTail = NULL;
                    delete p;
                    cout<<"\nThe list becomes empty";
                    return;
                }
                else
                {
                    L.pHead = p->pNext;
                    L.pHead->pPrev = NULL;
                }
            }
            else
            {
                if (p->pNext == NULL)
                {
                    L.pTail = p->pPrev;
                    L.pTail->pNext = NULL;

                }
                else
                {
                    p->pPrev->pNext = p->pNext;
                    p->pNext->pPrev = p->pPrev;

                }
            }
            delete p;
        }
    }
    else cout << "\nCan't find the value "<<x;
}


void removeMultiNodeS(DList &L, int x)
{

    DNode * p = Search(L,x);
    if (p)
    {
        DNode * tmp = NULL;
        char k;
        cout<<"\nDo you want to delete "<<x<<"s ?(y/n): ";
        cin>>k;
        if (k == 'Y' || k == 'y')
        {
            while (p != NULL)
            {
                if (p->info == x)
                {
                    tmp = p;
                    p = p->pNext;
                    if (tmp->pPrev == NULL)
                    {
                        if (tmp == L.pTail)
                        {
                            L.pHead = L.pTail = NULL;
                            delete tmp;
                            cout<<"\nThe list becomes empty";
                            return;
                        }
                        else
                        {
                            L.pHead = tmp->pNext;
                            L.pHead->pPrev = NULL;
                        }
                    }
                    else
                    {
                        if (tmp->pNext == NULL)
                        {
                            L.pTail = tmp->pPrev;
                            L.pTail->pNext = NULL;
                        }
                        else
                        {
                            tmp->pPrev->pNext = tmp->pNext;
                            tmp->pNext->pPrev = tmp->pPrev;
                        }
                    }
                    delete tmp;

                }
                else p = p->pNext;
            }
        }
    }
    else cout << "\nCan't find the value "<<x;
}

int main()
{
	DList L;
	init(L);
	int x,y,choice; char c;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n9. Delete the first element";
    cout<<"\n10. Delete the last element";
    cout<<"\n11. Delete the first element containing a specific value";
    cout<<"\n12. Delete all elements storing a particular value";
    cout<<"\n13. Delete the element after a specific value (only for the first one found)";
    cout<<"\n14. Delete the element before a specific value (only for the first one found)";
    cout<<"\n15. Delete all elements after a specific value";
    cout<<"\n16. Delete all elements before a specific value";
    cout<<"\n17. Delete all elements";
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
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 5:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 7:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfterMulti(L,x,y);
            break;
        case 8:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBeforeMulti(L,x,y);
            break;
        case 9:
            removeHead(L);
            break;
        case 10:
            removeTail(L);
            break;
        case 11:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeNode(L,x);
            break;
        case 12:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiNodeS(L,x);
            break;

        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}




