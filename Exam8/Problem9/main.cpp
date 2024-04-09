#include<iostream>
#include<cmath>
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

int dem = 0;
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
void AddNodeTail (DATHUC &B , DONTHUC * X , int &dem)
{
    if (dem == 0)
    {
        Init (B);
        dem++;
    }
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
void Nhap (DATHUC &B, double heso , int somu)
{
    DONTHUC * p = new DONTHUC;
    p->heso = heso;
    p->somu = somu;
    AddNodeTail (B, p , dem);
}
void Xuat (DATHUC B)
{
    int dem = 0;
    Node * p = B.head;
    if (p == NULL) cout<<0;
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


double TinhDaThuc (DATHUC B, double x)
{
    double Sum = 0;
    Node * p = B.head;
    while ( p != NULL )
    {
        Sum = Sum + p->data->heso * pow (x,p->data->somu);
        p = p->next;
    }
    return Sum;
}
int main() {
    DATHUC B;
    int n; cin >> n;
    double heso; int somu;
    for (int i = 0; i < n; i++)
    {
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
