#include <iostream>
#include <cmath>
using namespace std;

double f (double a, double x, int n ) {
    return a * pow(x, n);
}

double df (double a, double x, int n) {
    return n * a * pow(x, n - 1);
}

double d2f(double a, double x, int n) {
    return n * (n - 1) * a * pow(x, n - 2) ;
}

int main  ()  {
    int n;
    double a, x;

    cin >> a >> x >> n;

    cout << f(a, x, n) << endl;
    cout << df(a, x, n) << endl;
    cout << d2f(a, x, n) ;

    return 0;
}