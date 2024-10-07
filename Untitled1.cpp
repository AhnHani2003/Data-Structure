#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct benhnhan {
    int stt;
    char hoten[30];
    int tuoi;
} BenhNhan;

typedef struct node {
    BenhNhan info;
    struct node* next;
} Node;

typedef Node* QUEUE; // Ð?nh nghia QUEUE là m?t con tr? t?i Node

// Hàm kh?i t?o Queue
void init(QUEUE &q) {
    q = NULL; // Kh?i t?o Queue
}

// Hàm ki?m tra Queue có r?ng hay không
int isEmpty(QUEUE q) {
    return (q == NULL); // Ki?m tra Queue có r?ng hay không
}

// Hàm thêm b?nh nhân vào Queue
void Push(QUEUE& q, BenhNhan x) {
    Node* p = new Node; // C?p phát b? nh? cho node m?i
    p->info = x; // Gán thông tin b?nh nhân
    p->next = NULL; // Node m?i s? là node cu?i nên next là NULL

    if (isEmpty(q)) {
        q = p; // N?u Queue r?ng, gán node m?i làm d?u
    } else {
        Node* temp = q;
        while (temp->next != NULL) {
            temp = temp->next; // Tìm d?n node cu?i
        }
        temp->next = p; // G?n node m?i vào cu?i
    }
}

// Hàm l?y b?nh nhân ti?p theo t? Queue (Hàm Pop)
int popPatient(QUEUE& q, BenhNhan& x) {
    if (isEmpty(q)) {
        printf("Khong co benh nhan nao trong danh sach.\n");
        return 0; // Không có b?nh nhân
    }

    Node* temp = q; // Luu node d?u
    x = temp->info; // Truy?n thông tin b?nh nhân cho tham s? x
    q = (q)->next; // Gán d?u Queue sang node ti?p theo
    delete(temp); // Gi?i phóng node dã xóa

    return 1; // Thành công
}

// Hàm d?m s? lu?ng b?nh nhân chua khám
int countPending(QUEUE q) {
    int count = 0;
    Node* current = q;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Hàm xu?t danh sách b?nh nhân còn trong Queue
void printQueue(QUEUE q) {
    if (isEmpty(q)) {
        printf("Khong co benh nhan nao trong danh sach.\n");
        return;
    }

    Node* current = q;
    printf("Danh sach benh nhan chua kham:\n");
    while (current != NULL) {
        printf("STT: %d, Ho Ten: %s, Tuoi: %d\n", current->info.stt, current->info.hoten, current->info.tuoi);
        current = current->next;
    }
}

int main() {
    QUEUE q;
    init(q); // Kh?i t?o Queue
    int stt = 1;
    int choice;

    while (1) {
        printf("\n=== Menu ===\n");
        printf("1. Them benh nhan vao hang doi\n");
        printf("2. Lay benh nhan tiep theo kham\n");
        printf("3. So luong benh nhan da kham\n");
        printf("4. So luong benh nhan chua kham\n");
        printf("5. Xuat danh sach benh nhan chua kham\n");
        printf("6. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                BenhNhan bn;
                printf("Nhap ho ten: ");
                getchar(); // Xóa ký t? newline còn l?i
                fgets(bn.hoten, 30, stdin);
                bn.hoten[strcspn(bn.hoten, "\n")] = 0; // Xóa newline
                printf("Nhap tuoi: ");
                scanf("%d", &bn.tuoi);
                bn.stt = stt++;
                Push(q, bn); // G?i hàm Push thay vì insert
                printf("Da them benh nhan %s vao hang doi.\n", bn.hoten);
                break;
            }
            case 2: {
                BenhNhan bn;
                if (popPatient(q, bn)) {
                    printf("Benh nhan tiep theo kham: STT: %d, Ho Ten: %s, Tuoi: %d\n", bn.stt, bn.hoten, bn.tuoi);
                }
                break;
            }
            case 3: {
                printf("So luong benh nhan da kham: %d\n", stt - 1 - countPending(q));
                break;
            }
            case 4: {
                printf("So luong benh nhan chua kham: %d\n", countPending(q));
                break;
            }
            case 5: {
                printQueue(q);
                break;
            }
            case 6: {
                printf("Thoat chuong trinh.\n");
                return 0;
            }
            default:
                printf("Chuc nang khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}

