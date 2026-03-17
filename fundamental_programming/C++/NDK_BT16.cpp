#include <iostream>
#include <cmath>
using namespace std;
double f(double a, double b, double c, double x) {
    return a * pow(x, 2) + b * x + c;
}
double F(int n, double alpha, double a, double b, double c) {
    double a_n = alpha;
    for (int i = 0; i < n; ++i) {
        a_n = f(a, b, c, a_n);
    }
    return a_n;
}

int main() {
    double a, b, c, alpha;
    int n;
    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap he so b: ";
    cin >> b;
    cout << "Nhap he so c: ";
    cin >> c;
    cout << "Nhap gia tri ban dau alpha (a0): ";
    cin >> alpha;
    cout << "Nhap so lan lap n: ";
    cin >> n;
    cout << "KET QUA:" << endl;
    cout << "Gia tri a_" << n << " la: " << F(n, alpha, a, b, c) << endl;

    return 0;
}