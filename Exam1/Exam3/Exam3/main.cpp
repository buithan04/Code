#include<iostream>
using namespace std;

void inputArray(int*& a, int& n)
{
	cin >> n;
	a = new int[n];
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
}


//ham search se cho gia tri dau tien so sanh voi gia tri chinh giua cua mang
//neu k nho hon gia tri chinh giua (mid) thi de quy search(a,l,mid)
//neu k lon hon gia tri chinh giua (mid) thi dde quy search(a,mid+1,r)
//dieu kien ket thuc search la a[k]==a[mid]
//ket thuc va quay lai thuc hien searchmain den khi nao m(so luong can tim) == 0


//vi de quy nen diem dau va diem cuoi khong co dinh
//dat l la diem dau
//r la diem cuoi
//voi a la mang hien hanh
void search(int* a, int l, int r, int& k)
{
	int mid = (l + r) / 2;

	while (l < r)
	{
		//tim den khi nao a[mid]==k
		//lien thoat khoi while
		if (a[mid] == k)
		{
			cout << mid << endl;
			break;
		}
		//luc nay k thuoc vao khoan tu mid+1 -> r
		if (a[mid] < k)
		{
			search(a, mid + 1, r, k);
		}
		//luc nay k thuoc vao doan tu l -> mid
		if (a[mid] > k)
		{
			search(a, l, mid, k); //0 3 8
		}
		break;
	}
	//neu nhu khong co gia tri k trong mang
	// tuc la khi l=r
	if (l==r)
    {
        if (a[l]==k) cout<<l<<endl;
        else cout<<-1<<endl;
    }
}


//ham search_main chiu trach nhiem quan li m va k
//viec chia mang va de quy phai hoan thanh xong roi moi tiep tuc xet tiep m va k
//vi the phai su dung ham search lam de quy va tim kiem
void search_main(int* a, int n,int& k,int& m)
{
	cin >> m;
	while (m > 0)
	{
		cin >> k;
		search(a, 0, n-1,k);
		m--;
	}

}

int main()
{
	int* a;
	// n la so phan tu mang
	// m la so luong can tim trong mang
	// k la so can tim trong mang
	int n,k,m;
	a = NULL;
	inputArray(a, n);
	search_main(a, n,k,m);
	return 0;
}
