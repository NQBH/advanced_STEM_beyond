#include<iostream>
#include<cmath>
using namespace std;
int main() {
    double kq = 0;
    int m, n;

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
    while (cin.fail() || m < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai m (m >= 0, chi nhap so): ";
        cin >> m;
    }

    for (int i = 1; i <= n; i++) {
        kq += pow(i, m);
    }

    cout << "ket qua: " << kq;

}