#include <stdio.h>

void in_ma_tran(int mtr[][50], int h, int c) {
    printf("\n hien ra nao ma tran \n");
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", mtr[i][j]);
        }
        printf("\n");
    }
    printf("---\n");
}

int main() {
    int bai;
    printf("chon so cau 1 or cau 2: ");
    scanf("%d", &bai);

    if (bai == 1) {

        printf("\n Bai toan 1: Ma tran bo sung [A|b] \n");
        int a[50][50];
        int b[50];
        int h, c;

        printf("Nhap col,row cho A: ");
        scanf("%d %d", &h, &c);

        printf("Nhap A:\n");
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        int n;
        printf("Nhap so pt cua b: ");
        scanf("%d", &n);

        printf("Nhap b:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }

        if (h != n) {
            printf("NOT cleer");
        } else {
            printf("Ket qua [A|b]:\n");
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < c; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("| %d\n", b[i]);
            }
        }
    }
    else if (bai == 2) {

        printf("\n Bai toan 2: \n");
        int a[50][50];
        int h, c;

        printf("Nhap col,row cho A: ");
        scanf("%d %d", &h, &c);

        printf("Nhap A:\n");
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        int lua_chon = 0;
        while (lua_chon != 4) {
            in_ma_tran(a, h, c);
            printf("Chon phep bien doi:\n");
            printf("1. Doi cho 2 dong (R_i <-> R_j)\n");
            printf("2. Nhan 1 dong voi 1 so (k*R_i -> R_i)\n");
            printf("3. Cong mot dong voi mot dong khac da nhan voi mot so (R_i + k*R_j -> R_i)\n");
            printf("4. exit\n");
            printf("co the chon khac di ");
            scanf("%d", &lua_chon);

            if (lua_chon == 1) {
                int r1, r2;
                printf("Doi dong: ");
                scanf("%d", &r1);
                printf("cho dong: ");
                scanf("%d", &r2);


                for (int j = 0; j < c; j++) {
                    int temp = a[r1 - 1][j];
                    a[r1 - 1][j] = a[r2 - 1][j];
                    a[r2 - 1][j] = temp;
                }
            } else if (lua_chon == 2) {
                int r, k;
                printf("Nhan dong: ");
                scanf("%d", &r);
                printf("voi so: ");
                scanf("%d", &k);

                for (int j = 0; j < c; j++) {
                    a[r - 1][j] = a[r - 1][j] * k;
                }
            } else if (lua_chon == 3) {
                int r_i, r_j, k;
                printf("Lay dong (R_i): ");
                scanf("%d", &r_i);
                printf("cong voi so: ");
                scanf("%d", &k);
                printf("nhan voi dong (R_j): ");
                scanf("%d", &r_j);

                for (int j = 0; j < c; j++) {
                    a[r_i - 1][j] = a[r_i - 1][j] + k * a[r_j - 1][j];
                }
            }
        }
    }
    else {
        printf("NOt de");
    }

    return 0;
}