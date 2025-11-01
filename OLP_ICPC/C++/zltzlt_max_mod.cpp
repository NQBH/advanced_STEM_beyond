#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n & 1) {
			cout << n << ' ';
			for (int i = 1; i < n; ++i) cout << i << " \n"[i == n - 1];
		} else cout << "-1\n";
	}
}