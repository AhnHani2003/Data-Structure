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
void SelectionSort(int a[], int n)
{
	for (int i=0; i<n-1; i++) {
    	int min = i;
    	for (int j=i+1; j<n; j++) 
        	if (a[min] > a[j]) 
            	min = j;
        swap(a[i],a[min]);
    }
}

void SelectionSortdown(int a[], int n)
{
	for (int i=0; i<n-1; i++) {
    	int max = i;
    	for (int j=i+1; j<n; j++) 
        	if (a[max] < a[j]) 
            	max = j;
        swap(a[i],a[max]);
    }
}

void InsertionSort(int a[], int n)
{
	int pos, x;
	for(int i=1; i<n; i++)
	{
   		x= a[i]; pos=i-1;
   		while(pos>=0 && a[pos]>x)
   		{
   			a[pos+1] = a[pos];
   			pos--;
		}
		a[pos+1] = x;
	}
}

void InsertionSortdown(int a[], int n)
{
	int pos, x;
	for(int i=1; i<n; i++)
	{
   		x= a[i]; pos=i-1;
   		while(pos>=0 && a[pos]<x)
   		{
   			a[pos+1] = a[pos];
   			pos--;
		}
		a[pos+1] = x;
	}
}


void menu(int &chon){
printf("\n\n\n0: Thoat chuong trinh");
printf("\n1: Sinh day so");
printf("\n2: Xuat day so");
printf("\n3: Sap xep mang tang dan theo Selection Sort");
printf("\n4: Sap xep mang giam dan theo Selection Sort");
printf("\n5: Sap xep mang tang dan theo Insertion Sort");
printf("\n6: Sap xep mang giam dan theo Insertion Sort");
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
			case 3: SelectionSort(a,n); 	
			printf("\nDay so sau khi sap xep tang dan theo Selection Sort la:");
			xuatDS(a,n);break;
			case 4: SelectionSortdown(a,n); 	
			printf("\nDay so sau khi sap xep giam dan theo Selection Sort la:");
			xuatDS(a,n);break;
			case 5: InsertionSort(a,n); 	
			printf("\nDay so sau khi sap xep tang dan theo Insertion Sort la:");
			xuatDS(a,n);break;
			case 6: InsertionSortdown(a,n); 	
			printf("\nDay so sau khi sap xep giam dan theo Insertion Sort la:");
			xuatDS(a,n);break;
			default: printf("Chon sai, chuong trinh ket thuc"); chon=0;
		}
	}while (chon!=0);
	return 0;
}
