NTB_Matrix4
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

std::vector<std::vector<double>> nhanMaTran(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) {
    int soHangA = A.size();
    int soCotA = A[0].size();
    int soCotB = B[0].size();

    std::vector<std::vector<double>> C(soHangA, std::vector<double>(soCotB, 0.0));

    for (int i = 0; i < soHangA; ++i) {
        for (int j = 0; j < soCotB; ++j) {
            for (int k = 0; k < soCotA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    int m, n, p;
    std::cout << "Nhap so hang ma tran A (m): ";
    std::cin >> m;
    std::cout << "Nhap so cot ma tran A / so hang ma tran B (n): ";
    std::cin >> n;
    std::cout << "Nhap so cot ma tran B (p): ";
    std::cin >> p;
    
    if (m <= 0 || n <= 0 || p <= 0) {
        std::cout << "Kich thuoc ma tran khong hop le." << std::endl;
        return 1;
    }

    std::vector<std::vector<double>> A(m, std::vector<double>(n));
    std::vector<std::vector<double>> B(n, std::vector<double>(p));

    std::cout << "\n--- Nhap ma tran A (" << m << "x" << n << ") ---" << std::endl;
    nhapMaTran(A, m, n);
    std::cout << "\n--- Nhap ma tran B (" << n << "x" << p << ") ---" << std::endl;
    nhapMaTran(B, n, p);
    
    std::vector<std::vector<double>> ketQua = nhanMaTran(A, B);

    std::cout << "\nKet qua A * B:" << std::endl;
    xuatMaTran(ketQua);

    return 0;
}