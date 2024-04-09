#include <iostream>

using namespace std;
void input (int *&a, int &n)
{
    cin>>n;
    a = new int [n];
    for (int i=0;i<n;i++)
        cin>>a[i];
}
void Merge (int *a,int *b,int *&c,int l, int r, int x, int z, int &k)
{
    c= new int [r+z-l-x+2];
    k=0;
    int i=l;
    int j=x;
    while ( i<=r && j<=z)
    {
        if (a[i]< b[j])
        {
            c[k]=a[i];
            i++;
            k++;
        }
        else
        {
            c[k]=b[j];
            j++;
            k++;

        }
    }
    while (i<=r)
    {
        c[k]=a[i];
        i++;
        k++;
    }
    while (j<=z)
    {
        c[k]=b[j];
        j++;
        k++;
    }
}
void output (int *c, int k)
{
    for (int i=0;i<k;i++)
    {
        cout<<c[i]<<" ";
    }
}
int main()
{
    int n,m;
    int k;
    int *a=NULL;
    int *b=NULL;
    int *c=NULL;
    input (a,n);
    input (b,m);
    Merge (a,b,c,0,n-1,0,m-1,k);
    output (c,k);

}
