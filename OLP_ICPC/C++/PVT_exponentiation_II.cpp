#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MOD = 1e9+7;

int bin_pow(int a, int b, int mod = MOD) {
    int res = 1;
    while(b > 0) {
        if(b % 2 == 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b = b / 2;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 0) {
            if(b == 0 && c != 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        
        else {
            if(b == 0 && c != 0) cout << 1 << '\n';
            else if(b == 0 && c == 0) cout << a << '\n';
            else {
                int temp = bin_pow(b, c, MOD - 1);
                cout << bin_pow(a, temp) << '\n';
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    solve();
    return 0;
}