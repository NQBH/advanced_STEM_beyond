#include <iostream>
using namespace std;

const int MAX = 100;

void nhan_2(double A[][MAX], double B[][MAX], double C[][MAX], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void xuat(double C[][MAX], int m, int n) {
    cout << "A x B = " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    double A[MAX][MAX] = {{1, 2, 3}, {4, 5, 6}};
    double B[MAX][MAX] = {{1, 2}, {3, 4}, {5, 6}};
    double C[MAX][MAX];

    int m = 2;
    int n = 3;
    int p = 2;

    nhan_2(A, B, C, m, n, p);
    xuat(C, m, p);

    return 0;
}
