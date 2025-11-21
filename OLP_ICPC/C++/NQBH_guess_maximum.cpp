#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m = 1e9;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		for (int i = 1; i < n; ++i) m = min(m, max(a[i - 1], a[i]));
		cout << m - 1 << '\n';	
	}
}