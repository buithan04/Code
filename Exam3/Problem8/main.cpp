#include <iostream>
#include <set>
using namespace std;
set<int>::iterator operator + (set<int>::iterator &it,int n)
{
    for (int i = 0;i < n; i++)
    {
        it++;
    }
}
int Vitri(set<int> s, int x)
{
    for (int i = 0; i < s.size(); i ++)
    {
        if (x == *(s.begin()+i))
                    return i+1;
        if (x < *(s.begin()+i))
                    break;
    }
    return 0;
}
int main()
{
    int a,b;
    set <int> s;
    while (1)
    {
        cin>>a;
        if (a==0) break;
        else if (a==1)
        {
            cin>>b;
            s.insert(b);
        }
        else if (a==2)
        {
            cin>>b;
            if (s.count(b) != 0)
            {
                cout<<Vitri(s,b);
            }
            else cout<<0<<endl;
        }
    }
    return 0;
}
