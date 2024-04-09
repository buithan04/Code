#include <iostream>
using namespace std;

void my_sort (int *& A, int n)
{
    int i = 1,j;
    int x,z;
  while (i != n)
  {
      j = 0;
      while (j != n-i)
      {
           x = A[j];
           z = A[j+1];
           A[j] = min (x,z);
           A[j+1] = max (x,z);
           j++;
      }
      i++;
  }

}


int main(){
    int n;
    cin >> n;

    int *A = new int[n];
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    my_sort (A, n);

    for(int i = 0; i < n; i++){
        cout << A[i] << " " ;
    }
}



