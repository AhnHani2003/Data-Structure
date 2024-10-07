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
void sapXep(int a[], int n)
{
	int i, j, tam;
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if (a[i]<a[j]) 
			{ //sap xep giamdan
//hoán vi giá tra cua 2 ô nho
				tam=a[i];
				a[i]=a[j];
				a[j]=tam;
			}

}
int timNhiPhan(int a[], int n, int x)
{
//gioi han pham vi tìm kiem bang các bien dau, cuoi, giua
	int dau=0, cuoi=n-1, giua;
	while (dau <= cuoi) //lap chung nào pham vi tìm kiem còn phan tu
	{
		giua= (dau+cuoi)/2; //xác dinh vi trí phan tu chính giua
//so sánh phan tu dung giua DS voi x can tìm
		if (x==a[giua]) return giua;
		if (x>a[giua]) cuoi=giua-1; //tìm o nua sau
		if (x<a[giua]) dau=giua+1; //tìm o nua dau
	}
	return -1; 
}
void XoaPhanTu(int a[], int &n, int t)//ham xoa phan tu
{

    if(t<=0)//khong co phan tu trong mang
    {
        printf("Khong the xoa mang rong!");
        return;
    }else if(t>=n)//vi tri muon xoa nam ngoai mang
    {
        printf("vi tri nam ngoai mang!");
        return;
    }
    for(int i=t; i<n ; i++)//dich chuyen mang
    {
        a[i] = a[i+1];        
    }
    n--;// tang so phan tu cua mang
}
void menu(int &chon){
printf("\n\44n\n0: Thoat chuong trinh");
printf("\n1: Sinh day so");
printf("\n2: Xuat day so");
printf("\n3: Sap xep");
printf("\n4: Tim x");
printf("\n5: Xoa x");
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
			case 3: sapXep(a,n); 	
			printf("\nDay so sau khi sap xep giam dan la: ");
			xuatDS(a,n);break;
			case 4: 
			printf("Nhap gia tri can tim x= ");
			nhapX(x); 
			vt = timNhiPhan(a,n,x);
			if(vt==-1)
				printf("Khong tim thay phan tu vua nhap");
			else
				printf("Vi tri phan tu can tim la: %d",vt); 
			break;
			case 5: 
			printf("Nhap gia tri can xoa x= ");
			nhapX(x); 
			vt=timNhiPhan(a,n,x);
			if (vt==-1) 
				printf("Khong tim thay");
			else {
				XoaPhanTu(a, n, vt);
				printf("\nDay so sau khi xoa la:");
				xuatDS(a,n);
			}
			break;
			default: printf("Chon sai, chuong trinh ket thuc"); chon=0;
		}
	}while (chon!=0);
	return 0;
}
