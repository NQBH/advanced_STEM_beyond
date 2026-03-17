#include <bits/stdc++.h>
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
    double alpha, a, b, c;

    cout << "nhap n:";
    cin >> n;

    cout << "nhap alpha:";
    cin >> alpha;

    cout << "nhap a, b, c:";
    cin >> a >> b >> c;

    cout << "a_n = " << F(n, alpha, a, b, c) << endl;
    return 0;
}
