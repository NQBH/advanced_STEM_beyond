#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y;
    cin >> x >> y;
    if (x >= 0) {
        // sqrt
        cout << "sqrt = " << sqrt(x) << '\n';
        // pow
        cout << "pow = " << pow(x, y) << '\n';
        // exp
        cout << "exp = " << exp(x) << '\n';
        // log
        cout << "log = " << log(x) << '\n';
        // log10
        cout << "log10 = " << log10(x) << '\n';
        // int
        int absX = abs(x);
        cout << "abs(int x) = " << absX << '\n';
        // long
        long labsX = labs(x);
        cout << "labs(int x) = " << labsX << '\n';
        // double
        double fabsX = fabs(x);
        cout << "fabs(int x) = " << fabsX << '\n';
        // sin
        cout << "sin = " << sin(x) << '\n';
        // cos
        cout << "cos = " << cos(x) << '\n';
        // tan
        cout << "tan = " << tan(x) << '\n';
        // asin
        cout << "asin = " << asin(x) << '\n';
        // acos
        cout << "acos = " << acos(x) << '\n';
        // atan
        cout << "atan = " << atan(x) << '\n';
        // floor
        cout << "floor = " << floor(x) << '\n';
        // ceil
        cout << "ceil = " << ceil(x) << '\n';
    } else {
        // sqrt
        cout << "sqrt = nonnegative" << '\n';
        // pow
        cout << "pow = " << pow(x, y) << '\n';
        // exp
        cout << "exp = " << exp(x) << '\n';
        // log
        cout << "log = nonnegative" << '\n';
        // log10
        cout << "log10 = nonnegative" << '\n';
        // int
        int absX = abs(x);
        cout << "abs(int x) = " << absX << '\n';
        // long
        long labsX = labs(x);
        cout << "labs(int x) = " << labsX << '\n';
        // double
        double fabsX = fabs(x);
        cout << "fabs(int x) = " << fabsX << '\n';
        // sin
        cout << "sin = " << sin(x) << '\n';
        // cos
        cout << "cos = " << cos(x) << '\n';
        // tan
        cout << "tan = " << tan(x) << '\n';
        // asin
        cout << "asin = nonnegative" << '\n';
        // acos
        cout << "acos = nonnegative" << '\n';
        // atan
        cout << "atan = " << atan(x) << '\n';
        // floor
        cout << "floor = " << floor(x) << '\n';
        // ceil
        cout << "ceil = " << ceil(x) << '\n';
    }
    return 0;
}