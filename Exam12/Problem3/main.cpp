#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    char s[1000];
    for (int i = 0 ; i < n ; i++)
    {
        cin>>s[i];
    }
    int * b =  new int [26];
    for (int i = 0 ; i < 26 ; i++)
    {
        b[i] = 0;
    }
    for (int i = 0 ; i < n ; i++)
    {
        if (s[i] <= 'Z' && s[i] >= 'A')
        {
            b[int (s[i]) - 65]++;

        }
        else if (s[i] <= 'z' && s[i] >= 'a')
        {
            b[int (s[i]) - 97]++;
        }
    }
    int dem = 0;
    for (int i = 0; i < 26 ; i++)
    {
        if (b[i] == 0) dem++;
    }
    cout<<dem<<endl;
    return 0;
}
