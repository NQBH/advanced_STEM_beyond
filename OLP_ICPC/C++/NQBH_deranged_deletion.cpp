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
		bool ok = false;
		for (int &x : a) cin >> x;
		for (int i = 1; i < n; ++i)
			if (a[i] < a[i - 1]) {
				cout << "YES\n2\n";
				cout << a[i - 1] << ' ' << a[i] << '\n';
				ok = true;
				break;
			} 
		if (!ok) cout << "NO\n";
	}
}