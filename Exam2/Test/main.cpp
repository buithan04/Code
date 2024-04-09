#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
void Quicksort (int *&a , int l, int r)
{
    int i=l, j=r;
    char x = a[(l+r)/2];
    while (i<=j)
    {
        while (a[i]<x) i++;
        while (a[j]>x) j--;
        if (i<=j)
        {
            swap (a[i],a[j]);
            i++;
            j--;
        }
    }
    if (l<j) Quicksort (a,l,j);
    if (i<r) Quicksort (a,i,r);
}
int main()
{
    int n;cin>>n;
    int *a = new int [n];
    for (int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    int k = n;
    for (int i = 0;i<n;i++)
    {
        if (a[i]>=k)
        {
            cout<<n-i;
            break;
        }
        else k--;
    }

}






