#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    int n; cin>>n;
    vector <vector <int>> v (n,vector <int> (n,0));
    for (int i = 0; i < n ;i++)
    {
        for (int j = 0; j < n ; j++)
        {
            cin>>v[i][j];
        }
    }
    map <int , set <int>> mp;
    for (int i = 0; i < n ;i++)
    {
        for (int j = 0; j < n ; j++)
        {
            if (v[i][j])
            {
                 mp[i].insert(j+1);
            }
        }
    }
    for (int i = 0 ; i < n ; i++)
    {
        if (!mp[i].empty())
        {
            cout<<i+1<<"->";
            for (auto x : mp[i])
            {
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
