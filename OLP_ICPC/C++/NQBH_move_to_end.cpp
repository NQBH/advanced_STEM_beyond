#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n + 1, 0), pmax(n + 1, 0);
		vector<ll> ssum(n + 1, 0);
		for (int i = 1; i <= n; ++i) cin >> a[i];
		ssum[n] = a[n];
		for (int i = 1; i <= n; ++i) pmax[i] = max(pmax[i - 1], a[i]);
		for (int i = n - 1; i >= 1; --i) ssum[i] = ssum[i + 1] + a[i];
		for (int i = 1; i <= n; ++i)
			if (pmax[n - i] > a[n - i + 1]) cout << ssum[n - i + 1] + pmax[n - i] - a[n - i + 1] << ' ';
			else cout << ssum[n - i + 1] << ' ';
		cout << '\n';
	}
}