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
		bool have0 = false;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			if (!have0 && !x) have0 = true;
			if (x != -1) a.insert(x);
		}
		if (have0) {
			cout << "NO\n";
			continue;
		}
		if (a.size() > 1) cout << "NO\n";
		else cout << "YES\n";
	}
}