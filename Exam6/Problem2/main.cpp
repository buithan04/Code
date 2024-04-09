#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int t; // t là chỉ số của phần tử cuối mảng, tức là đỉnh stack
};
void Init(Stack &S)
{
    S.t=-1; //Khi stack chưa có phần tử nào thì top được khởi tạo là -1,
            // nếu khởi tạo t = 0 là SAI vì khi đó sẽ hiểu top tại a[0]
}
bool IsEmpty (Stack S)
{
    if (S.t == -1) return true;
    return false;
}
bool IsFull (Stack S)
{
    return S.t + 1 == MAX;
}
void Push (Stack &S, int x)
{
    if (!IsFull(S))
    {
        S.t ++;
        S.arr[S.t] = x;
    }
}
void printStack (Stack S)
{
    if (IsEmpty(S)) cout<<"Stack is empty";
    else
    {
        for (int i = 0; i <= S.t; i++)
        {
            cout<<S.arr[i]<<" ";
        }
    }
}
int Top (Stack S)
{
    if (IsEmpty(S)) return -1;
    else return S.arr[S.t];
}
void Pop (Stack &S)
{
    if (!IsEmpty(S))
    {
        S.arr[S.t] = 0;
        S.t -=1;
    }
}
int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    for (int i= 1; i<=n; i++)
    {
        cin>>x;
        Push(S,x);

    }
    cout<<"Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    Pop(S);
    cout<<"\nUpdated Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    return 0;
}
