#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, i;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		map<int, int> f;
		for (i = n - 1; i >= 0; --i) {
			++f[a[i]];
			if (f[a[i]] > 1) break;
		}
		cout << i + 1 << '\n';
	}
}