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
		map<int, int> f;
		for (int &x : a) cin >> x;
		sort(a.begin(), a.end());
		bool ok = true;
		for (int i = 1; i < n - 1; i += 2)
			if (a[i] != a[i + 1]) {
				ok = false;
				break;
			}
		cout << (ok ? "YES\n" : "NO\n");
	}
}