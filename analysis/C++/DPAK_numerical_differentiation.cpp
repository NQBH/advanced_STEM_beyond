#include <bits/stdc++.h>
using namespace std;
int n;
double h;

double forward(double xo, double x, vector<double> &a) {
    double ans =  0;
    for (int i = 0; i <= n; i++) {
        ans = ans + a[i] * pow(xo, i);
    }
    cout << ans << endl;
    for (int i = 0; i <= n; i++) {
        ans = ans - a[i] * pow(x, i);
    }
    cout << ans << endl;
    ans = ans / h;
    cout << ans << endl;
    return ans;
}

double backward(double xo, double x, vector<double> &a) {
    double ans =  0;
    for (int i = 0; i <= n; i++) {
        ans += a[i] * pow(xo, i);
    }
    for (int i = 0; i <= n; i++) {
        ans -= a[i] * pow(x, i);
    }
    ans = ans / h;
    return ans;
}

double stirling(double xo, double x, vector<double> &a) {
    double ans =  0;
    for (int i = 0; i <= n; i++) {
        ans += a[i] * pow(xo, i);
    }
    for (int i = 0; i <= n; i++) {
        ans -= a[i] * pow(x, i);
    }
    ans = ans / (2 * h);
    return ans;
}

int main() {
    vector<double>a;
    a.resize(n + 1);
    double xo;
    cin >> n >> xo >> h;
    for (int i = n; i >= 0; i--) {
        cin >> a[i];
    }
    double FW = forward(xo + h, xo, a);
    double BW = backward(xo, xo - h, a);
    double ST = stirling(xo + h, xo - h, a);
    cout << "Newton Forward = " << FW << endl;
    cout << "Newton Backward = " << BW << endl;
    cout << "Stirling = " << ST << endl;
}