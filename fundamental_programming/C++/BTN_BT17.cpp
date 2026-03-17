#include <iostream>
using namespace std;
void print_hello(int a) {
    cout << "Hello world from student " << a << '\n';
}
void hcn(long long a, long long b) {
    cout << "Chu vi: " << 2 * (a + b) << " | Dien tich: " << a * b << '\n';
}
long long f_double(int x) {
    return 2LL * x; 
}
double abs_function(double x) {
    if (x >= 0) return x;
    else return -x;
}
long long f_complex(int& x, int& y) {
    long long res = 2LL * x + 3LL * y;
    x *= 2;
    y *= 5;
    return res;
}

int main() {
    long long chieu_dai = 5, chieu_rong = 4;
    hcn(chieu_dai, chieu_rong);
    cout << "Nhan doi 2 ty: " << f_double(2000000000) << '\n';
    int val = -5;
    cout << "Tri tuyet doi cua f_double(5): " << abs_function(f_double(5)) << '\n';
    int x = 3, y = 4;
    cout << "Ket qua f_complex(3, 4): " << f_complex(x, y) << '\n';
    cout << "Debug: x sau khi goi ham = " << x << " (3*2), y = " << y << " (4*5)\n";

    return 0;
}