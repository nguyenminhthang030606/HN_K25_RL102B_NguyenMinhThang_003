#include <stdio.h>
#define MAX_SIZE 50

int passengers[MAX_SIZE] = {32, 18, 45, 27, 50};

int n = 5;

void displayPassengers() {
    printf("=== DANH SACH HANH KHACH ===\n");
    for (int i = 0; i < n; i++) {
        printf("Hanh khach %d: %d\n", i + 1, passengers[i]);
    }
}
int main() {
    int choice;     
    do {
        printf("\n=== HE THONG QUAN LY HANH KHACH ===\n");
        printf("1. them so luong hanh khach\n");
         printf("2. Sua so luong hanh khach\n");
        printf("3. Xoa so luong hanh khach\n");
        printf("4. Tim kiem so luong hanh khach\n");
        printf("0. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice){

            case 1:
            int value,position;
            if (n >= MAX_SIZE) {
                printf(" hanh khach da day\n");
                break;
            }
            printf("Nhap gia tri can them: ");
            scanf("%d", &value);
            printf("Nhap vi tri can them (0 den %d): ", n);
            scanf("%d", &position);
            if (position >= 1 && position <= n + 1) {
                for (int i = n; i > position - 1; i--) {
                    passengers[i] = passengers[i - 1];
                }
                passengers[position - 1] = value;
                n++;
            } else {
                printf("Vi tri khong hop le\n");
                break;
            }
                break;
            case 2:
            int newValue, editPosition;
            printf("Nhap vi tri can sua (1 den %d): ", n);
            scanf("%d", &editPosition);
            printf("Nhap gia tri moi: ");
            scanf("%d", &newValue);
            if (editPosition >= 1 && editPosition <= n) {
                if (newValue >= 0) {
                    passengers[editPosition - 1] = newValue;
                    printf("Da cap nhat so luong hanh khach\n");
                } else {
                    printf("So luong hanh khach khong hop le\n");
                }
            } else {
                printf("Vi tri sua khong hop le\n");
            }
                break;
            case 3:
            if (n == 0) {
                printf("danh sach trong khong co hanh khach de xoa\n");
                break;
            }
            int deletePosition;
            printf("Nhap vi tri can xoa (1 den %d): ", n);
            scanf("%d", &deletePosition);
            if (deletePosition >= 1 && deletePosition <= n) {
                for (int i = deletePosition - 1; i < n - 1; i++) {
                    passengers[i] = passengers[i + 1];
                }
            }else {
                    printf("Vi tri xoa khong hop le\n");
                    break;
                }
                n--;
                printf("Da xoa hanh khach tai vi tri %d\n", deletePosition);
                break;
            case 4:
            int searchValue, found = 0, count=0;
            printf("Nhap gia tri can tim kiem: ");
            scanf("%d", &searchValue);
            printf("=============================\n");
            printf("KET QUA TIM KIEM\n");
            printf("=============================\n");
            for (int i = 0; i < n; i++) {
                if (passengers[i] == searchValue) {
                    printf(" tim thay tai vi tri: %d\n", passengers[i]);
                    count++;
                    found = 1;
                    break;
                }
            }
            printf("tong so lan xuat hien: %d", count);
            if (!found) {
                printf("Khong tim thay gia tri trong mang %d\n", searchValue);
            }
            break;
        }while (choice != 0);
    }
}


