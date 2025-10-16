#include <iostream>
#include <vector>
using namespace std;

void mt(const vector<vector<int>>& matrix);

int main() {
    int dong, cot;
    cout << "Nhập số dòng của ma trận: ";
    cin >> dong;
    cout << "Nhập số cột của ma trận: ";
    cin >> cot;

    vector<vector<int>> A(dong, vector<int>(cot));
    cout << "Nhập các phần tử cho ma trận:" << endl;
    for (int i = 0; i < dong; ++i) {
        for (int j = 0; j < cot; ++j) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    cout << "\nMa trận đã nhập" << endl;
    mt(A);

    vector<vector<int>> b1 = A;
    if (dong >= 2) {
        swap(b1[0], b1[1]);
    }
    cout << "\nHoán vị dòng 0 và 1" << endl;
    mt(b1);

    vector<vector<int>> b2 = A;
    float k = 3.0;
    if (dong >= 1) {
        for (int j = 0; j < cot; ++j) {
            b2[0][j] *= k;
        }
    }
    cout << "\nNhân dòng 0 với " << k << endl;
    mt(b2);

    vector<vector<int>> b3 = A;
    int h = 2.0f;
    if (dong >= 2) {
        for (int j = 0; j < cot; ++j) {
            b3[1][j] += h * b3[0][j];
        }
    }
    cout << "\nDòng 1 cộng với dòng 0 nhân " << h << endl;
    mt(b3);

    return 0;
}

void mt(const vector<vector<int>>& matrix) { //hàm lấy ma trận
    int dong = matrix.size();
    int cot = matrix[0].size();
    for (int i = 0; i < dong; ++i) {
        for (int j = 0; j < cot; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
