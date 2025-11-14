#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	string s;
	cin >> n >> q >> s;
	vector<int> f(n, 0);
	f[0] = s[0] - 'a' + 1;
	for (int i = 1; i < n; ++i)
		f[i] = f[i - 1] + s[i] - 'a' + 1;
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l == 1) cout << f[r - 1] << '\n';
		else cout << f[r - 1] - f[l - 2] << '\n';
	}
}