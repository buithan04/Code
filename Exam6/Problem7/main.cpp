#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack <int> s;
    int n;
    cin>>n;
    while (n!=0)
    {
        s.push(n%2);
        n=n/2;
    }

    if (s.size()==0) cout<<0;
    else
    {
        while (!(s.empty()))
        {
            cout<<s.top();
            s.pop();
        }
    }
    return 0;
}
