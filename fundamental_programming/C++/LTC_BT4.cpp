#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    double x = 4.0, y = 2.0;
    double angle = 0.5;   // radian
    int a = -10;
    long b = -100;
    // Can bac hai
    cout << "sqrt(" << x << ") = " << sqrt(x) << endl;
    // Luy thua
    cout << "pow(" << x << ", " << y << ") = " << pow(x, y) << endl;
    // Ham mu
    cout << "exp(" << y << ") = " << exp(y) << endl;
    // Logarit tu nhien
    cout << "log(" << x << ") = " << log(x) << endl;
    // Logarit co so 10
    cout << "log10(" << x << ") = " << log10(x) << endl;
    // Gia tri tuyet doi
    cout << "abs(" << a << ") = " << abs(a) << endl;
    cout << "labs(" << b << ") = " << labs(b) << endl;
    cout << "fabs(-3.14) = " << fabs(-3.14) << endl;
    // Ham luong giac
    cout << "sin(" << angle << ") = " << sin(angle) << endl;
    cout << "cos(" << angle << ") = " << cos(angle) << endl;
    cout << "tan(" << angle << ") = " << tan(angle) << endl;
    cout << "asin(0.5) = " << asin(0.5) << endl;
    cout << "acos(0.5) = " << acos(0.5) << endl;
    cout << "atan(1) = " << atan(1) << endl;
    // Lam tron
    cout << "floor(3.7) = " << floor(3.7) << endl;
    cout << "ceil(3.7) = " << ceil(3.7) << endl;

    return 0;
}
