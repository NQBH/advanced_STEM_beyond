#include <bits/stdc++.h>
using namespace std;

double f(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

double F(int n, double alpha, double a, double b, double c) {
    double a_0 = alpha;
    for (int i = 0; i < n; i++) {
        a_0 = f(a, b, c, a_0);
    }
    return a_0;
}

int main() {
    double alpha, a, b, c;
    int n;
    cin >> a >> b >> c >> alpha >> n;
    cout << fixed << setprecision(2) << F(n, alpha, a, b, c);
}