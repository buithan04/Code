#include <iostream>

using namespace std;
void inputMatrix (int a[][50] , int &n , int &m)
{
    cin>>n>>m;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m; j++)
        {
            cin>>a[i][j];
        }
    }
}
void outputMatrix (int a[][50] , int n, int m)
{
     for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void uniqueElements(int a[][50], int n, int m)
{
    int dem = 0;
    int Max = 0;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m; j++)
        {
            if (Max < a[i][j]) Max = a[i][j];
        }
    }
    int * b = new int [Max + 1];
    for (int i = 0 ; i <= Max ; i++)
    {
        b[i] = 0;
    }
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m; j++)
        {
            b[a[i][j]] ++;
        }
    }
    for (int i = 0 ; i <= Max ; i++)
    {
        if (dem == 0 && b[i] == 1)
        {
            dem++;
            cout<<"Unique elements in the matrix:\n";
            cout<<i<<" ";
        }
        else if (b[i] == 1)
        {
            cout<<i<<" ";
            dem++;
        }
    }
    if (dem == 0) cout << "No unique element in the matrix";
}
int main()
{
    int m,n,a[50][50];
    inputMatrix(a,n,m);
    cout<<"Matrix:\n";
    outputMatrix(a,n,m);
    uniqueElements(a,n,m);
    return 0;
}
