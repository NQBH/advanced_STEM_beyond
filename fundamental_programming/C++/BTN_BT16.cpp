#include <cmath>
#include <iostream>
using namespace std;
void print_hello(int a) {
    cout << "Hello world from student " << a << '\n';
}
void tong_hieu_tich_thuong(long long a, long long b) {
    cout << a + b << ' ' << a - b << ' ' << a * b << ' ';
    if (b == 0) cout << "divisible by zero\n";
    else cout << a / b << '\n';
}
long long f(int x) {
    return 3LL * x + 5;
}
long long g(int& x, int& y) {
    x *= 2;
    y *= 3;
    return 3LL * x + 5LL * y;
}
double abs_function(double x) {
    if (x >= 0) return x;
    else return -x;
}
double round_custom(double x) {
    if (x >= 0) return floor(x + 0.5);
    else return -floor(-x + 0.5);
}

int main() {
    for (int i = 1; i <= 3; ++i) print_hello(i);
    tong_hieu_tich_thuong(10, 5);
    int x = 2, y = 3;
    cout << "Gia tri ham g(2, 3): " << g(x, y) << '\n';
    cout << "Sau khi goi ham g: x = " << x << ", y = " << y << '\n';
    cout << "Lam tron 3.7: " << round_custom(3.7) << '\n';

    return 0;
}