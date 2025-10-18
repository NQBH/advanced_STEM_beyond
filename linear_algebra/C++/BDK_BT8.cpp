#include <iostream>

int main() {
    int n;
    std::cout << "Nhap so nguyen        : ";
    std::cin >> n;

    int ma_1[100][100];
    int unit_ma_tran[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ma_1[i][j] = 0;
            if (i == j) {
                unit_ma_tran[i][j] = 1;
            } else {
                unit_ma_tran[i][j] = 0;
            }
        }
    }

    std::cout << "\nMa tran 0 kich thuoc " << n << "x" << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << ma_1[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nMa tran don vi kich thuoc " << n << "x" << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << unit_ma_tran[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}