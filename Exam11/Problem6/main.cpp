#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node * left;
    Node * right;
};
typedef Node * Tree;
Node * getNode (int x)
{
    Node * p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}
Node * Search (Tree T, int b)
{
    if (T != NULL)
    {
        if (T->info == b) return T;
        if (!(Search(T->left,b))) return Search(T->right,b);
        else return Search(T->left,b);
    }
    else return T;
}
void SetRight (Node * p, int c)
{
    if (p != NULL)
    {
        if (p->right != NULL) cout << "Da co node con ben phai\n";
        else
        {
            Node * q = getNode(c);
            p->right = q;
        }
    }
    else cout<<"Node khong ton tai\n";
}
void SetLeft (Node * p, int c)
{
    if (p != NULL)
    {
        if (p->left != NULL) cout << "Da co node con ben trai\n";
        else
        {
            Node * q = getNode(c);
            p->left = q;
        }
    }
    else cout<<"Node khong ton tai\n";
}
void LNR (Tree T)
{
    if (T != NULL)
    {
        LNR (T->left);
        cout<<T->info<<" ";
        LNR (T->right);
    }
}
int main()
{
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break; // Neu khong phai L hoac R thi ket thuc viec tao cay
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c); // chen c vao ben trai b
        else if (a=='R') SetRight(Search(T,b),c); // chen c vao ben phai b
    }
	cout<<"\nLNR: "; LNR(T); cout<<endl;

	return 0;
}
