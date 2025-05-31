#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

double evaluatePolynomial(const vector<double>& coeffs, double x) {
    double result = 0;
    for (int i = 0; i < coeffs.size(); ++i) {
        result += coeffs[i] * pow(x, i);
    }
    return result;
}

int degree(const vector<double>& coeffs) {
    for (int i = coeffs.size() - 1; i >= 0; --i) {
        if (fabs(coeffs[i]) > 1e-9) return i;
    }
    return 0;
}

int main() {
    string x0_str;
    double x0;
    int m, n;

    cout << "Nhap x0, Nhap bac cua tu so (m), Nhap bac cua mau so (n):  ";
    cin >> x0_str >> m >> n ;

    vector<double> a(m + 1);
    cout << "Nhap he so a0, a1, ..., am: ";
    for (int i = 0; i <= m; ++i) cin >> a[i];

    vector<double> b(n + 1);
    cout << "Nhap he so b0, b1, ..., bn: ";
    for (int i = 0; i <= n; ++i) cin >> b[i];

    bool is_inf = false;
    if (x0_str == "inf") {
        x0 = numeric_limits<double>::infinity();
        is_inf = true;
    } else if (x0_str == "-inf") {
        x0 = -numeric_limits<double>::infinity();
        is_inf = true;
    } else {
        x0 = stod(x0_str);
    }

    if (is_inf) {
        int deg_num = degree(a);
        int deg_den = degree(b);
        double leading_num = a[deg_num];
        double leading_den = b[deg_den];

        if (deg_num > deg_den) {
            cout << (leading_num * leading_den > 0 ? "inf" : "-inf") << endl;
        } else if (deg_num == deg_den) {
            cout << (leading_num / leading_den) << endl;
        } else {
            cout << 0 << endl;
        }
    } else {
        double num = evaluatePolynomial(a, x0);
        double den = evaluatePolynomial(b, x0);

        cout << "P(x0) = " << num << ", Q(x0) = " << den << endl;

        if (fabs(den) < 1e-9) {
            if (fabs(num) < 1e-9)
                cout << "0/0 (vo dinh)" << endl;
            else
                cout << "Khong xac dinh (mau tien ve 0)." << endl;
        } else {
            cout << "Gia tri gan dung cua gioi han = " << num / den << endl;
        }
    }

    return 0;
}