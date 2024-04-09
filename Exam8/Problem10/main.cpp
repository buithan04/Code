/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
[
]
define
include
###End banned keyword*/
#include<iostream>
#include <iomanip>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
};


struct Node{
	DONTHUC* data;
	Node* next;

};

typedef struct DATHUC{
	Node* head;
	Node* tail;
}List;


Node * GetNode (DONTHUC * X)
{
    Node * p = new Node;
    p->data = X;
    p->next = NULL;
    return p;
}
void Init (DATHUC & B)
{
    B.head = B.tail = NULL;
}
void AddNodeTail (DATHUC &B , DONTHUC * X )
{

    Node * new_ele = GetNode (X);
    if (B.head == NULL)
    {
        B.head = B.tail = new_ele;
    }
    else
    {
        B.tail->next = new_ele;
        B.tail = new_ele;
    }
}
void Nhap (DATHUC &B)
{
    Init (B);
    int n;cin>>n;
    for (int i = 0; i < n ; i++)
    {
        DONTHUC * p = new DONTHUC;
        cin>>p->heso;
        cin>>p->somu;
        AddNodeTail (B, p);
    }
}
void Xuat (DATHUC B)
{
    int dem = 0;
    Node * p = B.head;
    if (p == NULL)
    {
        cout<<0;
        return;
    }
    while (p != NULL)
    {
            if (p->data->heso > 0)
            {
                if (dem == 0)
                {
                    if (p->data->somu == 0) cout<<p->data->heso;
                    else if (p->data->somu == 1)
                    {
                        if (p->data->heso == 1) cout<<"x";
                        else cout<<p->data->heso<<"x";
                    }
                    else
                    {
                        if (p->data->heso == 1) cout<<"x^"<<p->data->somu;
                        else cout<<p->data->heso<<"x^"<<p->data->somu;
                    }
                }
                else
                {
                    if (p->data->somu == 0) cout<<"+"<<p->data->heso;
                    else if (p->data->somu == 1)
                    {
                        if (p->data->heso == 1) cout<<"+x";
                        else cout<<"+"<<p->data->heso<<"x";
                    }
                    else
                    {
                        if (p->data->heso == 1) cout<<"+x^"<<p->data->somu;
                        else cout<<"+"<<p->data->heso<<"x^"<<p->data->somu;
                    }
                }
                dem++;
            }
            else  if (p->data->heso < 0)
            {
                dem++;
                if (p->data->somu == 0) cout<<p->data->heso;
                else if (p->data->somu == 1)
                {
                    if (p->data->heso == -1) cout<<"-x";
                    else cout<<p->data->heso<<"x";
                }
                else
                {
                    if (p->data->heso == -1) cout<<"-x^"<<p->data->somu;
                    else cout<<p->data->heso<<"x^"<<p->data->somu;
                }
            }
        p = p->next;
    }
    if (dem == 0) cout<<0;
    cout<<endl;
}

DATHUC Tong2DaThuc ( DATHUC A, DATHUC B)
{
    DATHUC C;
    Init (C);
    Node * p = A.head;
    Node * q = B.head;
    while (p != NULL && q != NULL)
    {
        if (p->data->somu > q->data->somu)
        {
            DONTHUC * new_ele = new DONTHUC;
            new_ele->heso = p->data->heso;
            new_ele->somu = p->data->somu;
            AddNodeTail (C,new_ele);
            p = p->next;
        }
        else if (p->data->somu < q->data->somu)
        {
            DONTHUC * new_ele = new DONTHUC;
            new_ele->heso = q->data->heso;
            new_ele->somu = q->data->somu;
            AddNodeTail (C,new_ele);
            q = q->next;
        }
        else
        {
            DONTHUC * new_ele = new DONTHUC;
            new_ele->heso = p->data->heso + q->data->heso;
            new_ele->somu = p->data->somu;
            AddNodeTail (C,new_ele);
            q = q->next;
            p = p->next;
        }
    }
    while (p != NULL)
    {
        DONTHUC * new_ele = new DONTHUC;
            new_ele->heso = p->data->heso;
            new_ele->somu = p->data->somu;
            AddNodeTail (C,new_ele);
        p = p->next;
    }
    while (q != NULL)
    {
        DONTHUC * new_ele = new DONTHUC;
            new_ele->heso = q->data->heso;
            new_ele->somu = q->data->somu;
            AddNodeTail (C,new_ele);
        q = q->next;
    }
    return C;
}

//###INSERT CODE HERE -



int main() {
    DATHUC A, B;
    Nhap(A);
    Nhap(B);
    cout << "Da thuc A: "; Xuat(A);
    cout << "\nDa thuc B: "; Xuat(B);
    cout << "\nA+B = "; Xuat(Tong2DaThuc(A, B));
    return 0;
}
