#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
string Tinh (string s)
{
    stack <char> ch;
    stack <char> ch1;
    for (int i = 0 ; i < s.length(); i++)
    {
        if (s[i] >= '0'  && s[i]<='9')
        {
            ch.push (s[i]);
        }
        else if (s[i]== '+' || s[i]== '-' || s[i]=='*' || s[i]== '/')
        {
            ch1.push(s[i]);
        }
    }
    while (ch.size())
    {
        cout<<ch.top()<<" ";
        ch.pop();
    }

}
int main()
{
    string s;
    cin>>s;
    cout<<Tinh(s);
    return 0;
}
