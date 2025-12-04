#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x, n0 = 0;
	long long ans = 0;
	cin >> n;
	vector<int> a, b;
	map<int, int> f;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (!x) ++n0;
		else {
			++f[x];
			a.push_back(x);
		}
	}
	if (n0 == n) cout << 1ll * n * n;
	else {
		ans += 1ll * n0 * n;
		b.push_back(a[0]);
		for (int i = 1; i < (int)a.size(); ++i)
			if (a[i] != a[i - 1]) b.push_back(a[i]);
		int m = b.size();
		for (int i = 0; i < m - 1; ++i)
			for (int j = i + 1; j < m; ++j)
				if ((b[i] & b[j]) == 0) ans += f[b[i]] * f[b[j]];
		cout << ans;
	}
}