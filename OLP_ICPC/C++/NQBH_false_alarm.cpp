#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		int l = 0, r = n - 1;
		while (!a[l]) ++l;
		while (!a[r]) --r;
		if (r - l < x) cout << "YES\n";
		else cout << "NO\n";
	}
}