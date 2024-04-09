#include<iostream>

using namespace std;
struct point
{
	int x, y;
};
void nhap(int *&arr, int& n)
{
    cin >> n;
    arr = new int [n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
int max(int *&h, int n)
{
	int max = h[0];
	for (int i = 1; i < n; i++)
	{
		if (max < h[i])
		{
			max = h[i];
		}
	}
	return max;
}
int min(int *&h, int n)
{
	int min = h[0];
	for (int i = 1; i < n; i++)
	{
		if (min > h[i])
		{
			min = h[i];
		}
	}
	return min;
}
int kiemtra(int *&h1, int n,int lon)
{
	for (int i = 0; i < n; i++)
	{
		if (h1[i] < lon)
		{
			return 0;
		}
	}
	return 1;
}
void tinh(int *&h1, int *&h2, int n, int m)
{
	int lon = h1[0] + max(h2, m);
	int nho = min(h1, n) + min(h2, m);
	int *c= new int[n];
	point *k= new point[n];//point k[MAX];
	while (nho <= lon)
	{
		int count = 0;
		int s = 0;
			if (h1[s] < lon)
			{
				for (int j = 0; j < m; j++)
				{
					if (h1[s] + h2[j] == lon)
					{

						c[s] = h1[s] + h2[j];
						k[count].x = s + 1;
						k[count].y = j + 1;
						count++;
						s++;
					}
					else {
						if (h1[s] >= lon)
						{
							c[s] = h1[s];
							s++;
							j--;
						}
					}
				}
				if (kiemtra(c, n, lon) == 1)
				{
					cout << lon << " " << count << endl;
					for (int i = 0; i < count; i++)
					{
						cout << k[i].x << " " << k[i].y << endl;
					}
					return;
				}
			}
		lon--;
	}
}
int main()
{
	int *h1 = NULL;
	int *h2 = NULL;
	int n, m;
	nhap(h1, n);
	nhap(h2, m);
	tinh(h1, h2, n, m);
	return 0;

}
