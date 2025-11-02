#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		sort(v.begin(), v.end());
		cout << 2 * (v[n - 1] - v[0]) + 2 * (v[n - 2] - v[1]) << '\n';
	}
}