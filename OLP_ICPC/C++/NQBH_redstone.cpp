#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n;
		set<int> a;
		bool ok = false;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			if (!ok && a.count(x)) ok = true;
			else a.insert(x);
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}