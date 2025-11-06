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
		vector<int> a(n), odd, even;
		for (int &x : a) {
			cin >> x;
			if (x & 1) odd.push_back(x);
			else even.push_back(x);
		}
		if (even.size() >= 2) {
			cout << even[0] << ' ' << even[1] << '\n';
			continue;
		}
		bool ok = false;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if ((a[j] % a[i]) % 2 == 0) {
					cout << a[i] << ' ' << a[j] << '\n';
					ok = true;
					break;
				}
			}
			if (ok) break;
		}
		if (ok) continue;
		else cout << "-1\n";
	}
}