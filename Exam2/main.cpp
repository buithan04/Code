#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <map>
using namespace std;

void getInterger (int &n)
{
    cout<<"Nhap So Luong Phan Tu Cua Mang : "<<endl;
    cin>>n;
}
void getArray (int *&a, int n)
{
    srand (time(NULL));
    for (int i=0;i<n;i++)
        a[i]=-10000 + rand() % 20001;;
}
void outputArray (int *a, int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
void CopyArray (int *a, int n, int *&b)
{
    for (int i=0;i<n;i++)
        b[i]=a[i];
}
void Menu ()
{
    cout<<"---------------MENU---------------"<<endl;
    cout<<"01.Selection Sort"<<endl;
    cout<<"02.Interchange Sort"<<endl;
    cout<<"03.Insertion Sort"<<endl;
    cout<<"04.Binary Insertion Sort"<<endl;
    cout<<"05.Bubble Sort"<<endl;
    cout<<"06.Shaker Sort"<<endl;
    cout<<"07.Counting Sort"<<endl;
    cout<<"08.Quick Sort"<<endl;
    cout<<"09.Merge Sort"<<endl;
    cout<<"10.Heap Sort"<<endl;
    cout<<"11.Shell Sort"<<endl;
    cout<<"12.Radix Sort"<<endl;
    cout<<"13.Counting Sort New"<<endl;
}
void Quicksort (int *&a , int l, int r)
{
    int i=l, j=r;
    int x = a[(l+r)/2];
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
void Merge(int *&a, int l, int mid, int r)
{
  int k = 0;
  int i=l;
  int j=mid + 1;
  int *b = new int [r-l+1];
  while (i<=mid && j<= r)
  {
      if (a[i]<a[j])
      {
          b[k]=a[i];
          i++;
      }
      else
      {
          b[k]=a[j];
          j++;
      }
      k++;
  }
  while (i<=mid )
  {
      b[k] = a[i];
      i++;
      k++;
  }
  while (j<=r )
  {
      b[k] = a[j];
      j++;
      k++;
  }
  for (int i=0;i<k;i++)
  {
      a[l+i]=b[i];
  }
  delete []b;
}
void Mergesort (int *&a ,int l, int r)
{
    int mid =(l+r)/2;
    if (l<r)
    {
        Mergesort (a,l,mid);
        Mergesort (a,mid+1,r);
        Merge (a,l,mid,r);
    }
}
void HeapMax (int *&a , int n , int i )
{
    int Max = i;
    int L=2*i + 1;
    int R=2*i + 2;
    if (L < n && a[L]>a[Max])
                        Max=L;

    if (R < n && a[R]>a[Max])
                        Max=R;
    if (Max!=i)
    {
        swap (a[i],a[Max]);
        HeapMax (a,n,Max);
    }
}
void Heapsort (int *&a ,int n)
{
    for (int i = n/2 -1 ;i>=0;i--)
                    HeapMax (a,n,i);

    for (int i = 0;i<n;i++)
    {
        swap (a[0],a[n-1-i]);
        HeapMax (a,n-1-i,0);
    }
}
void Selectionsort (int *&a , int l, int r)
{
    int heap;
    for (int i=l;i<r;i++)
    {
        heap = i;
        for (int j=i+1;j<=r;j++)

            if (a[i]>a[j])
                        heap = j;
        swap (a[i],a[heap]);
    }
}
void Bubblesort (int *&a, int n)
{
    int dem;
    for (int i=0;i<n-1;i++)
    {
        dem=0;
        for (int j=0;j<n-1-i;j++)
        {
            if (a[j]>a[j+1])
            {
                swap (a[j],a[j+1]);
                dem++;
            }
        }
        if (dem==0) break;
    }
}
void BinaryInsertionSort(int *&a, int n)
{
  int l, r, m, i, x;
  for ( i = 1; i < n; i ++)
  {
      x = a[i];// x la phan tu can them
      l = 0;
      r = i - 1;
      while (l <= r)// tim vi tri de chen x
      {
          m = (l + r) / 2;
          if (x < a[m])
                r = m - 1;
          else
             l = m + 1;
      }
      //dời cho cac phan tu
      for ( int j = i - 1; j >= l; j --)
                a[j + 1] = a[j];
      a[l] = x;// chen x vao
  }
}
void InsertSort (int *&a , int n)
{
    int x;
    int j;
    for (int i=1;i<n;i++)
    {
        x=a[i];
        for (j=i-1;j>=0;j--)
        {
            if (x>=a[j]) break;
            else a[j+1]=a[j];
        }
        a[j+1]=x;
    }
}
void CountingSort (int *&a , int n)
{
    int m=0;
    int b[200001]={0};
    int Max=INT_MIN,Min=INT_MAX;
    for (int i=0;i<n;i++)
    {
        if (Max<a[i]) Max=a[i];
        if (Min>a[i]) Min=a[i];
    }
    int k=0;
    for (int i=Min;i<Max+1;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (a[j]==i)
            {
                b[k]++;
            }
        }
        k++;
    }
    int z=0;
    for (int i=Min;i<=Max;i++)
    {
        if (b[z]!=0)
        {
            for (int j=0;j<b[z];j++)
            {
                a[m]=i;
                m++;
            }
        }
        z++;
    }
}
void ShakerSort (int *&a , int l, int r)
{
    bool k=true;
    while (l<r  && k)
    {
        k=false;
        for (int i = l;i<r;i++)
        {
            if (a[i]>a[i+1])
            {
                swap (a[i],a[i+1]);
                k = true;
            }
        }
        r--;
        for (int i = r;i>l;i--)
        {
            if (a[i]<a[i-1])
            {
                swap (a[i],a[i-1]);
                k=true;
            }
        }
        l++;
    }
}
void ShellSort (int *&a , int n)
{
    int x;
    int k;
    for (int i = n/2 ; i > 0 ; i = i/2)
    {
        for (int j = i ; j<n ; j++ )
        {
            x=a[j];
            for ( k = j-i;k>=0;k = k-i)
            {
                if (a[k]<=x) break;
                else
                    a[k+i]=a[k];
            }
            a[k+i]=x;
        }
    }
}
void InterchangeSort (int *&a , int n)
{
    for (int i = 0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (a[i]>a[j]) swap (a[i],a[j]);
        }
    }
}
void Set_value(int *arr, int n, int value)
{
    for (int i = 0; i < n; i++){
        arr[i] = value;
    }
}
int find_max(int *arr, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++){
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
void Count_Sort(int *arr, int digit, int n)
{
    int *count = new int[19];
    int *output = new int[n];

    Set_value(count, 19, 0);


    for (int i = 0; i < n; i++){
        count[arr[i] % (digit*10)/digit + 9]++;
    }


    for (int i = 1; i < 19; i++){
        count[i] = count[i-1] + count[i];
    }
    for (int i = n-1; i >= 0; i--){
        output[count[arr[i] % (digit*10)/digit + 9] - 1 ] = arr[i];
        count[arr[i] % (digit*10)/digit + 9]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void radix_sort(int *arr, int n)
{
    int max = find_max(arr, n);

    for (int i = 1; i <= max; i= i* 10){
        Count_Sort(arr, i, n);
    }
}
void CountingSortNew (int *&a , int n)
{
    map<int, int> mp;
    int k = 0;
    for (int i=0;i<n;i++)
    {
        mp[a[i]]++;
    }
    for (auto x : mp)
    {
        if (x.second!=0)
        {
            for (int i=0;i<x.second;i++)
            {
                a[k] = x.first ;
                k++;
            }
        }
    }
}
int main()
{
    int n;
    getInterger(n);
    int *a = new int[n];
    int *b = new int[n];
    getArray (a,n);
    Menu();
    while (1)
    {
    CopyArray (a,n,b);
    int choose;
    cout<<"Choose an algorithm : ";
    cin>>choose;
    switch (choose)
    {
        case 1:
            {
                clock_t start = clock();
                Selectionsort (b,0,n-1);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<"s"<<endl;
                cout<<endl;
            } break;
        case 2:
            {
                clock_t start = clock();
                InterchangeSort (b,n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<"s"<<endl;
                cout<<endl;

            } break;
        case 3:
            {
                clock_t start = clock();
                InsertSort (b,n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<"s"<<endl;
                cout<<endl;
                break;
            }
        case 4:
            {
                clock_t start = clock();
                BinaryInsertionSort (b, n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<"s"<<endl;
                cout<<endl;
            } break;
       case 5:
            {
                clock_t start = clock();
                Bubblesort (b,n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<"s"<<endl;
                cout<<endl;
            } break;
       case 6:
            {
                clock_t start = clock();
                ShakerSort (b,0,n-1);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<"s"<<endl;
                cout<<endl;
            } break;
        case 7:
            {
                clock_t start = clock();
                CountingSort (b,n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<"s"<<endl;
                cout<<endl;
            } break;
        case 8:
            {
                clock_t start = clock();
                Quicksort(b,0,n-1);
                clock_t finish = clock();
                cout<<"Time : "<<double(finish - start)/CLOCKS_PER_SEC<<"s"<<endl;
                cout<<endl;
            } break;
        case 9:
            {
                clock_t start = clock();
                Mergesort (b,0,n-1);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<"s"<<endl;
                cout<<endl;
            } break;
        case 10:
            {
                clock_t start = clock();
                Heapsort (b,n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<"s"<<endl;
                cout<<endl;
                break;
            }
        case 11:
            {
                clock_t start = clock();
                ShellSort (b,n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<"s"<<endl;
                cout<<endl;
            } break;

        case 12:
            {
                clock_t start = clock();
                radix_sort (b,n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<"s"<<endl;
                cout<<endl;

            } break;
        case 13:
            {
                clock_t start = clock();
                CountingSortNew (b,n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<"s"<<endl;
                cout<<endl;
            } break;
    }
    cout<<"Do you want continue ? (Y/N) ";
    char c;
    cin>>c;
    if (c=='n' || c=='N') break;
    }

    return 0;
}
