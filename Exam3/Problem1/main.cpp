#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int , int> mp;
    int n,q;
    int x;
    int j=0;
    cin>>n>>q;
    int *a =  new int [n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    while (j<q)
    {
        cin>>x;
        if (mp[x]!=0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        j++;
    }

    return 0;
}
