#include<iostream>
#include<cmath>
using namespace std;
void f(double a, double x, double n) {
    double fx = a * pow(x, n);
    cout << "f(x) = " << fx << endl;
}
void Df (double a, double x, double n) {
    double df = n * a * pow(x, n - 1);
    cout << "f'(x) = " << df << endl;
}
void D2f (double a, double x, double n) {
    double d2f = n * (n - 1) * a * pow (x, n - 2);
    cout << "f''(x) = " << d2f << endl;
}
int main() {
    double a, x, n;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap n: ";
    cin >> n;
    f(a, x, n);
    Df(a, x, n);
    D2f(a, x, n);
    return 0;
}