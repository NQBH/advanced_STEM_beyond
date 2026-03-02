#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double x, y;
    cin >> x >> y;
    if (x < 0) {
        cout << "X must be nonnegative";
    }
    else cout << sqrt(x) << endl;
    cout << pow(x, y) << endl;
    cout << exp(x) << endl;
    cout << log(x) << endl;
    cout << log10(x) << endl;
    cout << "int=" << abs(x) << endl;
    cout << "long=" << long(x) << endl;
    cout << "double=" << fabs(x) << endl;
    cout << cos(x) << endl;
    cout << sin(x) << endl;
    cout << tan(x) << endl;
    cout << acos(x) << endl;
    cout << asin(x) << endl;
    cout << atan(x) << endl;
    cout << floor(x) << endl;
    cout << ceil(x) << endl;
    return 0;
}
