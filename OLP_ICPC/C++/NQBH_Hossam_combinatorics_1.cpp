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
		sort(a.begin(), a.end());
		if (a[0] == a[n - 1]) cout << 1LL * n * (n - 1) << '\n';
		else {
			int fmn = 1, fmx = 1;
			for (int i = 1; i < n; ++i)
				if (a[i] == a[0]) ++fmn;
				else break;
			for (int i = n - 2; i >= 0; --i)
				if (a[i] == a[n - 1]) ++fmx;
				else break;
			cout << 2LL * fmn * fmx << '\n';
		}
	}
}