#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), cnt(n + 1, 0), f;
		for (int& x : a) {
			cin >> x;
			++cnt[x];
		}
		if (n == 1) cout << "1\n";
		else if (n == 2) cout << "2\n";
		else {
			int ans = 0;
			for (int i = 1; i <= n; ++i)
				if (cnt[i]) f.push_back(cnt[i]);
			if (f.size() == 1 || f.size() == n) cout << n << '\n';
			else {
				for (int i = 0; i < f.size(); ++i) {
					int cnt_ge = 0;
					for (int j = 0; j < f.size(); ++j)
						if (f[j] >= f[i]) ++cnt_ge;
					ans = max(ans, f[i] * cnt_ge);
				}
				cout << ans << '\n';
			}
		}
	}
}