#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;
struct Stack
{
    char ch[MAX];
    int n;
};
void Init (Stack &S)
{
    S.n = 0;
}
void Push (Stack &S , char x)
{
    S.ch[S.n] = x;
    S.n++;
}
void Pop (Stack &S)
{
    S.n--;
}
bool IsEmpty (Stack S)
{
    return !(S.n);
}
int isValid (string s)
{
    Stack S;
    Init(S);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i]=='(')
            {
                Push (S,s[i]);
            }
            else if (s[i] == ')')
            {
                if (S.ch[S.n-1] == '(')
                {
                    if (IsEmpty(S)) return 0;
                    Pop(S);
                }
                else return 0;
            }
        }
        if (S.n != 0) return 0;
        return 1;
}

int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}
