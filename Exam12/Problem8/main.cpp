#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    map <int , set <int>> mp;
    int n;
    cin>>n;
    int x;
    for (int i = 0 ; i < n ; i++)
    {
        cin>>x;
        mp[x%10].insert(x);
    }
    for (int i = 0 ; i <= n ; i++)
    {
        if (mp[i%10].count(i) == 0)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
