#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, num_odd = 0;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) {
			cin >> x;
			if (x & 1) ++num_odd;
		}
		if (n == 1) {
			if (a[0] & 1) cout << "0\n";
			else cout << "1\n";
			continue;
		}
		if (!num_odd) {
			cout << "1\n";
			continue;
		}
		if (num_odd == n) {
			cout << n - 1 << '\n';
			continue;
		}
		cout << 1 + num_odd << '\n';		
	}
}