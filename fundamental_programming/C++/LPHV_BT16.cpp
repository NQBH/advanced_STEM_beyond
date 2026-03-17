#include<iostream>
using namespace std;
double f(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}
void F(int n, double alpha, double a, double b, double c) {
    double an = alpha;
    for (int i = 0; i < n; i++) {
        an = f(a, b, c, an);
    }
    cout << "a" << n << "= " << an << endl;
}
int main() {
    int n;
    double alpha;
    double a, b, c;
    cout << " Nhap n: ";
    cin >> n;
    cout << "Nhap alpha: ";
    cin >> alpha;
    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;
    F(n, alpha, a, b, c);
    return 0;
}
