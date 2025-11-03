#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, s;
		cin >> n >> s;
		vector<int> x(n);
		for (int i = 0; i < n; ++i) cin >> x[i];
		int ans = min(abs(s - x[0]), abs(s - x.back())) + x.back() - x[0];
		cout << ans << '\n';
	}
}