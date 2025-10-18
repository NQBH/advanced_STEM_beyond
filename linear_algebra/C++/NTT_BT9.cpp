#include <iostream>
#include <vector>

using namespace std;


bool matrancheo(const vector<vector<int>>& a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && a[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}


bool matrantren(const vector<vector<int>>& a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}


bool matranduoi(const vector<vector<int>>& a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool matrandoixung(const vector<vector<int>>& a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][j] != a[j][i]) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    int n;
    cout << " Nhap kich thuoc ma tran (n x n): " << endl;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << " Nhap cac phan tu cua ma tran: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << " \n--- KET QUA --- " << endl;
    cout << " 1. Kiem tra ma tran co phai la ma tran cheo " << (matrancheo(matrix, n) ? "YES" : "NO") << endl;
    cout << " 2. Kiem tra ma tran co phai la ma tran tren " << (matrantren(matrix, n) ? "YES" : "NO") << endl;
    cout << " 3. Kiem tra ma tran co phai la ma tran duoi " << (matranduoi(matrix, n) ? "YES" : "NO") << endl;
    cout << " 4. Kiem tra ma tran co phai la ma tran doi xung " << (matrandoixung(matrix, n) ? "YES" : "NO") << endl;

    return 0;
}
 