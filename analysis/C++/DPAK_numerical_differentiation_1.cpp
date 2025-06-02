#include <bits/stdc++.h>
using namespace std;
int n;

double ppow(double base, double exp) {
    if (base < 0 && fmod(exp, 1.0) != 0) {
        cout << "Can bac khong nguyen cua so am khong duoc ho tro trong kieu du lieu so thuc!!";
        exit(0);
//        return NAN;
    }
    return pow(base, exp);
}

double tongQuat(double xo, double x, double h, vector<double> &a, vector<double> &alpha) {
    double ans =  0;
    for (int i = 0; i <= n; i++) {
        ans = ans + a[i] * ppow(xo, alpha[i]);
    }
    for (int i = 0; i <= n; i++) {
        ans = ans - a[i] * ppow(x, alpha[i]);
    }
    ans = ans / h;
    return ans;
}

int main() {
    vector<double>a, alpha; double xo, h;
    cin >> n >> xo >> h;
    a.resize(n + 1); alpha.resize(n + 1);

    for (int i = n; i >= 0; cin >> a[i--]);
    for (int i = n; i >= 0; cin >> alpha[i--]);

    double FW = tongQuat(xo + h, xo, h, a, alpha);
    double BW = tongQuat(xo, xo - h, h, a, alpha);
    double ST = tongQuat(xo + h, xo - h, 2 * h, a, alpha);

    cout << "Newton Forward = " << fixed << setprecision(10) << FW << endl;
    cout << "Newton Backward = " << fixed << setprecision(10) << BW << endl;
    cout << "Stirling = " << fixed << setprecision(10) << ST << endl;
}