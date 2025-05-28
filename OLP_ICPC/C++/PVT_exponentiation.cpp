#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MOD = 1e9+7;

int bin_pow(int a, int b) {
    int res = 1;
    while(b > 0) {
        if(b % 2 == 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b = b / 2;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
        int a, b; cin >> a >> b;
        if(a == 0 && b == 0) cout << 1 << '\n';
        else cout << bin_pow(a, b) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    solve();
    return 0;
}