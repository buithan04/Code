#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
bool kt (vector<string> &v , string s)
{
    for (string x : v)
    {
        if (x==s) return false;
    }
    return true;
}
int main()
{
    int n;cin>>n;
    int dem;
    cin.ignore();
    string *ds = new string [n];
    vector<string> v;
    v.push_back ("");
    for (int i=0;i<n;i++)
    {
        getline (cin,ds[i]);
        if (kt(v,ds[i]))
        {
            dem++;
            v.push_back(ds[i]);
        }
    }
    cout<<dem;
    return 0;
}
