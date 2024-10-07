#include <stdio.h>
#include <string.h>
#define MAX 100
#include <algorithm>
using namespace std;
//dinh nghia kieu du lieu dau sách
typedef struct Thongtinnhanvien
{
	char ms [10]; 
	char hoten [30]; 
	long luong;
}nhanvien;
//a. ---------------------------------------------------------
void nhapSL(int &n)
{
	do{
		printf("So luong thong tin nhan vien muon nhap: ");
		scanf("%d",&n);
			if(n<=0){
				printf("Hay nhap lai so luong nhan vien: ");
				scanf("%d",&n);
			}
			if(n>MAX){
			printf("Hay nhap lai so luong nhan vien, so luong nhan vien khong the lon hon 100: ");
			scanf("%d",&n);		
			}
	}while (n<=0 || n>MAX);
}
void nhap1SV(nhanvien &x)
{
	printf("Nhap ma so nhan vien: "); 
	scanf("%s", &x.ms);
	printf("Nhap ho ten nhan vien: "); 
	fflush(stdin); gets(x.hoten);
	printf("Nhap luong nhan vien: "); 
	scanf("%d", &x.luong);
}
void nhapDS(nhanvien a[], int n)
{
	for (int i = 0; i < n; i ++)
	{
		printf ("Nhap thong tin nhan vien thu %d:\n", i+1);
		nhap1SV(a[i]);
	}
}
//b. ---------------------------------------------------------
void xuat1SV(nhanvien x)
{
	printf("\nMa so nhan vien: %s\nHo ten nhan vien: %s\nLuong nhan vien: %d", x.ms, x.hoten,x.luong);
}
void xuatDS(nhanvien x[], int n)
{
	printf ("\nDanh sach cac nhan vien:");
	for (int i = 0; i < n; i ++)
	{
		printf("\nThong tin nhan vien thu %d",i+1);
		xuat1SV(x[i]);
	}
}
//c. ---------------------------------------------------------

void InterchangeSort(nhanvien a[], int n)
{
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
		 	if(a[j].luong<a[i].luong)
				swap(a[i], a[j]);
}
//d. ---------------------------------------------------------
void InterchangeSortdown(nhanvien a[], int n)
{
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
		 	if(strcmp(a[j].hoten,a[i].hoten)<0)
				swap(a[i], a[j]);
}
//e. ---------------------------------------------------------
void BubbleSort(nhanvien a[], int n){	
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
		   if(a[j].luong > a[j-1].luong)
		       swap(a[j], a[j-1]);
}
//f. ---------------------------------------------------------
void BubbleSortdown(nhanvien a[], int n){	
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
		   if(strcmp(a[j].hoten,a[j-1].hoten)<0)
		       swap(a[j], a[j-1]);
}
void menu(int &chon){
printf("\n\n\n0: Thoat chuong trinh");
printf("\n1: Nhap thong tin nhan vien");
printf("\n2: Xuat thong tin nhan vien");
printf("\n3: Sap xep thong tin nhan vien tang dan theo luong bang thuat toan Interchange sort");
printf("\n4: Sap xep thong tin nhan vien giam dan theo ho ten bang thuat toan Interchange sort");
printf("\n5: Sap xep thong tin nhan vien giam dan theo luong bang thuat toan Bubble sort");
printf("\n6: Sap xep thong tin nhan vien tang dan theo ho ten bang thuat toan Bubble sort");
printf("\nBan hay chon: "); scanf("%d", &chon);
}
int main()
{
//khai báo các bien luu du liuu can su dung
	nhanvien a[MAX];
	int n, chon;
	do{
//xu?t menu cho ngu?i dùng ch?n
		menu(chon);

		switch(chon){
			case 1: nhapSL(n), nhapDS(a,n); break;
			case 2: xuatDS(a,n); break;
			case 3: InterchangeSort(a,n); 	
			printf("\nThong tin nhan vien sau khi sap xep tang dan theo luong bang thuat toan Interchange sort la:");
			xuatDS(a,n);break;
			case 4: InterchangeSortdown(a,n); 	
			printf("\nThong tin nhan vien sau khi sap xep giam dan theo ho ten bang thuat toan Interchange sort la:");
			xuatDS(a,n);break;
			case 5: BubbleSort(a,n); 	
			printf("\nThong tin nhan vien sau khi sap xep giam dan theo luong bang thuat toan Bubble sort la:");
			xuatDS(a,n);break;
			case 6: BubbleSortdown(a,n); 	
			printf("\nThong tin nhan vien sau khi sap xep tang dan theo ho ten bang thuat toan Bubble sort la:");
			xuatDS(a,n);break;
			default: printf("Chon sai, chuong trinh ket thuc"); chon=0;
		}
	}while (chon!=0);
	return 0;
}
