

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace std;


int main()
{

    map <string , map<string,int>> adj_list;
    int  e,n; cin >> e >>n;
    string x,y;
    int h;
    int Sum = 0;
    for (int i = 0 ; i < e ; i++)
    {
        cin>>x>>y;
        cin>>h;
        adj_list [x];
        adj_list [x][y] = h;
    }
    bool check = true;
    for (int i = 0 ; i < n ; i++)
    {
        vector<string> a;
        while (1)
        {
            cin>>x;
            if (x == ".") break;
            else a.push_back(x);
        }
        for (int i = 0 ; i < a.size()-1; i++)
        {
            if (!(adj_list[a[i]][a[i+1]]))
            {
                cout<<"FALSE"<<endl;
                check = false;
                break;
            }
            else
            {
                Sum += adj_list[a[i]][a[i+1]];
            }
        }
        if (check) cout<<Sum<<endl;
        else check = true;
        Sum = 0;

    }

    return 0;
}
