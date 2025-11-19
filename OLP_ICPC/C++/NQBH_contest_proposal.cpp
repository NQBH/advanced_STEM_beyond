#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		vector<int> a(n), b(n);
		for (int &x : a) cin >> x;
		for (int &x : b) cin >> x;
		int idx = 0;
		for (int i = 0; i < n; ++i)
			if (a[idx] > b[i]) ++ans; // add b[i]
			else ++idx;
		cout << ans << '\n';
	}
}