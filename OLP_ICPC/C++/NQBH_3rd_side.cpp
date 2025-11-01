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
		if (n == 1) {
			cout << a[0] << '\n';
			continue;
		}
		for (int i = 1; i < n; ++i)
			a[i] = (a[i - 1] + a[i] - 1);
		cout << a[n - 1] << '\n';
	}
}