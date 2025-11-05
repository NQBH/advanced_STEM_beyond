#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int k, x;
		cin >> k;
		set<int> a;
		for (int i = 0; i < k; ++i) {
			cin >> x;
			a.insert(x);
		}
		k -= 2;
		if (k == 1) {
			cout << "1 1\n";
			continue;
		}
		if (a.count(1) && a.count(k)) cout << "1 " << k << '\n';
		else {
			for (int i = 2; i <= k / 2; ++i) {
				if (k % i == 0) {
					int d = k / i;
					if (a.count(i) && a.count(d)) {
						cout << i << ' ' << d << '\n';
						break;
					}
				}
			}
		}
	}
}