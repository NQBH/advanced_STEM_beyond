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
		if (n & 1) {
			cout << n << ' ' << 1 << ' ';
			for (int i = 2; i < n; ++i) cout << i << " \n"[i == n - 1];
		} else cout << "-1\n";
	}
}