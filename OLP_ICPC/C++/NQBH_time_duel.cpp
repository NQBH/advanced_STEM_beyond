#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, n1 = 0;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) {
			cin >> x;
			if (x) ++n1;
		}
		if (n1 == 0 || n1 == n) {
			cout << "YES\n";
			continue;
		}
		bool done = false;
		for (int i = 0; i < n - 1; ++i)
			if (!a[i] && !a[i + 1]) {
				done = true;
				break;
			}
		if (done) cout << "YES\n";
		else cout << "NO\n";
	}
}