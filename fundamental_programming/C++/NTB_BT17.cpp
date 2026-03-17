#include <iostream>
#include <cmath>


using namespace std;

double f(double a, double x, double n) {
    return a * pow(x, n);
}
double D2f(double a, double x, double n) {
    return n * (n - 1) * a * pow(x, n - 2);
}
double Df(double a, double x, double n) {
    return n * a * pow(x, n - 1);
}

int main() {
    double a, x, n;
    cin >> a >> x >> n;
    cout << f(a, x, n) << endl;
    cout << D2f(a, x, n) << endl;
    cout << Df(a, x, n) << endl;
}