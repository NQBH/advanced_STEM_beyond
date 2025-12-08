#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mxn = 2e5 + 5;
const int B = 512;
int t, f[B + 3][mxn], n, a[mxn], q;
ll sum[mxn], N = 1000000001;
int l_[mxn], r_[mxn], x_[mxn], id[mxn];

void solve() {
	cin >> n >> q;
	vector<int> v;
	v.clear();
	for (int i = 1; i <= n; ++i) cin >> a[i], sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= q; ++i) cin >> l_[i] >> r_[i] >> x_[i], v.push_back(x_[i]);
	v.push_back(0);
	v.push_back(1000000008);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= q; ++i) id[i] = lower_bound(v.begin(), v.end(), x_[i]) - v.begin();
	for (int i = 1; i <= B; ++i) {
		int k = 0;
		for (int j = n - i; j >= 0; --j)
			for (; v[k] <= min(sum[j + i] - sum[j], N); ++k) f[i][k] = j + 1;
	}
	for (int t = 1; t <= q; ++t) {
		int l, r, x, cnt = 0;
		l = l_[t], r = r_[t], x = x_[t];
		for (int i = 1; i <= B; ++i)
			if (f[i][id[t]] >= l) {
				int w = min(r - l + 1, f[i][id[t]] - l + i) / i;
				cnt += w;
				l += w * i;
			} --l;
		while (1) {
			if (sum[r] - sum[l] < x) {
				cout << cnt << ' ' << sum[r] - sum[l] << '\n';
				break;
			} ++cnt;
			int t = x, lo = l - 1, hi = n + 1, md;
			ll req = sum[l] + t;
			for (; lo < hi - 1;) {
				md = (lo + hi) >> 1;
				if (sum[md] < req) lo = md;
				else hi = md;
			}
			l = hi;
		}
	}
	for (int i = 0; i < max(n, (int)v.size()) + 3; ++i) sum[i] = 0;
	for (int j = 0; j < B + 3; ++j)
		for (int i = 0; i < max(n, (int)v.size()) + 3; ++i) f[j][i] = 0;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) solve();
}