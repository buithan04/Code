#include <iostream>

using namespace std;
void Swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void Quicksort(int a[], int i, int j)
{
    int l = i;
    int r = j;// khoi tao 2 phan tu left va right
    int mid;
    mid = (l + r) / 2;
    int x = a[mid]; //xac dinh gia tri chinh giua
    while (l <= r)
    {
        while (a[l] < x) l++; // chay l cho den khi gap gia tri >= a[l] thi dung
        while (a[r] > x) r--; // chay l cho den khi gap gia tri <= a[r] thi dung
        if (l <= r) // neu l<= right thi hoa =n doi 2 gia tri cho nhau va giam r,tang l
        {
            Swap(a[l], a[r]);
            l++;
            r--;
        }
    }
    //sau khi phan hoach :
    if (i < r) Quicksort(a, i, r); // neu mang con thu nhat con nhieu hon 1 phan tu thi tiep tuc phan hoach
    if (j > l) Quicksort(a, l, j); // neu mang con thu hai con nhieu hon 1 phan tu thi tiep tuc phan hoach
}
void Sapxep (int a[], int n)
{
    int k=0;
    int l=0;
    int b[n];
    int c[n];
    for (int i=0;i<n;i++)
    {
        if (a[i]%2==0)
        {
            b[k]=a[i];
            k++;
        }
        else
        {
            c[l]=a[i];
            l++;
        }
    }
    Quicksort (b,0,k-1);
    Quicksort (c,0,l-1);
    l=0;
    for (int i=0;i<n;i++)
    {
        if (i<k)
        {
            a[i]=b[i];
        }
        else
        {
            a[i]=c[l];
            l++;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    Sapxep (a,n);
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
