#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, l, r;
		cin >> n >> m >> l >> r;
		if (n == m) cout << l << ' ' << r << '\n';
		else if (l == 0) cout << l << ' ' << r - n + m << '\n';
		else if (r == 0) cout << l + n - m << ' ' << r << '\n';
		else {
			int rem = n - m;
			while (rem) {
				if (l) {
					++l;
					--rem;
					continue;
				}
				if (r) {
					--r;
					--rem;
				}
			}
			cout << l << ' ' << r << '\n';
		}
	}
}