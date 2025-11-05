#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> b(k), c(k);
		map<int, int> shelf;
		for (int i = 0; i < k; ++i) {
			cin >> b[i] >> c[i];
			shelf[b[i]] += c[i];
		}
		long long ans = 0;
		vector<int> a;
		for (auto e : shelf) a.push_back(e.second);
		sort(a.begin(), a.end(), greater<int>());
		int lim = min((int)a.size(), min(n, k));
		for (int i = 0; i < lim; ++i) ans += a[i];
		cout << ans << '\n';
	}
}