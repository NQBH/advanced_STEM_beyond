#include <iostream>
#include <cmath>

using namespace std;

// --- BÀI TẬP 16 ---
double f_bt16(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

double F(int n, double alpha, double a, double b, double c) {
    double current_a = alpha;
    for (int i = 1; i <= n; i++) {
        current_a = f_bt16(a, b, c, current_a);
    }
    return current_a;
}

// --- BÀI TẬP 17 ---
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
    cout << "--- KET QUA BT16 ---" << endl;
    double a = 1.0, b = 1, c = 1.0;
    int n = 2; 
    double alpha = 1.0;
    cout << "Gia tri a_" << n << " la: " << F(n, alpha, a, b, c) << endl;

    cout << "\n--- KET QUA BT17 ---" << endl;
    double a17 = 2.0, x17 = 3.0, n17 = 3.0;
    cout << "f(x)   = " << f(a17, x17, n17) << endl;
    cout << "f'(x)  = " << Df(a17, x17, n17) << endl;
    cout << "f''(x) = " << D2f(a17, x17, n17) << endl;

    return 0;
}