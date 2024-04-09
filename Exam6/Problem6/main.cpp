#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;


struct Stack
{
    char ch[MAX];
    char ch1[MAX];
    char ch2[MAX];
    int a,b,c;
};
void Init (Stack &S)
{
    S.a =S.b =S.c = 0;
}
void Push (Stack &S, char x)
{
    if (x == '(')
    {
        S.ch[S.a] = x;
        S.a++;
    }
    if (x == '[')
    {
        S.ch1[S.b] = x;
        S.b++;
    }
    if (x == '{')
    {
        S.ch2[S.c] = x;
        S.c++;
    }
}
void Pop (Stack &S , char x)
{
    if (x == ')')
    {
        S.a--;
    }
    if (x == ']')
    {
        S.b--;
    }
    if (x == '}')
    {
        S.c--;
    }
}
bool IsEmpty (Stack S , char x)
{
    if (x == ')')
    {
        return !S.a;
    }
    if (x == ']')
    {
        return !S.b;
    }
    if (x == '}')
    {
        return !S.c;
    }
}
int isValid (string s)
{
    Stack S;
    Init (S);
    for (int i = 0 ; i< s.length() ; i++)
    {
        if (s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                Push (S,s[i]);
            }
            else
            {
                if (IsEmpty(S,s[i])) return 0;
                else Pop (S,s[i]);
            }
    }
    if (S.a == 0 && S.b == 0 && S.c == 0) return 1;
    return 0;
}
int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}
