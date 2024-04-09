#include <iostream>

using namespace std;
struct Node
{
    int info;
    Node * left;
    Node * right;
};
Node * GetNode (int x)
{
    Node * p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}
typedef Node * Tree;
void Insert (Tree &T , int x)
{
    if (T != NULL)
    {
        if (x < T->info) Insert (T->left,x);
        else if (x > T->info) Insert (T->right,x);
    }
    else
    {
        T = GetNode (x);
    }
}
void LNR (Tree T)
{
    if (T!= NULL)
    {
        LNR (T->left);
        cout<<T->info<<" ";
        LNR(T->right);
    }
}
void inputTree (Tree &T)
{
    int n;cin>>n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        Insert(T,x);
    }
}
int countNodes (Tree T)
{
    if (T == NULL) return 0;
    return countNodes (T->left) + countNodes (T->right) + 1;
}
bool CheckSnt (int n)
{
    if (n < 2) return false;
    else
    {
        for (int i = 2; i <= n/2; i++)
        {
            if (n % i == 0) return false;
        }
        return true;
    }
}
int depthOfTree (Tree T)
{
    if (T == NULL) return -1;
    if (T->left == NULL && T->right == NULL) return 0;
    return max (depthOfTree (T->left),depthOfTree (T->right)) + 1;
}
void countEven (Tree T, int &count_even)
{
    if (T == NULL) return;
    if (T->info % 2 == 0) count_even++;
    countEven (T->left, count_even);
    countEven (T->right, count_even);
}
void countOdd (Tree T, int &count_odd)
{
    if (T == NULL) return;
    if (T->info % 2 != 0) count_odd++;
    countOdd (T->left, count_odd);
    countOdd (T->right, count_odd);

}
int countPositive(Tree T)
{

    if (T == NULL) return 0;
    if (T->info > 0) return 1 + countPositive (T->left) + countPositive(T->right);
    else return countPositive (T->left) + countPositive(T->right);
}
int countNegative(Tree T)
{
    if (T == NULL) return 0;
    if (T->info < 0) return 1 + countNegative(T->left) + countNegative (T->right);
    else return countNegative(T->left) + countNegative (T->right);
}
int countPrime (Tree T)
{
    if (T == NULL) return 0;
    if (CheckSnt(T->info)) return 1 + countPrime (T->left) + countPrime (T->right);
    else return countPrime (T->left) + countPrime (T->right);
}
void listPrime (Tree T)
{
    if (T!= NULL)
    {
        if (CheckSnt(T->info))cout<<T->info<<" ";
        listPrime (T->left);
        listPrime(T->right);
    }
}
int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"LNR: "; LNR(T); cout<<endl;

	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<depthOfTree(T)<<endl;

    int count_even = 0, count_odd =0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<countPositive(T)<<endl;
    cout<<"Number of negative nodes: "<<countNegative(T)<<endl;

    cout<<"Number of prime nodes: "<<countPrime(T)<<endl;
    cout<<"Prime numbers: "; listPrime(T);



	return 0;
}
