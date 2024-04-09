#include <iostream>
#include <cstring>
#include <string>
#define M 10		// M là số nút có trên bảng băm, đủ để chứa các nút nhập vào bảng băm
#define NULLKEY -1
using namespace std;
struct node
{
    int key;
    int value;
};
struct Hash
{
    node * HashTable ;
    int m;
    int N;
};
void initHash (Hash &H)
{
    H.N = 0;
    H.m = 10;
    H.HashTable = new node [H.m];
    for (int i = 0 ; i < H.m ; i++)
    {
        H.HashTable[i].key = -1;
    }
}
bool isFULL (Hash H)
{
    return H.m == H.N;
}
void insertHash (Hash &H , int x)
{
    if (isFULL(H))
    {
        cout<<"\nBang bam bi day, khong them duoc"<<endl;
        return;
    }
    int index = x % H.m;
    while (H.HashTable[index].key != NULLKEY)
    {
        index++;
        if (index == H.m) index = 0;
    }
    H.HashTable[index].key = x;
    H.N++;
    cout<<endl;
}
void traverseAllHash(Hash H)
{
    for (int i = 0 ; i < H.m ; i++)
    {
        cout<<H.HashTable[i].key<<" ";
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
        cout<<"\nInsert "<<x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"\nCreated Hash:"<<endl;
    traverseAllHash(H);

    return 0;
}
