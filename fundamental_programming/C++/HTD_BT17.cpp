#include <iostream>
#include <cmath> // Dùng cái này để tính x^n cho nhanh
using namespace std;

// Tính giá trị của f(x) = a * x^n
double f(double a, double x, double n) {
    return a * pow(x, n);
}

// Tính đạo hàm bậc 1: f'(x) = n * a * x^(n-1)
double DF(double a, double x, double n) {
    double dao_ham_1 = n * a * pow(x, n - 1);
    return dao_ham_1;
}

// Tính đạo hàm bậc 2: f''(x) = n * (n-1) * a * x^(n-2)
double D2F(double a, double x, double n) {
    double dao_ham_2 = n * (n - 1) * a * pow(x, n - 2);
    return dao_ham_2;
}