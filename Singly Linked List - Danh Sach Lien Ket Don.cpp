#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node*next;
}Node;
void init(Node*&phead){
	phead = NULL;
}
int isEmpty(Node*phead)
{
	return (phead==NULL);
}
Node*CreateNode(int x)
{
	Node *p = new Node;
	p->info=x;
	p->next=NULL;
	return p;
}
//a
void InsertFirst(Node*&phead, int x)
{
	Node*p = CreateNode(x);
	p->next = phead;
		phead = p;
}
void inputList (Node*&phead)
{
	int c;
	do{
		int x; printf("Nhap x: "); scanf("%d",&x);
		InsertFirst(phead,x);
		printf("Chon 1 de tiep tuc nhap, 0 de exit: ");
		scanf("%d", &c);
		if(c==0)
		break;
	}while(c!=0);
}
//b
void showlist(Node*phead)
{
	Node*p=phead;
	if(p==NULL)
		printf("\nDanh sach bi rong");
	while(p!=NULL)
	{
		printf("%6d",p->info);
		p=p->next;
	}
}
//c
void sort(Node*phead)
{
	for(Node*i=phead;i->next!=NULL; i=i->next)
	{
		Node*min = i;
		for(Node*j=i->next;j!=NULL;j=j->next)
			if(min->info > j->info)
				min = j;
		int t = min -> info;
		min->info = i->info;
		i->info = t;
	}
}
//d
Node *Search(Node*phead, int x)
{
	Node *p=phead;
	while(p!=NULL && p->info!=x)
		p=p->next;
	return p;
}
void InsertAfter(Node*p, int x)
{
	Node*newNode;
	if(p!=NULL)
	{
		newNode = CreateNode(x);
		newNode -> next = p->next;
		p->next = newNode;
	}
}
//e
void DeleteFirst(Node*&phead)
{
	Node*p;
	if(isEmpty(phead))
		printf("danh sach rong");
	else
	{
		p = phead;
		phead = phead ->next;
		delete p;
	}
}
//f
Node *SearchBefore(Node*phead, int x)
{
	Node *p=phead;
	while(p->next!=NULL && p->next->info!=x)
		p=p->next;
	return p;
}
void DeleteAfter(Node*p)
{
	Node*q;
	if(p == NULL || p->next ==NULL)
		printf("Khong the xoa");
	else{
		q = p->next;
		p->next = q->next;
		delete q;
	}
}
//g
void ClearList(Node*&phead)
{
	while(phead!=NULL)
		DeleteFirst(phead);
}
//h
int Count(Node*phead)
{
	int a = 0;
	Node*i = phead;
	while(i){
		a++;
		i = i ->next;
	}
	return a;
}
int getKthValue(Node*phead, int k) {
        Node* current = phead;
        int index = 0;
        while (current) {
            if (index == k) {
                return current->info;
            }
            current = current->next;
            index++;
        }
        return -1; 
}
int main()
{
	Node *phead;
	phead = new Node;
	int x,y,z,a;
	init(phead);
	inputList(phead);
	printf("Day so duoc nhap la: ");		showlist(phead);
	sort(phead);
	printf("\n\nDay so duoc sap xep la: ");	showlist(phead);
	printf("\n\nHay nhap so muon tim: x = "); 		scanf("%d",&x);
	printf("\nHay nhap so muon them sau: y = ");	scanf("%d",&y);
	Node *p;
	p = Search(phead, x);
	InsertAfter(p,y);
	printf("\n\nDay so sau khi duoc them la: ");	showlist(phead);
	printf("\n\nDay so sau khi xoa so dau tien la:");
	DeleteFirst(phead);
	showlist(phead);
	printf("\n\nNhap so muon xoa: z = "); scanf("%d",&z);
	p = SearchBefore(phead, z);
	DeleteAfter(p);
	printf("\n\nDay so sau khi xoa so %d:",z);
	showlist(phead);
	printf("\n\nSo phan tu trong day so la: %d",Count(phead));
	printf("\n\nNhap thu tu so muon tim: a = ");	scanf("%d",&a);
	if(getKthValue(phead,a) == -1)
		printf("So thu tu nam ngoai mang");
	else
		printf("\nGia tri cua node thu %d la: %d",a,getKthValue(phead,a));
		
}
