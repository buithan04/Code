#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;
struct node
{
    int key;
    node * next;
};
node * GetNode (int x)
{
    node * p = new node;
    p->key = x;
    p->next = NULL;
    return p;
}
struct Hash
{
    node * bucket [MAX];
    int m;
};
void initHash (Hash &H)
{
    for (int i = 0 ; i < H.m ; i++)
    {
        H.bucket[i] = NULL;
    }
}
void insertHash (Hash &H , int x)
{
    node * k = NULL;
    node * p = GetNode (x);
    int index = x % H.m;
    if (H.bucket [index] == NULL)
    {
        H.bucket[index] = p;
    }
    else
    {
        node * curr = H.bucket[index];
        while (curr != NULL)
        {
            if (p->key > curr->key)
            {
                k = curr;
                curr = curr->next;
            }
            else
            {
                if (k == NULL)
                {
                    p->next = H.bucket[index];
                    H.bucket[index] = p;
                    return;
                }
                else
                {
                    k->next = p;
                    p->next = curr;
                    return;
                }
            }
        }
        k->next = p;
    }
}
void traverseAllHash(Hash H)
{
    for (int i = 0 ; i < H.m ; i++)
    {
        cout<<"Bucket "<<i<<": ";
        node * curr = H.bucket[i];
        while (curr != NULL)
        {
            cout<<curr->key<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
}
int main()
{
    Hash H;
    cin>>H.m; // m la so dia chi co trong bang bam
    initHash(H); //khoi tao cac bucket

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"Created Hash:"<<endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam

    return 0;
}
