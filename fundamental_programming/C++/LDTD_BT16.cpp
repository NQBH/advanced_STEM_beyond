#include <iostream>
#include <cmath>

using namespace std;

// Hàm f(x) = ax^2 + bx + c
double f(double x, double a, double b, double c) {
    return a * x * x + b * x + c;
}

// Hàm F để tính giá trị a_n
double F(int n, double alpha, double a, double b, double c) {
    double current_a = alpha; // Đây là a_0
    for (int i = 1; i <= n; i++) {
        current_a = f(current_a, a, b, c);
    }
    return current_a;
}

int main() {
    double alpha, a, b, c;
    int n;
    
    cout << "Nhap n, alpha, a, b, c: ";
    cin >> n >> alpha >> a >> b >> c;
    
    cout << "Gia tri a_" << n << " la: " << F(n, alpha, a, b, c) << endl;
    
    return 0;
}