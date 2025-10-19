#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		vector<int> a(n), cnt(n + 1, 0), f, ge(n + 1, 0);
		for (int& x : a) {
			cin >> x;
			++cnt[x];
		}
		if (n == 1) cout << "1\n";
		else if (n == 2) cout << "2\n";
		else {
			for (int i = 1; i <= n; ++i)
				if (cnt[i]) f.push_back(cnt[i]);
			if (f.size() == n) cout << n << '\n';
			else {
				for (int& x : f)
					for (int& y : f)
						if (y >= x) ++ge[x];
				for (int& x : f) ans = max(ans, x * ge[x]);
				cout << ans << '\n';
			}
		}
	}
}