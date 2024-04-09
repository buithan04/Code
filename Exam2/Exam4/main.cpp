#include <iostream>

using namespace std;
void inputArray (int *&a , int n)
{
    for (int i=0;i<n;i++)
        cin>>a[i];
}
void outputArray (int *a, int n)
{
    for (int i=0; i<n;i++)
    {
        cout<<a[i]<<" ";
    }
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
  delete[]b;
}
void MergeSort (int *&a ,int l, int r)
{
    int mid =(l+r)/2;
    if (l<r)
    {
        MergeSort (a,l,mid);
        MergeSort (a,mid+1,r);
        Merge (a,l,mid,r);
    }
}
int binarySearch(int *a,int n,int l,int r,int x)
{
  while (l<=r)
  {
      int mid=(l+r)/2;
      if (x==a[mid]) return mid;
      else if (x<a[mid]) r=mid-1;
      else l=mid+1;
  }
    return -1;
}

int main()
{
    int n; cin>>n;
    int *a = new int[n];
    inputArray(a,n);
    MergeSort(a,0,n-1);
    cout<<"Sorted Array: ";
    outputArray(a,n);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = binarySearch(a,n,0,n-1,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}

















int binarySearch(int a[],int n,int l,int r,int x)
{
  while (l<=r)
  {
      int mid=(l+r)/2;
      if (x==a[mid]) return mid;
      else if (x<a[mid]) r=mid-1;
      else l=mid+1;
  }
    return -1;
}
