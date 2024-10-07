#include <stdio.h>
#define MAX 100
//a. ---------------------------------------------------------
void nhapSL(int &n)
{
	do{
		printf ("Nhap so phan tu 0<n<%d: ", 100);
		scanf("%d", &n);
	}while (n<=0 || n>100);
}
void nhapDS(int a[], int n)
{
	for (int i = 0; i < n; i ++)
	{
		printf ("a[%d] = ", i);
		scanf ("%d", &a[i]);
	}
}
//b. ---------------------------------------------------------
void xuatDS(int a[], int n)
{
	printf ("\nDay so: ");
	for (int i = 0; i < n; i ++)
		printf ("%5d", a[i]);
	printf("\n");
}
//c. ---------------------------------------------------------
void nhapX(int &x)
{
	printf("Nhap gia tri can tim: x= "); scanf("%d", &x);
}
//d.
int timTuanTu(int a[], int n, int x)
{
//Duyet qua tung phan tu trong danh sách
	for(int i =0; i<n; i++)
//neu x = a[i] thì tra ve vi trí tìm thay là i
	if (a[i] == x) return i;
//Khi duyet het dãy, không tìm duoc thì tra ve -1
	return -1;
}


int main()
{
//khai báo các bien luu du liuu can su dung
	int a[MAX], n, x, vt;
//a.
	nhapSL(n); nhapDS(a,n);
//b.
	xuatDS(a,n);
//c.
	nhapX(x);
	vt=timTuanTu(a,n,x);
	if (vt==-1) 
		printf("Khong tim thay");
	else 
		printf("\nTim thay %d tai vi tri %d",x, vt);
}

