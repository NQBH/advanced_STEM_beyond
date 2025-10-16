#include <iostream>
#include <vector>
using namespace std;

void inMaTran(const vector<vector<double>>& A) {
    for (auto row : A) {
        for (auto val : row)
            cout << val << " ";
        cout << "\n";
    }
}

int main() {
    int m, n;
    cout << "Nhập số dòng và cột của ma trận A: ";
    cin >> m >> n;

    vector<vector<double>> A(m, vector<double>(n));
    cout << "Nhập ma trận A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    int choice;
    cout << "\n--- MENU ---\n";
    cout << "1. Hoán vị hai dòng\n";
    cout << "2. Nhân một dòng với hằng khác 0\n";
    cout << "3. Cộng một dòng với bội của dòng khác\n";
    cout << "Chọn phép biến đổi (1-3): ";
    cin >> choice;

    if (choice == 1) {
        int i, j;
        cout << "Nhập hai dòng cần hoán vị (bắt đầu từ 1): ";
        cin >> i >> j;
        swap(A[i-1], A[j-1]);
    } 
    else if (choice == 2) {
        int i;
        double k;
        cout << "Nhập dòng cần nhân và hệ số k (k ≠ 0): ";
        cin >> i >> k;
        if (k == 0) {
            cout << "k phải khác 0!\n";
            return 0;
        }
        for (int c = 0; c < n; c++)
            A[i-1][c] *= k;
    } 
    else if (choice == 3) {
        int i, j;
        double k;
        cout << "Nhập dòng cần biến đổi (i), dòng dùng để cộng (j), và hệ số k: ";
        cin >> i >> j >> k;
        for (int c = 0; c < n; c++)
            A[i-1][c] += k * A[j-1][c];
    } 
    else {
        cout << "Lựa chọn không hợp lệ!\n";
        return 0;
    }

    cout << "\nMa trận sau biến đổi:\n";
    inMaTran(A);

    return 0;
}