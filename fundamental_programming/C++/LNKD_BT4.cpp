#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x = 4.0;
    double y = 2.0;

    cout << "x = " << x << ", y = " << y << endl;
    cout << "sqrt(x) = " << sqrt(x) << endl;
    cout << "pow(x, y) = " << pow(x, y) << endl;
    cout << "exp(x) = " << exp(x) << endl;
    cout << "log(x) = " << log(x) << endl;
    cout << "log10(x) = " << log10(x) << endl;
    int a = -10;
    long b = -100;
    double c = -3.14;
    cout << "abs(a) = " << abs(a) << endl;
    cout << "labs(b) = " << labs(b) << endl;
    cout << "fabs(c) = " << fabs(c) << endl;
    double angle = 0.5;
    cout << "cos(angle) = " << cos(angle) << endl;
    cout << "sin(angle) = " << sin(angle) << endl;
    cout << "tan(angle) = " << tan(angle) << endl;
    cout << "acos(0.5) = " << acos(0.5) << endl;
    cout << "asin(0.5) = " << asin(0.5) << endl;
    cout << "atan(1) = " << atan(1) << endl;
    double z = 3.7;
    cout << "floor(z) = " << floor(z) << endl;
    cout << "ceil(z) = " << ceil(z) << endl;
    return 0;
}