#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    
    cout << "Nhap kich thuoc N cua ma tran vuong: ";
    cin >> n;

    if (n <= 0) {
        cout << "N phai lon hon 0. Ket thuc.\n";
        return 0;
    }

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Nhap cac phan tu cua ma tran " << n << "x" << n << " (theo thu tu tung hang):\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    bool isDiagonal = true;
    bool isUpperTriangular = true;
    bool isLowerTriangular = true;
    bool isSymmetric = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            
            if (i != j && matrix[i][j] != 0) {
                isDiagonal = false;
            }

            if (i > j && matrix[i][j] != 0) {
                isUpperTriangular = false;
            }

            if (i < j && matrix[i][j] != 0) {
                isLowerTriangular = false;
            }

            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = false;
            }
        }
    }

    cout << "\n--- KET QUA KIEM TRA ---\n";
    cout << "Ma tran Duong cheo? " << (isDiagonal ? "Co" : "Khong") << endl;
    cout << "Ma tran Tam giac Tren? " << (isUpperTriangular ? "Co" : "Khong") << endl;
    cout << "Ma tran Tam giac Duoi? " << (isLowerTriangular ? "Co" : "Khong") << endl;
    cout << "Ma tran Doi xung (A = A^T)? " << (isSymmetric ? "Co" : "Khong") << endl;

    return 0;
}