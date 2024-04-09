#include <iostream>
#include <math.h>
using namespace std;
long long CapSoCong (int n)
{
    return n*(n+1)/2;
}
long long Tinh (long long n)
{
    long long l = 0;
    long r = n;
    while (l <= r)
    {
        long long mid = (l+r)/2;
        long long x = CapSoCong(mid);
        if (n == x) return mid;
        else if (x < n)
        {
            if ((n-x) < mid + 1) return mid;
            else l = mid + 1;
        }
        else
        {
            if (n >= CapSoCong(mid -1)) return mid -1;
            else r = mid - 1;
        }
    }
}
int main()
{
    long long n ;cin>>n;
    cout<<Tinh(n);
    return 0;
}
