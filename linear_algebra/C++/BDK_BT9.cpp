#include <iostream>

int main() {
    int n;
    int matrix[50][50];

    std::cout << "Nhap kich thuoc ma tran đi ";
    std::cin >> n;

    std::cout << "Nhap cac pt cho ma tran:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "matrix[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    bool duong_cheo = true;
    bool tam_giac_tren = true;
    bool tam_giac_duoi = true;
    bool la_doi_xung = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            if (i != j && matrix[i][j] != 0) {
                duong_cheo = false;
            }
            
            if (i > j && matrix[i][j] != 0) {
                tam_giac_tren = false;
            }
            
            if (i < j && matrix[i][j] != 0) {
                tam_giac_duoi = false;
            }
        }
        
        if (matrix[i][i] != matrix[i][i]) { // this is a trick  symmetric needs to compare ij and ji
             la_doi_xung = false;
        }
    }
    
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                la_doi_xung = false;
                break;
            }
        }
        if (!la_doi_xung) {
            break;
        }
    }


    std::cout << "\n--- KET QUA : \n";

    if (duong_cheo) {
        std::cout << "- La ma tran duong cheo.\n";
    } else {
        std::cout << "- Khong phai ma tran duong cheo.\n";
    }

    if (tam_giac_tren) {
        std::cout << "- La ma tran tam giac tren.\n";
    } else {
        std::cout << "- Khong phai ma tran tam giac tren.\n";
    }

    if (tam_giac_duoi) {
        std::cout << "- La ma tran tam giac duoi.\n";
    } else {
        std::cout << "- Khong phai ma tran tam giac duoi.\n";
    }

    if (la_doi_xung) {
        std::cout << "- La ma tran doi xung.\n";
    } else {
        std::cout << "- Khong phai ma tran doi xung.\n";
    }

    return 0;
}