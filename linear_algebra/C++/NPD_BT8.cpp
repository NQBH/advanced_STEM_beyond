#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    int A[n][n], B[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0; // ma tran 0
            if (i == j) {
                B[i][j] = 1; // ma tran don vi
            } else {
                B[i][j] = 0;
            }
        }
    }

    cout << "\nMa tran 0 " << n << "x" << n << " la: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMa tran don vi " << n << "x" << n << " la: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
}