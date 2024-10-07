#include <stdio.h>
#include <string.h>
#define MAX 100
//dinh nghia kieu du lieu dau sách
typedef struct ThongtinSinhvien
{

	char mssv [10]; 
	char hoten [40]; 
	float dtb;
}sinhvien;
//a. ---------------------------------------------------------
void nhapSL(int &n)
{
	do{
		printf("So luong thong tin sinh vien muon nhap: ");
		scanf("%d",&n);
			if(n<=0){
				printf("Hay nhap lai so luong sinh vien: ");
				scanf("%d",&n);
			}
			if(n>MAX){
			printf("Hay nhap lai so luong sinh vien, so luong sinh vien khong the lon hon 100: ");
			scanf("%d",&n);		
			}
	}while (n<=0 || n>MAX);
}
void nhap1SV(sinhvien &x)
{
	printf("Nhap ma so sinh vien: "); 
	scanf("%s", &x.mssv);
	printf("Nhap ho ten sinh vien: "); 
	fflush(stdin); gets(x.hoten);
	printf("Nhap diem trung binh: "); 
	scanf("%f", &x.dtb);
}
void nhapDS(sinhvien a[], int n)
{
	for (int i = 0; i < n; i ++)
	{
		printf ("Nhap thong tin sinh vien thu %d:\n", i+1);
		nhap1SV(a[i]);
	}
}
//b. ---------------------------------------------------------
void xuat1SV(sinhvien x)
{
	printf("\nMa so sinh vien: %s\nHo ten sinh vien: %s\nDiem trung binh: %f", x.mssv, x.hoten,x.dtb);
}
void xuatDS(sinhvien x[], int n)
{
	printf ("\nDanh sach cac sinh vien:");
	for (int i = 0; i < n; i ++)
	{
		printf("\nThong tin sach thu %d",i+1);
		xuat1SV(x[i]);
	}
}
//c. ---------------------------------------------------------
void Nhap(char a[])
{
	fflush(stdin); gets(a);
}

int timtheomssv(sinhvien x[], int n, char a[10])
{
	for(int i = 0; i < n; i ++)
		if (strcmp(x[i].mssv,a)==0) return i;
	return -1;
}
//d.---------------------------------------------------------
void timtheoten(sinhvien x[], int n, char a[40])
{
	
	for(int i = 0; i < n; i ++)
		if (strcmp(x[i].hoten,a)!=0)
			printf("Khong tim thay",a);
		else
		{
			printf("Thong tin sinh vien %s can tim:\n",a);
			xuat1SV(x[i]);
			printf("\n");
		}
}
//e.---------------------------------------------------------
void timMAX(sinhvien x[], int n)
{
	float max = x[0].dtb;
	printf("Cac sinh vien co diem trung binh cao nhat:\n");
	for(int i = 0; i<n; i++)
		if(x[i].dtb>max)
			max = x[i].dtb;
	for(int i = 0; i<n; i++)
		if(x[i].dtb == max)
		{
			xuat1SV(x[i]);
			printf("\n");
		}
}
//************************************************
void menu(int &chon){
printf("\n\n\n0: Thoat chuong trinh");
printf("\n1: Nhap thong tin sinh vien");
printf("\n2: Xuat thong tin sinh vien");
printf("\n3: Tim thong tin sinh vien theo ma so sinh vien");
printf("\n4: Tim thong tin sinh vien theo ho ten");
printf("\n5: Xuat cac sinh vien co diem trung binh cao nhat");
printf("\nBan hay chon: "); scanf("%d", &chon);
}

int main()
{
//khai báo các bien luu du liuu can su dung
	sinhvien a[MAX];
	int n, chon;
	char x[10];
	char y[40];

	do{
//xu?t menu cho ngu?i dùng ch?n
		menu(chon);

		switch(chon){
			case 1: nhapSL(n), nhapDS(a,n); break;
			case 2: xuatDS(a,n); break;
			case 3: 
			printf("Hay nhap ma so sinh vien can tim: ");
			Nhap(x);
			if(timtheomssv(a,n,x)==-1)
				printf("\nKhong tim thay\n");
			else{
				printf("\nThong tin sinh vien can tim: \n");
				xuat1SV(a[timtheomssv(a,n,x)]);
			}
			break;
			case 4: 
			printf("Hay nhap ho ten sinh vien can tim: ");
			Nhap(y);
			timtheoten(a,n,y);
			break;
			case 5: timMAX(a,n); break;
			default: printf("Chon sai, chuong trinh ket thuc"); chon=0;
		}
	}while (chon!=0);
	return 0;
}
