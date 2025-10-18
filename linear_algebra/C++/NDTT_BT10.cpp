#include <iostream>
using namespace std;

int main() {

    double a[2][2];

    cout << "nhap phan tu trong ma tran a:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }
    cout << "det(a)\n";
    double A = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    cout << A;
}
