#include <iostream>
#include <cmath> 

using namespace std;

double f(double a, double x, double n) {
    return a * pow(x, n);
}

double Df(double a, double x, double n) {
    return n * a * pow(x, n - 1);
}

double D2f(double a, double x, double n) {
    return n * (n - 1) * a * pow(x, n - 2);
}

int main() {
    double a, x, n;

    cout << "--- Tinh gia tri va dao ham cua f(x) = a * x^n ---" << endl;
    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap so mu n: ";
    cin >> n;
    cout << "Nhap gia tri x can tinh: ";
    cin >> x;

    cout << "Gia tri f(" << x << ") = " << f(a, x, n) << endl;
    cout << "Dao ham bac 1 Df(" << x << ") = " << Df(a, x, n) << endl;
    cout << "Dao ham bac 2 D2f(" << x << ") = " << D2f(a, x, n) << endl;

    return 0;
}
