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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ans = 0;
	int last = -1e9;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1' && i - last >= k) ++ans;
		if (s[i] == '1') last = i;
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