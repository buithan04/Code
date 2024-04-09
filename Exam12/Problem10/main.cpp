#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map <string , string> mp;
    int N,Q;
    cin>>N>>Q;
    string x,y;
    for (int  i = 0 ; i < N ; i++)
    {
        cin>>x>>y;
        mp[x] = y;
    }
    for (int i = 0 ; i < Q ; i++)
    {
        cin>>x;
        if (mp.find(x) == mp.end()) cout<<"Chua Dang Ky!"<<endl;
        else cout<<mp[x]<<endl;
    }
    return 0;
}
