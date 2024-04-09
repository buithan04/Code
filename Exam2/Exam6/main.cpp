/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

void Swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void Quicksort(int*& a, int i, int j)
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
void Quicksort1 (int *&a, int i, int j)
{
    int l=i;
    int r=j;// khoi tao 2 phan tu left va right
    int mid ;
    mid = (l+r)/2;
    int x = a[mid]; //xac dinh gia tri chinh giua
    while (l<=r)
    {
        while (a[l] > x) l++; // chay l cho den khi gap gia tri >= a[l] thi dung
        while (a[r] < x) r--; // chay l cho den khi gap gia tri <= a[r] thi dung
        if (l<=r) // neu l<= right thi hoa =n doi 2 gia tri cho nhau va giam r,tang l
        {
            Swap (a[l], a[r]);
            l++;
            r--;
        }
    }
    //sau khi phan hoach :
    if (i<r) Quicksort1 (a,i,r); // neu mang con thu nhat con nhieu hon 1 phan tu thi tiep tuc phan hoach
    if (j>l) Quicksort1 (a,l,j); // neu mang con thu hai con nhieu hon 1 phan tu thi tiep tuc phan hoach
}
void sort(int*&a, int n)
{
    int* b = new int[n];
    int k = 0;
    for (int i = 0;i < n;i++)
    {
        if (a[i] % 2 == 0)
        {
            b[k] = a[i];
            k++;
        }
    }
    Quicksort(b, 0, k - 1);
    k=0;
    for (int i = 0;i < n;i++)
    {
        if (a[i] % 2 == 0)
        {
            a[i] = b[k];
            k++;
        }
    }
    k=0;
    for (int i = 0;i < n;i++)
    {
        if (a[i] % 2 != 0)
        {
            b[k] = a[i];
            k++;
        }
    }
    Quicksort1(b, 0, k - 1);
    k=0;
    for (int i = 0;i < n;i++)
    {
        if (a[i] % 2 != 0)
        {
            a[i] = b[k];
            k++;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int *a = new int [n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,n);
    cout<<"Sorted Array: ";
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
