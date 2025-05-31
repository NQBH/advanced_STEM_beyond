//158
#include <bits/stdc++.h>
#define ll long long 
#define ld long double

using namespace std;

ld power(ld a, int b) {
    ld ans(1);
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a;
        a *= a;
    }
    return ans;
}

ld Lim(const vector<ld>& coeffs, ld x) {
    ld res = 0;
    for (int i = 0; i < coeffs.size(); ++i) {
        res += coeffs[i] * power(x, i);
    }
    return res;
}

int main() {
    string x_input;
    int m, n;

    cout << "Nhap x0 (thuc hoac +inf / -inf): ";
    cin >> x_input;

    cout << "Nhap so bac da thuc tu m, mau n: ";
    cin >> m >> n;

    vector<ld> a(m + 1), b(n + 1);

    cout << "Nhap cac he so tu a0 -> a" << m << ": ";
    for (int i = m; i >= 0; --i) cin >> a[i];

    cout << "Nhap cac he so mau b0 -> b" << n << ": ";
    for (int i = n; i >= 0; --i) cin >> b[i];

    cout << fixed << setprecision(6);

    if (x_input == "+inf" || x_input == "inf" || x_input == "-inf") {
        int sign = (x_input == "-inf") ? -1 : 1;

        if (m < n) {
            cout << "Lim(x->" << x_input << ") P(x)/Q(x) = 0" << endl;
        } 
        else if (m > n) {
            ld leading = a[m] / b[n];
            int deg_diff = m - n;
            ld sign_adjust = (sign == 1) ? 1 : power(-1, deg_diff);
            ld res = leading * sign_adjust;

            if (res > 0) cout << "Lim(x->" << x_input << ") P(x)/Q(x) = +infinity" << endl;
            else if (res < 0) cout << "Lim(x->" << x_input << ") P(x)/Q(x) = -infinity" << endl;
            else cout << "Lim(x->" << x_input << ") P(x)/Q(x) = 0" << endl;
        } 
        else {
            ld res = a[m] / b[n];
            cout << "Lim(x->" << x_input << ") P(x)/Q(x) = " << res << endl;
        }
    } 
    else {
        ld x0 = stold(x_input);

        ld Px = Lim(a, x0);
        ld Qx = Lim(b, x0);

        cout << "P(" << x0 << ") = " << Px << ", Q(" << x0 << ") = " << Qx << endl;

        if (fabs(Qx) < 1e-9 && fabs(Px) < 1e-9) {
            cout << "Gioi han co dang vo dinh 0/0 tai x = " << x0 << endl;
        } 
        else if (fabs(Qx) < 1e-9) {
            cout << "Khong the tinh lim vi Q(x0) = 0 (chia cho 0)" << endl;
        } 
        else {
            ld result = Px / Qx;
            cout << "Gia tri lim(x->" << x0 << ") P(x)/Q(x) = " << result << endl;
        }
    }

    return 0;
}