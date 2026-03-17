#include <bits/stdc++.h>
#include <cmath>
#include <string>
#define int long long
using namespace std;

double f(double a, double x, double n) {
    double total = x;
    for (int i = 1; i <= n - 1; i++) total *= x;
    return total * a;
}

double Df(double a, double x, double n) {
    double total = x;
    for (int i = 1; i <= n - 2; i++) total *= x;
    return total * a * n;
}

double D2f(double a, double x, double n) {
    double total = x;
    for (int i = 1; i <= n - 3; i++) total *= x;
    return total * a * (n * (n - 1));
}

signed main() {
    double a, x, n;
    cin >> a >> x >> n;
    cout << "f = " << f(a, x, n) << endl;
    cout << "f'(x) = " << Df(a, x, n) << endl;
    cout << "f''(x) = " <<  D2f(a, x, n) << endl;
    return 0;
}