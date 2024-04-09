#include <iostream>
#include <string>
using namespace std;
struct SP
{
    int Ma;
    string Ten;
    string ChungLoai;
    int NamSanXuat;
    int SoNamBaoHanh;
};
void Nhap (SP &x)
{
    cin>>x.Ma;
    cin.ignore();
    getline (cin,x.Ten);
    getline (cin,x.ChungLoai);
    cin>>x.NamSanXuat;
    cin>>x.SoNamBaoHanh;
}
void Xuat (SP x)
{
    cout<<x.Ma<<" ";
    cout<<x.Ten<<" ";
    cout<<x.ChungLoai<<" ";
    cout<<x.NamSanXuat<<" ";
    cout<<x.SoNamBaoHanh<<endl;
}
struct Node
{
    SP info;
    Node * left;
    Node * right;
};
Node * GetNode (SP x)
{
    Node * p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}
typedef Node * Tree;
void Insert (Tree &T , SP x)
{
    if (T != NULL)
    {
        if (x.SoNamBaoHanh <= T->info.SoNamBaoHanh) Insert (T->left,x);
        else  Insert (T->right,x);
    }
    else
    {
        T = GetNode (x);
    }
}


void inputTree (Tree &T)
{
    int n;cin>>n;
    SP x;
    for (int i = 0; i < n; i++)
    {
        Nhap(x);
        Insert(T,x);
    }
}
void listProduct (Tree T,string type)
{
    if (T!= NULL)
    {
        if (T->info.ChungLoai == type ) Xuat(T->info);
        listProduct (T->right,type);
        listProduct (T->left,type);
    }
}
int countProduct (Tree T, int year)
{
    if (T != NULL)
    {
        if (T->info.SoNamBaoHanh > year) return 1 + countProduct (T->left,year) + countProduct (T->right,year);
        else return countProduct (T->left,year) + countProduct (T->right,year);
    }
    else return 0;
}
int main()
{
    Tree T = NULL;
    inputTree(T);

    string type;  cin.ignore(); getline(cin,type);
    cout<<"List of products whose type is  "<<type<<": ";
    cout<<"\nID\tName\tType\tYear\tWarranty\n";
    listProduct(T,type);

    int year;cin>>year;
    cout<<"Number of products with more than "<<year<<" years of warranty: "<<countProduct(T,year)<<endl;


	return 0;
}
