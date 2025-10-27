#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = n; i >= 1; --i) cout << i << ' ';
		cout << n;
		for (int i = 1; i < n; ++i) cout << ' ' << i;
		cout << '\n';
	}
}