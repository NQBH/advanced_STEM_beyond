#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll e10 = 1;
		vector<ll> ans;
		for (int i = 1; i < 18; ++i) {
			e10 *= 10;
			if (n % (e10 + 1) == 0) ans.push_back(n / (e10 + 1));
		}
		if (ans.empty()) cout << "0\n";
		else {
			cout << ans.size() << '\n';
			sort(ans.begin(), ans.end());
			for (ll i : ans) cout << i << ' ';
			cout << '\n';
		}
	}
}