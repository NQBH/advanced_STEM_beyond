#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Nhập cặp ma trận vương n: ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    cout << "Nhập ma trận:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    bool isDiagonal = true, isUpper = true, isLower = true, isSymmetric = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i != j && A[i][j] != 0) isDiagonal = false;
            if (i > j && A[i][j] != 0) isUpper = false;
            if (i < j && A[i][j] != 0) isLower = false;
            if (A[i][j] != A[j][i]) isSymmetric = false;
        }
    }

    cout << "\nKết quả kiểm tra:\n";
    cout << "Ma trận đường chéo: " << (isDiagonal ? "Đúng" : "Sai") << endl;
    cout << "Ma trận tam giác trên: " << (isUpper ? "Đúng" : "Sai") << endl;
    cout << "Ma trận tam giác dưới: " << (isLower ? "Đúng" : "Sai") << endl;
    cout << "Ma trận đối xứng: " << (isSymmetric ? "Đúng" : "Sai") << endl;

    return 0;
}