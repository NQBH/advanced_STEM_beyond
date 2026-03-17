#include <iostream>
#include <cmath>
using namespace std;

double f(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}
double F(int n, double an, double a, double b, double c) {
    for (int i = 0; i < n; i++) {
        an = f(a, b, c, an);
    }
    return an;
}

int main() {
    int n;
    double an, a, b, c;
    cin >> n >> an >> a >> b >> c;
    cout << "  " << F(n, an, a, b, c) << endl;
    return 0;
}
