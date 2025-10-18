#include <iostream>

int main() {
    int n;
    int mTran[50][50];

    std::cout << "Nhap kthuoc mtran: ";
    std::cin >> n;

    std::cout << "Nhap cac ptu cho mtran:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "Phan tu a[" << i << "][" << j << "]: ";
            std::cin >> mTran[i][j];
        }
    }

    std::cout << "\n kqa ktra \n";

    bool ma_tran_cheo = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && mTran[i][j] != 0) {
                ma_tran_cheo = false;
                break;
            }
        }
        if (!ma_tran_cheo) {
            break;
        }
    }
    if (ma_tran_cheo) {
        std::cout << "-  mtran cheo.\n";
    } else {
        std::cout << "- Khong phai mtran cheo.\n";
    }

    bool tam_giac_tren = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > j && mTran[i][j] != 0) {
                tam_giac_tren = false;
                break;
            }
        }
        if (!tam_giac_tren) {
            break;
        }
    }
    if (tam_giac_tren) {
        std::cout << "-  mtran tam giac tren.\n";
    } else {
        std::cout << "- Khong phai mtran tam giac tren.\n";
    }

    bool tam_giac_duoi = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i < j && mTran[i][j] != 0) {
                tam_giac_duoi = false;
                break;
            }
        }
        if (!tam_giac_duoi) {
            break;
        }
    }
    if (tam_giac_duoi) {
        std::cout << "- mtran tam giac duoi.\n";
    } else {
        std::cout << "- Khong phai mtran tam giac duoi.\n";
    }

    bool mtran_doi_xung = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mTran[i][j] != mTran[j][i]) {
                mtran_doi_xung = false;
                break;
            }
        }
        if (!mtran_doi_xung) {
            break;
        }
    }
    if (mtran_doi_xung) {
        std::cout << "- mtran doi xung.\n";
    } else {
        std::cout << "- Khong phai mtran doi xung.\n";
    }

    return 0;
}