#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; // so luong phan tu cua stack
};
void Init (Stack &S)
{
    S.n = 0;
}
void Push (Stack& S, int x)
{
    S.arr[S.n++] = x;
}
void DecimaltoBinary2 (int n, Stack &S)
{
    while (n!=0)
    {
        Push (S,n%2);
        n/=2;
    }
}
void printStack (Stack S)
{
    if (S.n == 0) cout<<0;
    else
    {
        for (int i = S.n -1; i >= 0 ; i--)
        {
            cout<<S.arr[i];
        }
    }
}
int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary2(n,S);
    printStack(S);
    return 0;
}
