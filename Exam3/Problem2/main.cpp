#include <iostream>

using namespace std;
void quick(int *&a,int l,int r)
{
    int i=l,j=r,x;
    x=a[(l+r)/2];
    while (i<=j)
        {
            while (a[i]<x) i++;
            while (a[j]>x) j--;
                if (i<=j)
                    {
                        swap(a[i],a[j]);
                        i++;j--;
                    }
        }
   if (l<j) quick(a,l,j);
   if (i<r)  quick(a,i,r);
}
int main()
{
    int n;cin>>n;
    int *a = new int [n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quick(a,0,n-1);
    int i;
    for (i=0;i<n;i++)
    {
        if (a[i]!= i)
        {
            cout<<i;
            break;
        }
    }
    if (i==n) cout<<i;
    return 0;
}
