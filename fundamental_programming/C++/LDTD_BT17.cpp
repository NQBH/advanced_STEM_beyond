#include <iostream>
#include <cmath>

using namespace std;

// Hàm tính f(x) = ax^n
double f(double a, double x, double n) {
    return a * pow(x, n);
}

// Hàm tính đạo hàm bậc nhất f'(x) = n*a*x^(n-1)
double Df(double a, double x, double n) {
    if (n == 0) return 0; 
    return n * a * pow(x, n - 1);
}

// Hàm tính đạo hàm bậc hai f''(x) = n*(n-1)*a*x^(n-2)
double D2f(double a, double x, double n) {
    if (n < 2) return 0;
    return n * (n - 1) * a * pow(x, n - 2);
}

int main() {
    double a, x, n;
    
    cout << "Nhap a, x, n: ";
    cin >> a >> x >> n;
    
    cout << "f(x)  = " << f(a, x, n) << endl;
    cout << "f'(x) = " << Df(a, x, n) << endl;
    cout << "f''(x)= " << D2f(a, x, n) << endl;
    
    return 0;
}