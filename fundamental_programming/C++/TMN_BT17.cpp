#include <iostream>
#include <cmath>
using namespace std;

double f(double a, double x, double n) {
    return a * pow(x, n);
}

void DF(double a, double x, double n) {
    double f1 = n * a * pow(x, n - 1);
    double f2 = n * (n - 1) * a * pow(x, n - 2);

    cout << "f'(x) = " << f1 << endl;
    cout << "f''(x) = " << f2 << endl;
}

int main() {
    double a, x, n;

    cin >> a >> x >> n;

    cout << "f(x) = " << f(a, x, n) << endl;

    DF(a, x, n);

    return 0;
}