#include <iostream>
#include <tuple>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::get;
using std::tuple;
using std::make_tuple;

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

tuple <List,List,List> partition(List &l, int x)
{
    tuple <List,List,List> ls ;
    Node * p = l.head;
    Node * tmp = NULL;
    while (p != NULL)
    {
        if (p->val < x)
        {
            add_tail (std::get<0>(ls),p->val);
        }
        else  if (p->val == x)
        {
            add_tail (std::get<1>(ls),p->val);
        }
        else
        {
            add_tail (std::get<2>(ls),p->val);
        }
        tmp = p;
        p = p->next;
        l.head = p;
        delete tmp;
    }
    l.tail = NULL;
    return ls;
}
void join (List &l , List &ls)
{
    Node * p = ls.head;
    Node * tmp = NULL;
    while (p != NULL)
    {
        add_tail (l,p->val);
        tmp = p;
        p = p->next;
        ls.head = p;
        delete tmp;
    }
    ls.tail = NULL;
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


    do{
        cin >> x;
        if (x == 0) break;

        auto ls = partition(l, x);

        xuat(std::get<0>(ls));
        xuat(std::get<1>(ls));
        xuat(std::get<2>(ls));


        join(l, std::get<0>(ls));
        join(l, std::get<1>(ls));
        join(l, std::get<2>(ls));

    } while(true);

    return 0;
}
