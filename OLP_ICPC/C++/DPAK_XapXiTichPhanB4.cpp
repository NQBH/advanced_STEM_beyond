#include <bits/stdc++.h>
using namespace std;
int n, m;

double P(double x, int sz, vector<double> &a) {
    double ans = 0;
    for (int i = 0; i <= sz; i++) {
        ans += a[i] * pow(x,i);
    }
    return ans;
}
double tongQuat(double xo, double x, double h, vector<double> &a, vector<double> &b) {
    double ans =  0;
    double Px_T = P(xo,n, a);
    double Qx_M = P(xo,m, b);
    
    double Py_T = P(x,n,a);
    double Qy_M = P(x,m, b);

    if (Qx_M == 0 || Qy_M == 0) {
        cout << "ERROR: Divided by 0";
        exit(0);
    }

    double Left = Px_T / Qx_M;
    double Right = Py_T / Qy_M;

    ans = (Left - Right) / h;
    return ans;
}

int main(){    
    vector<double>a, b; double xo, h;

    cin >> n >> m >> xo >> h;
    a.resize(n + 1); b.resize(m + 1);

    for (int i = n; i >= 0; cin >> a[i--]);
    for (int i = m; i >= 0; cin >> b[i--]);
    
    double FW = tongQuat(xo + h, xo, h, a, b);
    double BW = tongQuat(xo, xo - h, h, a, b);
    double ST = tongQuat(xo + h, xo - h, 2 * h, a, b);
    
    cout << "Newton Forward = " << fixed << setprecision(10) << FW << endl;
    cout << "Newton Backward = "<< fixed << setprecision(10) << BW << endl;
    cout << "Stirling = " << fixed << setprecision(10) << ST << endl;
}