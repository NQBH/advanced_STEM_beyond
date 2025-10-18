#include <iostream>
#include <vector>
#include <iomanip>

void nhapMaTran(std::vector<std::vector<double>>& maTran, int n) {
    std::cout << "Nhap cac phan tu cua ma tran:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "Phan tu [" << i + 1 << "][" << j + 1 << "]: ";
            std::cin >> maTran[i][j];
        }
    }
}

void xuatMaTran(const std::vector<std::vector<double>>& maTran) {
    std::cout << "\nMa tran da nhap:" << std::endl;
    for (const auto& hang : maTran) {
        for (double phanTu : hang) {
            std::cout << std::setw(8) << phanTu;
        }
        std::cout << std::endl;
    }
}

bool kiemTraMaTranDuongCheo(const std::vector<std::vector<double>>& maTran) {
    int n = maTran.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && maTran[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool kiemTraMaTranTamGiacTren(const std::vector<std::vector<double>>& maTran) {
    int n = maTran.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > j && maTran[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool kiemTraMaTranTamGiacDuoi(const std::vector<std::vector<double>>& maTran) {
    int n = maTran.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i < j && maTran[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool kiemTraMaTranDoiXung(const std::vector<std::vector<double>>& maTran) {
    int n = maTran.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (maTran[i][j] != maTran[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    std::cout << "Nhap kich thuoc n cho ma tran vuong: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Kich thuoc n phai la mot so nguyen duong." << std::endl;
        return 1;
    }

    std::vector<std::vector<double>> A(n, std::vector<double>(n));
    nhapMaTran(A, n);
    xuatMaTran(A);

    std::cout << "\n--- KET QUA KIEM TRA ---" << std::endl;

    std::cout << "1. Co phai ma tran duong cheo khong? " 
              << (kiemTraMaTranDuongCheo(A) ? "Co" : "Khong") << std::endl;

    std::cout << "2. Co phai ma tran tam giac tren khong? "
              << (kiemTraMaTranTamGiacTren(A) ? "Co" : "Khong") << std::endl;

    std::cout << "3. Co phai ma tran tam giac duoi khong? "
              << (kiemTraMaTranTamGiacDuoi(A) ? "Co" : "Khong") << std::endl;
              
    std::cout << "4. Co phai ma tran doi xung khong? "
              << (kiemTraMaTranDoiXung(A) ? "Co" : "Khong") << std::endl;

    return 0;
}