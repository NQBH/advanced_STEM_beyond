#include <iostream>
using namespace std;

int main() {
    double A[2][2];
    cout << "Nhap gia tri cho ma tran A (2x2):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
    cout << "\nMa tran A:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    double det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    cout << "\n Det A = " << det << endl;
    return 0;
}