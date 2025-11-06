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
		vector<int> a(n);
		for (int &x : a) cin >> x;
		int n0 = 0, n1 = 0, max0 = 0, max1 = 0;
		for (int i = 0; i < n; ++i)
			if (i & 1) {
				++n1;
				max1 = max(max1, a[i]);
			} else {
				++n0;
				max0 = max(max0, a[i]);
			}
		cout << max(max0 + n0, max1 + n1) << '\n';
	}
}