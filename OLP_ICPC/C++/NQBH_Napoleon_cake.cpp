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
		vector<int> a(n + 1), ans(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			
		}
		for (int i = n - 1; i >= 0; --i) {
			if (a[i]) {
				for (int j = i; j >= max(0, i - a[i] + 1); --j)
					if (!ans[j]) ans[j] = 1;
			}
		}
		for (int x : ans) cout << x << ' ';
		cout << '\n';
	}
}