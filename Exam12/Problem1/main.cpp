#include <iostream>

using namespace std;
void inputArray (int a[] , int &n)
{
    cin>>n;
    for (int i = 0 ; i < n ; i++)
    {
        cin>>a[i];
    }
}
void printArray (int a[] , int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void removeDups (int a[] , int n)
{
    int * b = new int [10000];
    for (int i = 0 ; i < n ; i++)
    {
        b[a[i]] = 0;
        if (b[a[i]] == 0) b[a[i]]++;
    }
    for (int i = 0 ; i < 1000 ; i++)
    {
        if (b[i] == 1) cout<<i<<" ";
    }
}
int main()
{
    int a[100],n;
    inputArray(a,n);

    // In mang ban dau
    printArray(a, n);

    /* Goi ham thuc hien xuat mang nhung chi xuat nhung gia tri xuat hien lan dau tien,
    *  khong xuat nhung gia tri bi lap lai/bi trung
    */


    cout << "After removing the duplicate elements:" << endl;

    removeDups(a, n);

   return 0;
}
