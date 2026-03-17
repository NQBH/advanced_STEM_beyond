#include <iostream>
#include <cmath>
using namespace std;
double mux(double x, double n) {
    double anx = 1;
    bool an = 0;
    if ( n < 0 ) {
        n = -n; an = 1;

    }
    for ( int i = 1; i <= n ; i++ ) {
        anx *= x;
    }
    if ( an ) {
        return 1 / anx;

    }
    else {
        return anx;
    }
    return pow(x, n);

}
double f(double a , double x, double n) {
    return a * mux(x, n);
}

double df(double a, double x, double n) {
    return a * n * mux(x, n - 1);
}
double d2f(double a, double x, double n) {
    return a * n * (n - 1) * mux(x, n - 2);
}
int main() {
    double a, x, n;
    cin >> a >> x >> n;
    cout << f(a, x, n) << '\n';
    cout << df(a, x, n) << '\n';
    cout << d2f(a, x, n) << '\n';
}