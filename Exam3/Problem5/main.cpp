#include <iostream>
#include <algorithm>

using namespace std;

class Point
{
public:
    int x,y;
    //bool operator > (Point Another);
    //bool operator < (Point Another);
    //bool operator == (Point Another);
};
/*bool Point::operator > (Point Another)
{
    if (this->x > Another.x) return true;
    else if (this->x == Another.x)
    {
        if (this->y < Another.y) return true;
        else return false;
    }
    else return false;
}
bool Point::operator < (Point Another)
{
    if (this->x < Another.x) return true;
    else if (this->x == Another.x)
    {
        if (this->y > Another.y) return true;
        else return false;
    }
    else return false;
}
bool Point::operator == (Point Another)
{
    return (this->x == Another.x  && this->y == Another.y);
}*/

bool KtraBe (Point A, Point B)
{
    if (A.x < B.x) return true;
    else if (A.x == B.x)
    {
        if (A.y > B.y) return true;
        else return false;
    }
    else return false;
}
bool KtraLon (Point A, Point B)
{
    if (A.x > B.x) return true;
    else if (A.x == B.x)
    {
        if (A.y < B.y) return true;
        else return false;
    }
    else return false;
}
void QuickSort (Point*& Ds,int l, int r)
{
    int mid;
    int i = l;
    int j = r;
    mid = (l+r)/2;
    Point x = Ds[mid];
    while (i<j)
    {
        while (KtraBe(Ds[i],x)) i++;
        while (KtraLon(Ds[j],x)) j--;
        if (i<=j)
        {
            Point Temp = Ds[i];
            Ds[i] = Ds[j];
            Ds[j] = Temp;
            i++;
            j--;
        }
    }
    if (l<j) QuickSort(Ds,l,j);
    if (i<r) QuickSort(Ds,i,r);
}
int main ()
{
    int n;
    cin>>n;
    Point * Ds = new Point[n];
    for (int i=0; i<n; i++)
    {
        cin>>Ds[i].x>>Ds[i].y;
    }
    QuickSort (Ds,0,n-1);
    for (int i=0;i<n;i++)
    {
        cout<<Ds[i].x<<" "<<Ds[i].y<<"\n";
    }
    return 0;
}

