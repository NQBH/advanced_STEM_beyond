#include <cmath>
#include <iostream>
using namespace std;
double f(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}
double F(int n, double alpha, double a, double b, double c) {
    double an = alpha;
    for (int i = 0; i < n; i++) {
        an = f(a, b, c, an);
    }
    return an;
}
int main() {
    int n;
    double a, b, c, alpha;
    cout << "n = ";
    cin >> n;
    cout << "alpha = ";
    cin >> alpha;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << "gia tri cua an = " << F(n, alpha, a, b, c);
}