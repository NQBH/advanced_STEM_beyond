#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		int n0 = 0, n1 = 0;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) {
			cin >> x;
			if (!x) ++n0;
			else if (x == 1) ++n1;
		}
		long long p = 1;
		for (int i = 0; i < n0; ++i) p *= 2;
		cout << 1LL * n1 * p << '\n';
	}
}