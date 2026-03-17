#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double f(double a, double b, double c, double x) {
    return a * (x * x) + b * x + c;
}
double F(int n, double alpha, double a, double b, double c) {
    double a_0 = alpha;
    for (int i = 0 ; i < n ; i++) {
        a_0 = f(a, b, c, a_0);
    }
    return a_0;
}

int main() {
    int n;
    double alpha, a, b, c;
    cin >> n >> alpha >> a >> b >> c;
    double dap_an = F(n, alpha, a, b, c);
    cout << fixed << setprecision(2) << dap_an;
    return 0;
}