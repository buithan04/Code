#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int *a = new int[n];
    for (int i=0;i<n;i++)
    {
        cin>> a[i];
    }
    int m;
    cin>>m;
    int *b= new int [m];
    for (int i=0;i<m;i++)
    {
        cin>> b[i];
    }
    int j;
    for (int i=0;i<m;i++)
    {
        for (j=0;i<n;j++)
        {
            if (a[j]==b[i])
            {
                cout<<j<<endl;
                break;
            }
        }
        if (j==n) cout<<-1<<endl;
    }
}
