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
		vector<int> p(n);
		for (int &x : p) cin >> x;
		int n_inv = 0;
		for (int i = 1; i < n; ++i)
			if (p[i] < p[i - 1]) {
				++n_inv;
				++i;
			}
		if (!n_inv) cout << "0\n";
		else cout << n_inv << '\n';
	}
}