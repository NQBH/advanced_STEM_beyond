#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k, a = 2023;
		cin >> n >> k;
		vector<int> b(n);
		for (int &x : b) cin >> x;
		bool no = false;
		for (int x : b)
			if (a % x) {
				no = true;
				break;
			} else a /= x;
		if (no) cout << "NO\n";
		else {
			cout << "YES\n";
			cout << a << ' ';
			for (int i = 0; i < k - 1; ++i) cout << "1 ";
			cout << '\n';
		}
	}
}