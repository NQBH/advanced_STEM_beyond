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
		vector<int> h(n);
		for (int &x : h) cin >> x;
		for (int i = 0; i < n - 1; ++i)
			if (h[i] > h[i + 1]) ++ans;
		cout << ans << '\n';
	}
}