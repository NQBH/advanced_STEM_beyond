#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x;
    cout << "Nhap x = ";
    cin >> x;

    if (x >= 0)
        cout << "sqrt(x) = " << sqrt(x) << endl;
    else
        cout << "sqrt(x): x must be nonnegative\n";
    cout << "pow(x, 2) = " << pow(x, 2) << endl;
    cout << "exp(x) = " << exp(x) << endl;
    if (x > 0) {
        cout << "log(x) = " << log(x) << endl;
        cout << "log10(x) = " << log10(x) << endl;
    } else {
        cout << "log(x), log10(x): x must be nonnegative\n";
    }
    cout << "fabs(x) = " << fabs(x) << endl;
    cout << "abs((int)x) = " << abs((int)x) << endl;
    cout << "labs((long)x) = " << labs((long)x) << endl;
    cout << "sin(x) = " << sin(x) << endl;
    cout << "cos(x) = " << cos(x) << endl;
    cout << "tan(x) = " << tan(x) << endl;
    if (fabs(x) <= 1) {
        cout << "asin(x) = " << asin(x) << endl;
        cout << "acos(x) = " << acos(x) << endl;
    } else {
        cout << "asin(x), acos(x): |x| must be <= 1\n";
    }
    cout << "atan(x) = " << atan(x) << endl;
    cout << "floor(x) = " << floor(x) << endl;
    cout << "ceil(x) = " << ceil(x) << endl;

    return 0;
}