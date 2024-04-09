#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int KiemTra (string s)
{
    stack <char> ch;
    stack <char> ch1;
    stack <char> ch2;

    for (int i = 0;i < s.length() ; i++)
    {
        if (s[i]== '{')
            {
                ch.push(s[i]);
            }
            else if (s[i]=='}')
            {
                if (ch.empty()) return 0;
                else ch.pop();
            }
        if (s[i]== '(')
            {
                ch1.push(s[i]);
            }
            else if (s[i]==')')
            {
                if (ch1.empty()) return 0;
                else ch1.pop();
            }
        if (s[i]== '[')
            {
                ch2.push(s[i]);
            }
            else if (s[i]==']')
            {
                if (ch2.empty()) return 0;
                else ch2.pop();
            }
    }
    if (ch.empty() && ch1.empty() && ch2.empty()) return 1;
    return 0;
}
int main()
{
    string s;
    cin>>s;
    cout<<KiemTra(s);
    return 0;
}
