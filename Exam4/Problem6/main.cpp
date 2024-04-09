#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void XoaMax (vector<int> &v , int& Max)
{
    for (vector<int>::iterator it = v.begin();it!=v.end();it++)
    {
        if (*it == Max)
        {
            v.erase(it);
            it--;
        }
    }
    Max = *max_element(v.begin(), v.end());
}
void Selection (vector<int> &v)
{
    vector<int>::iterator it1;
    for (vector<int>::iterator it = v.begin();it!=v.end();it++)
    {
        it1 = it;
        for (vector<int>::iterator it2 = it + 1 ;it2!=v.end();it2++)
        {
            if (*it1 < *it2) it1 = it2;
        }
        swap (*it,*it1);
    }
}
int main()
{
    vector<int> v;
    int x;
    int Max = -3;
    while (1)
    {
        cin>>x;
        if (x == -2)
        {
            Selection (v);
            cout<<v.size()<<endl;
            for (auto x : v)
            {
                cout<<x<<endl;
            }
            break ;
        }
        else if (x==-1)
        {
            XoaMax (v,Max);
        }
        else if ( x > 0 && v.size() < 100000)
        {
            v.push_back(x);
            if (x > Max) Max = x;
        }
    }
    return 0;
}
