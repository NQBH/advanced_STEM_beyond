#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, x, sum = 0, n0 = 0;
		cin >> n;
		map<int, int> f;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			++f[x];
			sum += x;
			if (!x) ++n0;
		}
		if (!n0) cout << sum << '\n';
		else if (n0 == n) cout << "1\n";
		else {
			for (int i = 1; i <= n; ++i)
				if (!f[i]) {
					if (i != n) {
						sum -= (i - 1) * i / 2;
						sum += i; // mex([i - 1]) = i
						break;
					}
				}
			cout << sum << '\n';
		}
	}
}