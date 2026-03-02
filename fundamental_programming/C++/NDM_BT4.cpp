#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y;
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;

    if (x < 0) cout << "sqrt ERROR: x must be nonnegative" << endl;
    else cout << "sqrt(x) = " << sqrt(x) << endl;

    cout << "pow = " << pow(x, y) << endl;
    cout << "e^x = " << exp(x) << endl;

    if (x <= 0) cout << "log ERROR: x must be > 0" << endl;
    else {
        cout << "ln x = " << log(x) << endl;
        cout << "log10 x = " << log10(x) << endl;
    }

    cout << "abs x = " << abs(x) << endl;
    cout << "fabs x = " << fabs(x) << endl;
    cout << "cos x = " << cos(x) << endl;
    cout << "tan x = " << tan(x) << endl;
    cout << "sin x = " << sin(x) << endl;

    if (x < -1 || x > 1) cout << "acos, asin ERROR: x must be in [-1, 1]" << endl;
    else {
        cout << "acos x = " << acos(x) << endl;
        cout << "asin x = " << asin(x) << endl;
    }

    cout << "atan x = " << atan(x) << endl;
    cout << "floor x = " << floor(x) << endl;
    cout << "ceil x = " << ceil(x) << endl;

    return 0;
}