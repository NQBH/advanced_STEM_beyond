#include <iostream>
#include <vector>

using namespace std;

void xuatmatran(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;

    do {
        cout << "Nhap so dong va cot (n > 0): ";
        cin >> n;
        if (n <= 0) {
            cout << "Vui long nhap lai!" << endl;
        }
        } while (n <= 0);
        vector<vector<int>> matrankhong(n, vector<int>(n, 0));
        vector<vector<int>> matrixdonvi(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            matrixdonvi[i][i] = 1;
        }

        cout << "Ma tran khong  :" << n << "x" << n << ":" << n << endl;
        xuatmatran(matrankhong);
        cout << "Ma tran don vi :" << n << "x" << n << ":" << n << endl;
        xuatmatran(matrixdonvi);
        
        return 0;
}