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
		sort(a.begin() + 1, a.end());
		for (int i = 1; i < n; ++i)
			if (a[0] < a[i]) a[0] = (a[0] + a[i] + 1) / 2;
		cout << a[0] << '\n';
	}
}