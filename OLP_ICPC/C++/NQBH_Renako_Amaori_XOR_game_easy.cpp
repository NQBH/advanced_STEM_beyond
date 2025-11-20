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
		int odd_diff_pos = 0, even_diff_pos = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] != b[i]) {
				if (i & 1) ++odd_diff_pos;
				else ++even_diff_pos;
			}
		}
		int last_diff_pos = 0;
		for (int i = n; i >= 1; --i) {
			if (a[i] != b[i]) {
				last_diff_pos = i;
				break;
			}
		}
		if (A == B) cout << "Tie\n";
		else if (A == 1 && B == 0) { // A has advantage
			if (!odd_diff_pos && even_diff_pos) cout << "Mai\n";
			else if (even_diff_pos && !(last_diff_pos & 1)) cout << "Mai\n";
			else cout << "Ajisai\n";
		} else { // A = 0 && B = 1 // M has advantage
			if (!even_diff_pos && odd_diff_pos) cout << "Ajisai\n";
			else if (odd_diff_pos && (last_diff_pos & 1)) cout << "Ajisai\n";
			else cout << "Mai\n";
		}
	}
}