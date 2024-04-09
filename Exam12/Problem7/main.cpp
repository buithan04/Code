#include <iostream>
#include <cstring>
#include <string>
#define M 10		// M là số nút có trên bảng băm, đủ để chứa các nút nhập vào bảng băm
#define NULLKEY -1
using namespace std;
struct Hash
{
    int * HashTable ;
    int m;
    int N;
};
void initHash (Hash &H)
{
    H.N = 0;
    H.m = M;
    H.HashTable = new int [H.m];
    for (int i = 0 ; i < H.m ; i++)
    {
        H.HashTable[i] = NULLKEY;
    }
}
bool isFULL (Hash H)
{
    return H.m == H.N;
}
void insertHash (Hash &H , int x)
{
    int k = 1;
    if (isFULL(H))
    {
        cout<<"\nBang bam bi day, khong them duoc"<<endl;
        return;
    }
    int index = x % H.m;
    int i = index;
    while (H.HashTable[index] != NULLKEY && k != H.m)
    {
        index = (i + k*k) % H.m;
        k++;
    }
    if (k == H.m)
    {
        index = i;
        while (H.HashTable[index] != NULLKEY)
        {
            index++;
            if (index >= H.m) index = 0;
        }
    }
    H.HashTable[index] = x;
    H.N++;
    cout<<endl;
}
void traverseAllHash(Hash H)
{
    for (int i = 0 ; i < H.m ; i++)
    {
        cout<<i;
        if (H.HashTable[i] != NULLKEY)
        {
            cout<<" --> "<<H.HashTable[i];
        }
        cout<<endl;
    }
}

int main()
{
    Hash H;
    initHash(H);

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        cout<<"Insert "<<x<<endl;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"\nCreated Hash:"<<endl;
    traverseAllHash(H);

    return 0;
}
