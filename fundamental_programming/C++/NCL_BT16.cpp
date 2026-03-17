#include <bits/stdc++.h>
using namespace std;

double F(int n, double alpha) {
    double result = alpha * n;
    return result;
}
double f(double a, double b, double c, double x) {
    double result = a * x * x + b * x + c;
    return result;
}
int main() {
    double a, b, c, x, alpha;
    int n;
    cin >> alpha >> n >> a >> b >> c >> x;
    cout << F(n, alpha) << endl;
    cout << f(a, b, c, x) << endl;
    return 0;
}
