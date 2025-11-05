#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MOD =1e9+7;

int mul(int n, int p) {
    if (p == 0) return 1;
    if (p == 1) return n;
    int temp = mul(n, p / 2);

    if (p% 2 == 0) {
        return temp % MOD * temp % MOD;
    }
    return temp % MOD * temp % MOD * n % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> bits;
        for (;k > 0; bits.push_back(k % 2), k /= 2);
        //reverse(bits.begin(), bits.end());
        int ans = 0;
        for (int i = 0; i < bits.size(); i++) {
            (ans += (bits[i] == 0 ? 0 : mul(n,i))) %= MOD;
        }
        cout << ans << endl;
    }
}
/*
5 = 101 3^0 + 3^2
24 = 11000 2^4 + 2^3
6 = 110 3^1 + 3^2
*/