#include <iostream>
#include <vector>
using namespace std;

void kq(const vector<vector<int>>& A, const vector<int>& b);

int main() {
    int donga, cota; // dòng a cột a
    cout << "Nhập số dòng của ma trận A: ";
    cin >> donga;
    cout << "Nhập số cột của ma trận A: ";
    cin >> cota;

    vector<vector<int>> A(donga, vector<int>(cota));

    cout << "Nhập các phần tử cho ma trận A:" << endl;
    for (int i = 0; i < donga; ++i) {
        for (int j = 0; j < cota; ++j) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    int ptub; //số phần tử b
    cout << "\nNhập số phần tử của vector b: ";
    cin >> ptub;

    vector<int> b(ptub);

    cout << "Nhập các phần tử cho vector b:" << endl;
    for (int i = 0; i < ptub; ++i) {
        cout << "b[" << i << "]: ";
        cin >> b[i];
    }

    if (A.size() != b.size()) {
        cout << "Impossible" << endl;
    } 
    else {
        kq(A, b);
    }

    return 0;
}

void kq(const vector<vector<int>>& A, const vector<int>& b) { //lấy kết quả
    int dong = A.size();
    int cot = A[0].size();

    cout << "\n ma trận [A|b]" << endl;
    for (int i = 0; i < dong; ++i) {
        for (int j = 0; j < cot; ++j) {
            cout << A[i][j] << "\t";
        }
        cout << "|\t";
        cout << b[i] << endl;
    }
}
