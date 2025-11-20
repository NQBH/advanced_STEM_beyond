#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, A = 0, B = 0;
		cin >> n;
		vector<int> a(n + 1, 0), b(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			A ^= a[i];
		}
		for (int i = 1; i <= n; ++i) {
			cin >> b[i];
			B ^= b[i];
		}

		if (A == B) {
			cout << "Tie\n";
			continue;
		}
		int diff = A ^ B, k = 31 - __builtin_clz(diff), win = -1;
		for (int i = n; i >= 1; --i) {
			int M = a[i] ^ b[i];
			if ((M >> k) & 1) {
				win = i;
				break;
			}
		}
		if (win & 1) cout << "Ajisai\n";
        else cout << "Mai\n";
	}
}