#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �inh nghia kieu Mat h�ng
typedef struct MatHang {
    char mahang[10];
    char tenhang[30];
    int soluong;
} MH;

// �inh nghia cau tr�c mot n�t de luu 1 mat h�ng
typedef struct node {
    MH info;
    struct node* next;
} Node;

// Khoi tao danh s�ch
void init(Node*& phead) {
    phead = NULL;
}

// Tao mot n�t moi
Node* CreateNode(MH item) {
    Node* p = new Node;
    p->info = item;
    p->next = NULL;
    return p;
}

// Nhap th�ng tin mot mat h�ng
void input1MH(MH& item) {
    printf("Nhap ma hang: ");
    scanf("%s", item.mahang);
    printf("Nhap ten hang: ");
    getchar(); // X�a k� t? newline c�n l?i
    fflush(stdin); gets(item.tenhang);
    printf("Nhap so luong ton: ");
    scanf("%d", &item.soluong);
}

// Nhap danh s�ch mat h�ng
void inputList(Node*& phead) {
    int c;
    do {
        MH item;
        input1MH(item);
        
        Node* p = CreateNode(item);
        p->next = phead;
        phead = p;

        printf("Chon 1 de tiep tuc nhap, 0 de exit: ");
        scanf("%d", &c);
    } while (c != 0);
}

// Xu?t th�ng tin m?t m?t h�ng
void Output1MH(MH item) {
    printf("Ma hang: %s, Ten hang: %s, So luong ton: %d\n", 
           item.mahang, item.tenhang, item.soluong);
}

// Xuat danh s�ch mat h�ng
void output(Node* phead) {
    Node* p = phead;
    if (p == NULL) {
        printf("\nDanh sach bi rong\n");
    } else {
        while (p != NULL) {
            Output1MH(p->info);
            p = p->next;
        }
    }
}

// T�m mat h�ng c� m� x
Node* search(Node* phead, char x[]) {
    Node* p = phead;
    while (p != NULL) {
        if (strcmp(p->info.mahang, x) == 0) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// Th�m mot mat h�ng m v�o sau n�t p
void insertAfter(Node* p, MH& m) {
    if (p != NULL) {
        Node* newNode = CreateNode(m);
        newNode->next = p->next;
        p->next = newNode;
    }
}

// X�a n�t dau danh s�ch
void deleteFirst(Node*& phead) {
    if (phead == NULL) {
        printf("Danh sach rong\n");
    } else {
        Node* p = phead;
        phead = phead->next;
        free(p);
    }
}

// X�a to�n bo danh s�ch
void deleteAll(Node*& phead) {
    while (phead != NULL) {
        deleteFirst(phead);
    }
}

// X�a mat h�ng c� m� x
void deleteViaCode(Node*& phead, char x[]) {
    if (phead == NULL) {
        printf("Danh sach rong\n");
        return;
    }
    // Neu n�t dau DS chua mat h�ng c� m� x
    if (strcmp(phead->info.mahang, x) == 0) {
        deleteFirst(phead);
        return;
    }

    Node* p = phead;
    while (p->next != NULL && strcmp(p->next->info.mahang, x) != 0) {
        p = p->next;
    }

    if (p->next == NULL) {
        printf("Khong tim thay\n");
    } else {
        Node* temp = p->next;
        p->next = temp->next;
        free(temp);
    }
}

// Sap xep danh s�ch tang theo t�n h�ng
void sort(Node* phead) {
    Node *i, *j;
    for (i = phead; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->info.tenhang, j->info.tenhang) > 0) {
                MH temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}

int main() {
    Node* phead;
    init(phead);

    int choice;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap danh sach mat hang\n");
        printf("2. Xuat danh sach mat hang\n");
        printf("3. Tim mat hang theo ma\n");
        printf("4. Them mat hang sau mat hang co ma\n");
        printf("5. Xoa mat hang dau danh sach\n");
        printf("6. Xoa toan bo danh sach\n");
        printf("7. Xoa mat hang theo ma\n");
        printf("8. Sap xep danh sach theo ten hang\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputList(phead);
                break;
            case 2:
                output(phead);
                break;
            case 3: {
                char x[10];
                printf("Nhap ma hang can tim: ");
                fflush(stdin);
                gets(x);
                Node* kq = search(phead, x);
                if (kq == NULL) {
                    printf("Khong tim thay\n");
                } else {
                    printf("Mat hang tim duoc la:\n");
                    Output1MH(kq->info);
                }
                break;
            }
            case 4: {
                char x[10];
                printf("Nhap ma hang can tim: ");
                fflush(stdin);
                gets(x);
                Node* kq = search(phead, x);
                if (kq == NULL) {
                    printf("Khong tim thay\n");
                } else {
                    MH m;
                    input1MH(m);
                    insertAfter(kq, m);
                    printf("Danh sach sau khi them mat hang:\n");
                    output(phead);
                }
                break;
            }
            case 5:
                deleteFirst(phead);
                printf("Da xoa mat hang dau danh sach.\n");
                printf("Danh sach sau khi xoa:\n");
                output(phead);
                break;
            case 6:
                deleteAll(phead);
                printf("Da xoa toan bo danh sach.\n");
                break;
            case 7: {
                char x[10];
                printf("Nhap ma hang muon xoa: ");
                fflush(stdin);
                gets(x);
                deleteViaCode(phead, x);
                printf("Danh sach sau khi xoa:\n");
                output(phead);
                break;
            }
            case 8:
                sort(phead);
                printf("Danh sach sau khi sap xep:\n");
                output(phead);
                break;
            case 0:
                printf("Thoat.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}

