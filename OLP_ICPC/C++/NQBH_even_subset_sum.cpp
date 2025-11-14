#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, nodd = 0, pos_even = 0;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] & 1) ++nodd;
			else if (!pos_even) pos_even = i;
		}
		if (n == 1) cout << (nodd ? "-1\n" : "1\n1\n");
		else {
			if (nodd != n) cout << "1\n" << pos_even << '\n';
			else cout << "2\n1 2\n";
		}
	}
}