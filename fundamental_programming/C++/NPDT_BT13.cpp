#include<iostream>
#include<cmath>
using namespace std;
int main() {
    double kq = 0;
    int m, n, M, i = 1;

    cout << "nhap n: ";
    cin >> n;
    while (cin.fail() || n <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai n (n > 0, chi nhap so): ";
        cin >> n;
    }

    cout << "nhap m: ";
    cin >> m;
    while (cin.fail() || m <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai m (m > 0, chi nhap so): ";
        cin >> m;
    }

    cout << "nhap M: ";
    cin >> M;
    while (cin.fail() || M <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai M (M > 0, chi nhap so): ";
        cin >> M;
    }

    while (i <= n) {
        if (kq + pow(i, m) <= M) {
            kq += pow(i, m);
        } else break;
        i += 1;
    }

    cout << "ket qua: " << kq;

}