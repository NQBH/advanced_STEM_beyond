#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, a;
		cin >> n >> a;
		vector<int> v(n);
		int n_less = 0, n_more = 0, n_equal = 0;
		for (int &x : v) {
			cin >> x;
			if (x == a) ++n_equal;
			else if (x < a) ++n_less;
			else ++n_more;
		}
		if (n_equal == n) cout << "0\n";
		else if (n_less <= n_more) cout << a + 1 << '\n';
		else if (n_less > n_more) cout << a - 1 << '\n';




		
	}
}