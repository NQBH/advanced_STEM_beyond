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
		vector<int> a(n);
		for (int &x : a) cin >> x;
		bool ok = 1;
		for (int i = 1; i < n; ++i) {
			int diff = abs(a[i] - a[i - 1]);
			if (diff != 5 && diff != 7) {
				ok = 0;
				break;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}