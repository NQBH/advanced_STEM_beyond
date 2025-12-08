#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, l, r;
		cin >> n >> l >> r;
		// p[i]: prefix xor sum from a[0] to a[i]: construct p[i] = i, except p[r] = l - 1
		int prev_p = 0;
		for (int i = 1; i <= n; ++i) {
			int curr_p;
			if (i == r) curr_p = l - 1;
			else curr_p = i;
			int a = prev_p ^ curr_p; // a = a[i]
			cout << a << ' ';
			prev_p = curr_p;
		}
		cout << '\n';
	}
}