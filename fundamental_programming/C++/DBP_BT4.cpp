#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double x, y;
    cin >> x;
    if (x < 0) cout << "x must be nonnegative";
    else cout << sqrt(x) << '\n';

    cin >> x >> y;
    if (x < 0) cout << " x must be nonnegative";
    else cout << pow(x, y) << '\n';

    cin >> x;
    if (x < 0) cout << "x must be nonnegative";
    else cout << exp(x) << '\n';

    cin >> x;
    if (x <= 0) cout << " x must be positive";
    else cout << log(x) << '\n';

    cin >> x;
    if (x <= 0) cout << "x must be positive";
    else cout << log10(x) << '\n';
    int a;
    long b;
    cin >> a;
    cout << abs(a) << '\n';
    cin >> b;
    cout << labs(b) << '\n';
    cin >> x;
    cout << fabs(x) << '\n';
    cin >> x;
    cout << cos(x) << '\n';
    cin >> x;
    cout << sin(x) << '\n';
    cin >> x;
    cout << tan(x) << '\n';
    cin >> x;
    if (x < -1 || x > 1)
        cout << "x must be in [-1,1]\n";
    else
        cout << asin(x) << '\n';
    cin >> x;
    if (x < -1 || x > 1)
        cout << "x must be in [-1,1]\n";
    else
        cout << acos(x) << '\n';
    cin >> x;
    cout << atan(x) << '\n';
    cin >> x;
    cout << floor(x) << '\n';
    cin >> x;
    cout << ceil(x) << '\n';
}