#include <iostream>

using namespace std;
void input (int *&a , int &n)
{
    cin>>n;
    a = new int[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}
void output (int *a , int n)
{
    cout<<"Sorted Array: ";
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
void Swap (int &a , int &b, int &dem)
{
    dem++;
    int temp;
    temp = a;
    a=b;
    b=temp;
}
void Quicksort (int *&a, int i, int j, int &dem)
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
            Swap (a[l], a[r],dem);
            l++;
            r--;
        }
    }
    //sau khi phan hoach :
    if (i<r) Quicksort (a,i,r,dem); // neu mang con thu nhat con nhieu hon 1 phan tu thi tiep tuc phan hoach
    if (j>l) Quicksort (a,l,j,dem); // neu mang con thu hai con nhieu hon 1 phan tu thi tiep tuc phan hoach
}

int main()
{
    int n;
    int dem=0;
    int *a=NULL;
    input (a,n);
    Quicksort (a,0,n-1,dem);
    output (a,n);
    cout<<endl;
    cout<<"Number of times to swap 2 numbers: "<<dem;

    return 0;
}
