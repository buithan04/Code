#include <iostream>
#define MAX 100
using namespace std;
void inputArray (int *&a, int &n)
{
    cin>>n;
    a = new int [n];
    for (int i=0;i<n;i++)
        cin>>a[i];
}
void outputArray (int *a, int n)
{
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
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
int main()
{
    int n;
    int *a=NULL;
    inputArray (a,n);
    Mergesort (a,0,n-1);
    outputArray (a,n);
    return 0;
}
