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

void SelectionSort(nhanvien a[], int n)
{
	for (int i=0; i<n-1; i++) {
    	int min = i;
    	for (int j=i+1; j<n; j++) 
        	if (a[min].luong > a[j].luong) 
            	min = j;
        swap(a[i],a[min]);
    }
}
//d. ---------------------------------------------------------
void SelectionSortdown(nhanvien a[], int n)
{
	for (int i=0; i<n-1; i++) {
    	int max = i;
    	for (int j=i+1; j<n; j++) 
        	if (strcmp(a[max].hoten,a[j].hoten) < 0)
            	max = j;
        swap(a[i],a[max]);
    }
}
//e. ---------------------------------------------------------
void InsertionSort(nhanvien a[], int n)
{
	int pos; 
	for(int i=1; i<n; i++)
	{
   		pos=i-1;
   		nhanvien x = a[i];
   		while(pos>=0 && a[pos].luong<x.luong)
   		{
   			a[pos+1] = a[pos];
   			pos--;
		}
		a[pos+1] = x;
	}
}
//f. ---------------------------------------------------------
void InsertionSortdown(nhanvien a[], int n)
{
	int pos;
	for(int i=1; i<n; i++)
	{
   		pos=i-1;
   		nhanvien x = a[i];
   		while(pos>=0 && strcmp(a[pos].hoten,x.hoten)>0)
   		{
   			a[pos+1] = a[pos];
   			pos--;
		}
		a[pos+1] = x;
	}
}
//g. ---------------------------------------------------------
void QuickSort(nhanvien a[], int left, int right)
{
	int i, j;
	nhanvien x = a[(left+right)/2]; // chon phan tu giua làm moc
	i = left; j = right;
	do {
		//lap den khi a[i].luong >= x.luong
		while (a[i].luong < x.luong) i++;
		// lap dan khi a[j] <= x
		while (a[j].luong > x.luong) j--;
		if (i <= j) {
	 		swap(a[i], a[j]); //hoán vi/doi cho a[i] và a[j]
	 		i++; // qua phan tu ke tiep
	 		j--; // qua phan tu dang truoc
		}
	} while (i<j);
	if (left < j) /* phân doan bên trái */
		QuickSort(a, left, j);
	if (right > i) /* phân doan bên phai */
		QuickSort(a, i, right);
}
//h. ---------------------------------------------------------
void QuickSortdown(nhanvien a[], int left, int right)
{
	int i, j;
	nhanvien x = a[(left+right)/2]; // chon phan tu giua làm moc
	i = left; j = right;
	do {
		//lap den khi a[i].luong >= x.luong
		while (strcmp(a[i].hoten, x.hoten)<0) i++;
		// lap dan khi a[j] <= x
		while (strcmp(a[i].hoten, x.hoten)>0) j--;
		if (i <= j) {
	
	 		swap(a[i], a[j]); //hoán vi/doi cho a[i] và a[j]
	 		i++; // qua phan tu ke tiep
	 		j--; // qua phan tu dang truoc
		}
	} while (i<j);
	if (left < j) /* phân doan bên trái */
		QuickSort(a, left, j);
	if (right > i) /* phân doan bên phai */
		QuickSort(a, i, right);
}
void menu(int &chon){
printf("\n\n\n0: Thoat chuong trinh");
printf("\n1: Nhap thong tin nhan vien");
printf("\n2: Xuat thong tin nhan vien");
printf("\n3: Sap xep thong tin nhan vien tang dan theo luong bang thuat toan Selection Sort");
printf("\n4: Sap xep thong tin nhan vien giam dan theo ho ten bang thuat toan Selection Sort");
printf("\n5: Sap xep thong tin nhan vien giam dan theo luong bang thuat toan Insertion Sort");
printf("\n6: Sap xep thong tin nhan vien tang dan theo ho ten bang thuat toan Insertion Sort");
printf("\n7: Sap xep thong tin nhan vien tang dan theo luong bang thuat toan Quick sort");
printf("\n8: Sap xep thong tin nhan vien giam dan theo ho ten bang thuat toan Quick sort");
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
			case 3: SelectionSort(a,n); 	
			printf("\nThong tin nhan vien sau khi sap xep tang dan theo luong bang thuat toan Selection Sort la:");
			xuatDS(a,n);break;
			case 4: SelectionSortdown(a,n); 	
			printf("\nThong tin nhan vien sau khi sap xep giam dan theo ho ten bang thuat toan Selection Sort la:");
			xuatDS(a,n);break;
			case 5: InsertionSort(a,n); 	
			printf("\nThong tin nhan vien sau khi sap xep giam dan theo luong bang thuat toan Insertion Sort la:");
			xuatDS(a,n);break;
			case 6: InsertionSortdown(a,n); 	
			printf("\nThong tin nhan vien sau khi sap xep tang dan theo ho ten bang thuat toan Insertion Sort la:");
			xuatDS(a,n);break;
			case 7: QuickSort(a,0,n-1); 	
			printf("\nThong tin nhan vien sau khi sap xep tang dan theo luong bang thuat toan Quick sort la:");
			xuatDS(a,n);break;
			case 8: QuickSortdown(a,0,n-1); 	
			printf("\nThong tin nhan vien sau khi sap xep giam dan theo ho ten bang thuat toan Quick sort la:");
			xuatDS(a,n);break;
			default: printf("Chon sai, chuong trinh ket thuc"); chon=0;
		}
	}while (chon!=0);
	return 0;
}
