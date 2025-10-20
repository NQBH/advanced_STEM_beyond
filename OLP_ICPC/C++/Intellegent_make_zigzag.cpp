#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int uid(int a, int b) {
	return uniform_int_distribution<int>(a, b)(rng);
}

ll uld(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(rng);
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	vector<int> pre(n);
	pre[0] = a[0];
	for (int i = 1; i < n; ++i) pre[i] = max(pre[i - 1], a[i]);
	ll ans = 0;
	for (int i = 0; i < n; i += 2) {
		int dif = -1;
		if (i) dif = max(dif, a[i] - pre[i - 1]);
		if (i < n - 1) dif = max(dif, a[i] - pre[i + 1]);
		ans += dif + 1;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}