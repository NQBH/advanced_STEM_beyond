#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; ++i) cin >> a[i];
		string s;
		cin >> s;
		int S = stoi(s, nullptr, 2);
		cin >> q;
		while (q--) {
			int tp;
			cin >> tp;
			if (tp == 1) {
				int l, r;
				cin >> l >> r;
				for (int i = n - r; i <= n - l; ++i)
					S ^= (1 << i); // flip ith bit
			} else {
				int g, ans = 0;
				cin >> g;
				if (g == 1) {
					for (int i = 0; i < n; ++i)
						if (S & (1 << i)) ans ^= a[n - i];
				} else {
					for (int i = 0; i < n; ++i)
						if ((S & (1 << i)) == 0) ans ^= a[n - i];
				}
				cout << ans << ' ';
			}
		}
		cout << '\n';
	}
}