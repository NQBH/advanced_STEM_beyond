#include <iostream>
#include <vector>
#include <iomanip>

void nhapMaTran(std::vector<std::vector<double>>& maTran, int soHang, int soCot) {
    std::cout << "Nhap cac phan tu cua ma tran:" << std::endl;
    for (int i = 0; i < soHang; ++i) {
        for (int j = 0; j < soCot; ++j) {
            std::cout << "Phan tu [" << i + 1 << "][" << j + 1 << "]: ";
            std::cin >> maTran[i][j];
        }
    }
}

void xuatMaTran(const std::vector<std::vector<double>>& maTran) {
    for (const auto& hang : maTran) {
        for (double phanTu : hang) {
            std::cout << std::setw(8) << phanTu;
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<double>> chuyenVi(const std::vector<std::vector<double>>& A) {
    int soHang = A.size();
    int soCot = A[0].size();

    std::vector<std::vector<double>> A_T(soCot, std::vector<double>(soHang));

    for (int i = 0; i < soHang; ++i) {
        for (int j = 0; j < soCot; ++j) {
            A_T[j][i] = A[i][j];
        }
    }
    return A_T;
}

int main() {
    int soHang, soCot;
    std::cout << "Nhap so hang: ";
    std::cin >> soHang;
    std::cout << "Nhap so cot: ";
    std::cin >> soCot;

    if (soHang <= 0 || soCot <= 0) {
        std::cout << "Kich thuoc ma tran khong hop le." << std::endl;
        return 1;
    }

    std::vector<std::vector<double>> A(soHang, std::vector<double>(soCot));
    nhapMaTran(A, soHang, soCot);
    
    std::vector<std::vector<double>> A_T = chuyenVi(A);
    std::cout << "\nMa tran chuyen vi A^T:" << std::endl;
    xuatMaTran(A_T);

    return 0;
}