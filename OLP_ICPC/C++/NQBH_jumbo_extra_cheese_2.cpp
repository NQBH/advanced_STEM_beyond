#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, h = 0;
		long long S = 0;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
			S += min(a[i], b[i]);
			h = max({h, a[i], b[i]});
		}
		cout << 2 * (S + h) << '\n';
	}
}