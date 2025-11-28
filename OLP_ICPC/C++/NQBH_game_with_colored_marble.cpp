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
		vector<int> c(n);
		map<int, int> f;
		for (int &x : c) {
			cin >> x;
			++f[x];
		}
		int n_single = 0, n_mul = 0;
		for (auto e : f)
			if (e.second == 1) ++n_single;
			else ++n_mul;
		cout << (n_single + 1) / 2 * 2 + n_mul << '\n';
	}
}