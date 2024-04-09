#include<iostream>
using namespace std;
void nhapmang(int a[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
}

void xuatmang(int a[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << a[i]<<" ";
	}
}

void hoandoi(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void quicksort(int a[], int l, int r)
{
	int i = l, j = r;
	int x;
	x = a[(l + r) / 2];
	while (i <= j)              // khi j vuot qua i hoac i vuot qua j thoat khoi vong lap
	{                          // thuc kiem tra gia tri cua i
		while (a[i] < x) i++; // neu gia tri a[i] nho hon x thi tang len de xet tiep cac gia tri tiep theo, dung lai khi a[i] = x hoac a[i] < x de thuc hien while phia duoi
		while (a[j] > x) j--;   // neu gia tri a[j] lon hon x thi hoan doi vi tri va giam dan
		if (i <= j)
		{
			hoandoi(a[i], a[j]);
			i++;
			j--;
		}
	}
	// thoat khoi vong lap while tai thoi diem i > j
	// sap xep tiep tu i - > r
	// sap xep tiep tu l - > l
	// sap xep den khi mang chia nho chi con 1 phan tu
	if (l < j)
	{
		quicksort(a, l, j);
	}
	if (r > i)
	{
		quicksort(a, i, r);
	}

}

int main()
{
	int a[100], n;
	cin >> n;
	nhapmang(a, n);
	quicksort(a, 0, n-1);
	xuatmang(a, n);
	return 0;
}
