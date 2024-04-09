#include <iostream>
#include <cmath>
using namespace std;

void Search (long long k)
{
    long long m = 0;
    long long n = 0;
    long long Min = k * 2;

    int sum =0;
    for (int i = 2; i <= (k*2 - 2)/3 ; i++)
    {
        int l = 1;
        int r = i - 1;
        while (l <= r)
        {
            int mid = (l + r)/2;
            sum = 2*i*mid + mid + i + 1;
            if (sum == 2*k)
            {
                if (Min > abs (i-mid))
                {
                    n = i;
                    m = mid;
                    Min = abs (i - mid);
                }
                break;
            }
            else if (sum > 2*k) r = mid - 1;
            else l = mid + 1;
        }

    }
    if (m == 0 && n == 0)
        cout << "-1 -1" << '\n';
    else
        cout << m << " " << n << '\n';
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long k;
        cin>>k;
        Search(k);
    }
    return 0;
}





















