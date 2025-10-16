#include <iostream>
#include <vector>
#include <iomanip> 

void inMaTran(const std::vector<std::vector<double>>& A) {
    for (const auto& hang : A) {
        for (double phanTu : hang) {
            std::cout << std::setw(8) << phanTu;
        }
        std::cout << std::endl;
    }
}

void hoanViHaiDong(std::vector<std::vector<double>>& A, int r1, int r2) {
    std::swap(A[r1], A[r2]);
}

void nhanDongVoiMotSo(std::vector<std::vector<double>>& A, int r, double c) {
    for (size_t j = 0; j < A[r].size(); ++j) {
        A[r][j] *= c;
    }
}

void congMotDongVaoDongKhac(std::vector<std::vector<double>>& A, int r1, int r2, double c) {
    for (size_t j = 0; j < A[r1].size(); ++j) {
        A[r1][j] += c * A[r2][j];
    }
}


int main() {
    std::vector<std::vector<double>> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    std::cout << "Ma tran ban dau:" << std::endl;
    inMaTran(A);

    std::cout << "\n1. Hoan vi dong 0 or 2..." << std::endl;
    hoanViHaiDong(A, 0, 2);
    std::cout << " sau khi hoan vi ra " << std::endl;
    inMaTran(A);

    std::cout << "\n2. Nhan dong 1 or 2 " << std::endl;
    nhanDongVoiMotSo(A, 1, 2);
    std::cout << "Ma tran sau khi xong " << std::endl;
    inMaTran(A);

    std::cout << "\n3. Lay dong 2 + (-3)*dong 0" << std::endl;
    congMotDongVaoDongKhac(A, 2, 0, -3);
    std::cout << "ket qua cuoi: " << std::endl;
    inMaTran(A);

    return 0;
}