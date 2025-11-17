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
		vector<int> s(n), a(n);
		for (int &x : s) cin >> x;
		for (int i = 0; i < n; ++i) a[i] = s[i]; // copy
		sort(a.begin(), a.end());
		for (int i = 0; i < n; ++i)
			if (s[i] == a[n - 1]) cout << s[i] - a[n - 2] << ' ';
			else cout << s[i] - a[n - 1] << ' ';
		cout << '\n';
	}
}