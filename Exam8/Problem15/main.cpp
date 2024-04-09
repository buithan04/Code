#include <iostream>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::pair;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}
void add_tail(List &l, int x){
    Node*p = new Node;
    p->val = x;
    p->next = NULL;

    if (l.head == NULL){
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

void xuat(List &l){
    for(Node *p = l.head; p != NULL; p = p->next){
        cout << p->val << " ";
    }
    cout << endl;
}

pair <List, List> split (List l)
{
    Node * tmp = NULL;
    pair <List,List> ls;
    bool check = true;
    Node * p = l.head;
    while (p != NULL)
    {
        if (check)
        {
            add_tail (ls.first,p->val);
        }
        else
        {
            add_tail (ls.second,p->val);
        }
        check = !check;
        tmp = p;
        p = p->next;
        delete tmp;
    }
    return ls;
}

int main()
{
    List l; list_initializing(l);
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int x;
    do{
        cin >> x;
        if (x != 0) add_tail(l, x);
        else break;
    } while(true);


    pair<List, List> ls = split(l);

    xuat(ls.first);
    xuat(ls.second);

    return 0;
}
