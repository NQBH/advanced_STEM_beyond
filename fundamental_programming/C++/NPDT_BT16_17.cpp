#include <iostream>
#include <cmath>
using namespace std;

// ================= BT16 =================

double f(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

double an(int n, double alpha, double a, double b, double c) {
    for (int i = 0; i < n; i++)
    {
        alpha = f(a, b, c, alpha);
    }

    return alpha;
}

// ================= BT17 =================

// f(x)
double fx(double a, double x, int n) {
    return a * pow(x, n);
}

// f'(x)
double df(double a, double x, int n) {
    return n * a * pow(x, n - 1);
}

// f''(x)
double d2f(double a, double x, int n) {
    return n * (n - 1) * a * pow(x, n - 2);
}

int main() {
    // ===== BT16 =====
    double a, b, c, alpha;
    int n;

    cout << "BT16\n";
    cout << "Nhap a b c: ";
    cin >> a >> b >> c;

    cout << "Nhap alpha: ";
    cin >> alpha;

    cout << "Nhap n: ";
    cin >> n;

    double result = an(n, alpha, a, b, c);

    cout << "a_" << n << " = " << result << endl;

    // ===== BT17 =====
    double x;

    cout << "\nBT17\n";
    cout << "Nhap a x n: ";
    cin >> a >> x >> n;

    cout << "f(x) = " << fx(a, x, n) << endl;
    cout << "f'(x) = " << df(a, x, n) << endl;
    cout << "f''(x) = " << d2f(a, x, n) << endl;
}