#include <bits/stdc++.h>
#include <cmath>
#include <string>
#define int long long
using namespace std;

double f(double a, double b, double c, double x) {
    double fx = a * (x * x) + b * x + c;
    return fx;
}

double F(int n, double alpha) {
    double a_list[n];
    a_list[0] = alpha;
    double a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= n; i++) {
        a_list[i] = f(a, b, c, a_list[i - 1]);
    }
    return a_list[n];
}

signed main() {
    double alpha;
    int n;
    cin >> n >> alpha;
    cout << fixed << setprecision(2) << F(n, alpha);
    return 0;
}
