#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <map>
#include "Quicksort.h"
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
    cout<<"1.Quicksort"<<endl;
    cout<<"2.Mergesort"<<endl;
    cout<<"3.Heapsort"<<endl;
    cout<<"4.Selectionsort"<<endl;
    cout<<"5.BinaryInsertsort"<<endl;
    cout<<"6.Bubblesort"<<endl;
    cout<<"7.Insertsort"<<endl;
    cout<<"8.Countingsort"<<endl;
    cout<<"9.Shakersort"<<endl;
    cout<<"10.Shellsort"<<endl;
    cout<<"11.Interchangesort"<<endl;
    cout<<"12.Radixsort"<<endl;
    cout<<"13.CountingsortNew"<<endl;
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
                Quicksort(b,0,n-1);
                clock_t finish = clock();
                cout<<"Time : "<<double(finish - start)/CLOCKS_PER_SEC<<endl;
                cout<<endl;
                break;
            }
        case 2:
            {
                clock_t start = clock();
                Mergesort (b,0,n-1);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<endl;
                cout<<endl;
                break;
            }
        case 3:
            {
                clock_t start = clock();
                Heapsort (b,n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<endl;
                cout<<endl;
                break;
            }
        case 4:
            {
                clock_t start = clock();
                Selectionsort (b,0,n-1);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<endl;
                cout<<endl;
                break;
            }
        case 5:
            {
                clock_t start = clock();
                BinaryInsertsort (b,0,n-1);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<endl;
                cout<<endl;
                break;
            }
        case 6:
            {
                clock_t start = clock();
                Bubblesort (b,n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<endl;
                cout<<endl;
                break;
            }
        case 7:
            {
                clock_t start = clock();
                InsertSort (b,n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<endl;
                cout<<endl;
                break;
            }
        case 8:
            {
                clock_t start = clock();
                CountingSort (b,n);
                outputArray (b,n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<endl;
                cout<<endl;
                break;
            }
        case 9:
            {
                clock_t start = clock();
                ShakerSort (b,0,n-1);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<endl;
                cout<<endl;

            }
        case 10:
            {
                clock_t start = clock();
                ShellSort (b,n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<endl;
                cout<<endl;

            }
        case 11:
            {
                clock_t start = clock();
                InterchangeSort (b,n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<endl;
                cout<<endl;

            }
        case 12:
            {
                clock_t start = clock();
                radix_sort (b,n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<endl;
                cout<<endl;

            }
        case 13:
            {
                clock_t start = clock();
                CountingSortNew (b,n);
                clock_t finish = clock();
                cout<<"Time : "<<double (finish - start)/CLOCKS_PER_SEC<<endl;
                cout<<endl;

            }
    }
    cout<<"Do you want continue ? (Y/N) "<<endl;
    char c;
    cin>>c;
    if (c=='n' || c=='N') break;
    }

    return 0;
}
