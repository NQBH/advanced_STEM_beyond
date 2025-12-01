#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n + 1, 0), pmin(n + 1, 1e9), smax(n + 1, 0);
		for (int i = 1; i <= n; ++i) cin >> a[i];
		smax[n] = a[n];
		for (int i = 1; i <= n; ++i)
			pmin[i] = min(pmin[i - 1], a[i]);
		for (int i = n - 1; i >= 1; --i)
			smax[i] = max(smax[i + 1], a[i]);
		string s = "";
		for (int i = 1; i <= n; ++i)
			if (a[i] <= pmin[i] || a[i] >= smax[i]) s += '1';
			else s += '0';
		cout << s << '\n';
	}
}