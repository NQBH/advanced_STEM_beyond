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
    
    cout << "Nhap gia tri a: ";
    cin >> a;
    cout << "Nhap gia tri x: ";
    cin >> x;
    cout << "Nhap bac n: ";
    cin >> n;
    cout <<"Ket qua";
    cout << "f(x) = " << f(a, x, n) << endl;
    cout << "f'(x) = " << Df(a, x, n) << endl;
    cout << "f''(x) = " << D2f(a, x, n) << endl;
    
    return 0;
}