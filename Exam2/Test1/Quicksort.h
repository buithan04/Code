#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED
#include <iostream>
using namespace std;
void Quicksort (int *&a , int l, int r)
{
    int i=l, j=r;
    int x = a[(l+r)/2];
    while (i<j)
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

#endif // QUICKSORT_H_INCLUDED
