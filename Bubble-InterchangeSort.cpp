#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void nhapSL(int &n)
{
	do{
		printf ("Nhap so phan tu 0<n<%d: ", 100);
		scanf("%d", &n);
	}while (n<=0 || n>100);
}
void sinhDS(int a[], int n)
{
	srand(time(NULL)) ;
	for (int i = 0; i < n; i ++)
	{
	a[i]=rand()%100 ;
	}
}
void xuatDS(int a[], int n)
{
	printf ("\nDay so: ");
	for (int i = 0; i < n; i ++)
		printf ("%5d", a[i]);
	printf("\n");
}
void nhapX(int &x)
{
	scanf("%d", &x);
}
void swap(int &a, int &b)
{
	int tam = a;
	a = b;
	b = tam;
}
void InterchangeSort(int a[], int n)
{
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
		 	if(a[j]<a[i])
				swap(a[i], a[j]);
}
void InterchangeSortdown(int a[], int n)
{
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
		 	if(a[j]>a[i])
				swap(a[i], a[j]);
}
void BubbleSort(int a[], int n){	
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
		   if(a[j] < a[j-1])
		       swap(a[j], a[j-1]);
}
void BubbleSortdown(int a[], int n){	
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
		   if(a[j] > a[j-1])
		       swap(a[j], a[j-1]);
}

void menu(int &chon){
printf("\n\1n\n0: Thoat chuong trinh");
printf("\n1: Sinh day so");
printf("\n2: Xuat day so");
printf("\n3: Sap xep mang tang dan theo Interchange sort");
printf("\n4: Sap xep mang giam dan theo Interchange sort");
printf("\n5: Sap xep mang tang dan theo Bubble sort");
printf("\n6: Sap xep mang giam dan theo Bubble sort");
printf("\nBan hay chon: "); scanf("%d", &chon);
}
int main()
{
//khai báo các bien luu du liuu can su dung
	int a[100], n, x, vt, chon;

	do{
//xu?t menu cho ngu?i dùng ch?n
		menu(chon);

		switch(chon){
			case 1: nhapSL(n), sinhDS(a,n); break;
			case 2: xuatDS(a,n); break;
			case 3: InterchangeSort(a,n); 	
			printf("\nDay so sau khi sap xep tang dan theo Interchange sort la:");
			xuatDS(a,n);break;
			case 4: InterchangeSortdown(a,n); 	
			printf("\nDay so sau khi sap xep giam dan theo Interchange sort la:");
			xuatDS(a,n);break;
			case 5: BubbleSort(a,n); 	
			printf("\nDay so sau khi sap xep tang dan theo Bubble sort la:");
			xuatDS(a,n);break;
			case 6: BubbleSortdown(a,n); 	
			printf("\nDay so sau khi sap xep giam dan theo Bubble sort la:");
			xuatDS(a,n);break;
			default: printf("Chon sai, chuong trinh ket thuc"); chon=0;
		}
	}while (chon!=0);
	return 0;
}
