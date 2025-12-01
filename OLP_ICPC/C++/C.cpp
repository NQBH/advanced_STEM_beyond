#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ok(ll q, ll r, ll k) {
	if (r >= k) return false;
	ll y = (k - r) / q;
	return y > r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll n, ans = 0;
		ll k;
		cin >> n >> k;
		vector<ll> q(n), r(n);
		unordered_map<ll, ll> fq, fr;
		for (ll &x : q) {
			cin >> x;
			++fq[x];
		}
		for (ll &x : r) {
			cin >> x;
			++fr[x];
		}
		vector<pair<ll, ll>> Q, R;
		for (auto &e : fq) Q.emplace_back(e);
		for (auto &e : fr) R.emplace_back(e);
		sort(Q.begin(), Q.end());
		sort(R.begin(), R.end());
		vector<ll> q_rem(Q.size()), r_rem(R.size());
		for (ll i = 0; i < Q.size(); ++i) q_rem[i] = Q[i].second;
		for (ll i = 0; i < R.size(); ++i) r_rem[i] = R[i].second;
		for (ll i = 0; i < Q.size(); ++i)
			for (ll j = 0; j < R.size(); ++j) {
				if (!q_rem[i] || !r_rem[j]) continue;
				if (ok(Q[i].first, R[j].first, k)) {
					ll n_pair = min(q_rem[i], r_rem[j]);
					ans += n_pair;
					q_rem[i] -= n_pair;
					r_rem[j] -= n_pair;
				}
			}
		cout << ans << '\n';
	}
}