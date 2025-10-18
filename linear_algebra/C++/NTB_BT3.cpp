NTB_Matrix3
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

std::vector<std::vector<double>> nhanVoHuong(const std::vector<std::vector<double>>& A, double c) {
    int soHang = A.size();
    int soCot = A[0].size();
    std::vector<std::vector<double>> ketQua(soHang, std::vector<double>(soCot));
    for (int i = 0; i < soHang; ++i) {
        for (int j = 0; j < soCot; ++j) {
            ketQua[i][j] = A[i][j] * c;
        }
    }
    return ketQua;
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
    
    double c;
    std::cout << "Nhap so thuc c de nhan: ";
    std::cin >> c;

    std::vector<std::vector<double>> ketQua = nhanVoHuong(A, c);
    std::cout << "\nKet qua cua c * A:" << std::endl;
    xuatMaTran(ketQua);

    return 0;
}