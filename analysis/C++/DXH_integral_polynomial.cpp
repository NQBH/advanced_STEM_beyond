#include <bits/stdc++.h>
using namespace std;

// nhap da thuc, he so, can phan tich
void nhapDaThuc(int &n, vector<double> &a, double &x0, double &x1) {
    cout << "Nhap bac da thuc (n): ";
    cin >> n;
    a.resize(n + 1);

    cout << "Nhap cac he so a_i tu i = 0 den i = " << n << ":\n";
    for (int i = 0; i <= n; ++i) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    cout << "Nhap can duoi x0: ";
    cin >> x0;
    cout << "Nhap can tren x1: ";
    cin >> x1;
}

// in lai da thuc
void inDaThuc(int n, const vector<double> &a) {
    cout << "Da thuc P(x) = ";
    for (int i = 0; i <= n; ++i) {
        if (i > 0 && a[i] >= 0) cout << "+";
        cout << a[i];
        if (i >= 1) cout << "*x^" << i << " ";
    }
    cout << endl;
}

// tinh tich phan
void tinhTichPhan(int n, const vector<double> &a, double x0, double x1, double &result) {
    result = 0;
    for (int i = 0; i <= n; ++i) {
        double term = (a[i] / (i + 1)) * (pow(x1, i + 1) - pow(x0, i + 1)); // // cttp a_i * x^i là (a_i / (i+1)) * x^(i+1)
        result += term;
    }
}

// in ra ket qua
void inKetQua(double result) {
    cout << fixed << setprecision(10);
    cout << "Gia tri tich phan cua da thuc tu x0 den x1 la: " << result << endl;
}

int main() {
    int n;
    vector<double> a;
    double x0, x1, result;

    nhapDaThuc(n, a, x0, x1);
    inDaThuc(n, a);
    tinhTichPhan(n, a, x0, x1, result);
    inKetQua(result);

    return 0;
}