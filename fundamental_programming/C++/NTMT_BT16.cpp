#include <iostream>
#include <cmath>
using namespace std;
double a, b, c;
double f(double x);
double F(double alpha, unsigned n);

main() {
    cin >> a >> b >> c;
    double alpha; cin >> alpha;
    unsigned n; cin >> n;
    cout << F(alpha, n) << endl;
}

double f(double x) {
    return a * pow(x, 2) + b * x + c;
}

double F(double alpha, unsigned n) {
    if (n == 0) return alpha;
    return f(F(alpha, n - 1));
}