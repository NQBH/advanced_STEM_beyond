#include <iostream>
#include <vector>
#include <iomanip>


void xuatMaTran(const std::vector<std::vector<int>>& maTran) {
    for (const auto& hang : maTran) {
        for (int phanTu : hang) {            
            std::cout << std::setw(4) << phanTu;
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Nhap kich thuoc n cho ma tran vuong: ";
    std::cin >> n;

   
    if (n <= 0) {
        std::cout << "Kich thuoc n phai la mot so nguyen duong." << std::endl;
        return 1; // Kết thúc chương trình nếu n không hợp lệ
    }

   
    std::vector<std::vector<int>> maTranKhong(n, std::vector<int>(n, 0));
    
    std::cout << "\nMa tran khong (Zero Matrix) cap " << n << ":" << std::endl;
    xuatMaTran(maTranKhong);

    
    std::vector<std::vector<int>> maTranDonVi(n, std::vector<int>(n, 0));
    
    
    for (int i = 0; i < n; ++i) {
        maTranDonVi[i][i] = 1; 
    }

    std::cout << "\nMa tran don vi (Identity Matrix) cap " << n << ":" << std::endl;
    xuatMaTran(maTranDonVi);

    return 0;
}