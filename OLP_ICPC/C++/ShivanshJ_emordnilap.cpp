#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	const int N = 1e5 + 5;
    const int mod = 1e9 + 7;
    vector<int> fact(N);
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
    	fact[i] = fact[i - 1] * i;
    	fact[i] %= mod;
    }
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	int ans = n * (n - 1);
    	ans %= mod;
    	ans = (ans * fact[n]) % mod;
    	cout << ans << endl;
    }
}