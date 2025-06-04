#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9 + 7;
string str;
int n, freq[26];
ll fact[1000005], inv_fact[1000005];

ll Power(ll a, ll b) {
	ll ans(1);
	for (; b; b >>= 1) {
		if (b & 1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
	}
	return ans;
}

void solve() {
	fact[0] = inv_fact[0] = 1;
	for (int i = 1; i <= 1e6; ++i) {
		fact[i] = (fact[i - 1] * i) % mod;
		inv_fact[i] = Power(fact[i], mod - 2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
	cin >> str;
	n = str.size();
	for (int i = 0; i < n; ++i)
		freq[str[i] - 'a']++;
	ll ans = fact[n];
	for (int i = 0; i < 26; ++i)
		ans = (ans * inv_fact[freq[i]]) % mod;
	cout << ans << '\n';

	return 0;
}