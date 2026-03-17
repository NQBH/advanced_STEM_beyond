#include <iostream>
using namespace std;

// Hàm này để tính công thức f(x) = ax^2 + bx + c
double f(double a, double b, double c, double x) {
    double ket_qua = a * x * x + b * x + c;
    return ket_qua;
}

// Hàm F để tìm ra số hạng a_n
double F(int n, double alpha, double a, double b, double c) {
    // Bắt đầu với số hạng đầu tiên là a_0 = alpha
    double so_hang_dang_xet = alpha; 
    
    // Mình sẽ lặp n lần để "nhảy" từ a_0 lên đến a_n
    for (int i = 0; i < n; i++) {
        so_hang_dang_xet = f(a, b, c, so_hang_dang_xet);
    }
    
    return so_hang_dang_xet;
}