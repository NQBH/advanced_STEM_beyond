#include <bits/stdc++.h>
#define ld long double
using namespace std;

int n;
ld x, h;
ld a[1000005], alpha[1000005];

ld forward(ld x, ld h) {
    ld ans(0), fx(0);
    for (int i = 0; i <= n; ++i)
        ans += (a[i] * pow(x + h, alpha[i]));
    for (int i = 0; i <= n; ++i)
        fx += (a[i] * pow(x, alpha[i]));
    ans -= fx;
    return ans / h;
}

ld backward(ld x, ld h) {
    ld ans(0), fx(0);
    for (int i = 0; i <= n; ++i)
        ans += (a[i] * pow(x - h, alpha[i]));
    for (int i = 0; i <= n; ++i)
        fx += (a[i] * pow(x, alpha[i]));
    ans = fx - ans;
    return ans / h;
}

ld stirling(ld x, ld h) {
    ld ans1(0), ans2(0);
    for (int i = 0; i <= n; ++i)
        ans1 += (a[i] * pow(x + h, alpha[i]));

    for (int i = 0; i <= n; ++i)
        ans2 += (a[i] * pow(x - h, alpha[i]));

    ld ans = ans1 - ans2;
    return ans / (2 * h);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x >> h;
    for (int i = n; i >= 0; --i) cin >> a[i];
    for (int i = n; i >= 0; --i) cin >> alpha[i];

    ld FORWARD = forward(x, h), BACKWARD = backward(x, h), STIRLING = stirling(x, h);
    cout << fixed << setprecision(10) << "FORWARD: " << FORWARD << "\n";
    cout << fixed << setprecision(10) << "BACKWARD: " << BACKWARD << "\n";
    cout << fixed << setprecision(10) << "STIRLING: " << STIRLING << "\n";
    return 0;
}