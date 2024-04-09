#include <iostream>

using namespace std;
void inputArray (int *&a, int &n)
{
    cin>>n;
    a=new int [n];
    for (int i=0;i<n;i++)
        cin>>a[i];
}
void Swap (int &a, int &b)
{
    int temp = a;
    a=b;
    b=temp;
}
void output (int *a, int n)
{
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
void Heapsort (int *&a , int l, int r)
{
    if (l<r)
    {
        for (int i=l+1;i<r-l+1;i++)
        {
            if (a[l]<a[i])
            {
                Swap (a[l],a[i]);
            }
        }
        Swap (a[l],a[r]);
        r--;
        Heapsort (a,l,r);
    }
}

int main()
{
    int n;
    int *a=NULL;
    inputArray (a,n);
    Heapsort (a,0,n-1);
    output (a,n);

    return 0;
}
