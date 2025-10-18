#include <iostream>
#include <vector>
#include <iomanip> 


void nhapMaTran(std::vector<std::vector<double>>& maTran, int soHang, int soCot) {
    std::cout << "Nhap cac phan tu cua ma tran:" << std::endl;
    for (int i = 0; i < soHang; ++i) {
        for (int j = 0; j < soCot; ++j) {
            std::cout << "Nhap phan tu o vi tri [" << i + 1 << "][" << j + 1 << "]: ";
            std::cin >> maTran[i][j];
        }
    }
}


void xuatMaTran(const std::vector<std::vector<double>>& maTran) {
    std::cout << "\nMa tran da nhap la:" << std::endl;
    for (const auto& hang : maTran) {
        for (double phanTu : hang) {
            
            std::cout << std::setw(8) << phanTu;
        }
        std::cout << std::endl;
    }
}

int main() {
    int soHang, soCot;
    std::cout << "Nhap so hang cua ma tran: ";
    std::cin >> soHang;
    std::cout << "Nhap so cot cua ma tran: ";
    std::cin >> soCot;

    
    std::vector<std::vector<double>> A(soHang, std::vector<double>(soCot));

    nhapMaTran(A, soHang, soCot);
    xuatMaTran(A);

    return 0;
}