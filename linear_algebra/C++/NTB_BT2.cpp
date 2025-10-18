NTB_Matrix2
#include <iostream>
#include <vector>
#include <iomanip>

void nhapMaTran(std::vector<std::vector<double>>& maTran, int soHang, int soCot) {
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

std::vector<std::vector<double>> congMaTran(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) {
    int soHang = A.size();
    int soCot = A[0].size();
    std::vector<std::vector<double>> ketQua(soHang, std::vector<double>(soCot));
    for (int i = 0; i < soHang; ++i) {
        for (int j = 0; j < soCot; ++j) {
            ketQua[i][j] = A[i][j] + B[i][j];
        }
    }
    return ketQua;
}

std::vector<std::vector<double>> truMaTran(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) {
    int soHang = A.size();
    int soCot = A[0].size();
    std::vector<std::vector<double>> ketQua(soHang, std::vector<double>(soCot));
    for (int i = 0; i < soHang; ++i) {
        for (int j = 0; j < soCot; ++j) {
            ketQua[i][j] = A[i][j] - B[i][j];
        }
    }
    return ketQua;
}

int main() {
    int soHang, soCot;
    std::cout << "Nhap kich thuoc cho hai ma tran (so hang va so cot): ";
    std::cin >> soHang >> soCot;

    if (soHang <= 0 || soCot <= 0) {
        std::cout << "Kich thuoc ma tran khong hop le." << std::endl;
        return 1;
    }

    std::vector<std::vector<double>> A(soHang, std::vector<double>(soCot));
    std::vector<std::vector<double>> B(soHang, std::vector<double>(soCot));

    std::cout << "\n--- Nhap ma tran A ---" << std::endl;
    nhapMaTran(A, soHang, soCot);
    std::cout << "\n--- Nhap ma tran B ---" << std::endl;
    nhapMaTran(B, soHang, soCot);

    std::cout << "\nKet qua A + B:" << std::endl;
    std::vector<std::vector<double>> C_cong = congMaTran(A, B);
    xuatMaTran(C_cong);
    
    std::cout << "\nKet qua A - B:" << std::endl;
    std::vector<std::vector<double>> C_tru = truMaTran(A, B);
    xuatMaTran(C_tru);

    return 0;
}