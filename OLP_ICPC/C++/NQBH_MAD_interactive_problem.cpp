#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int query(vector<int> s) {
	cout << "? " << s.size() << ' ';
	sort(s.begin(), s.end());
	for (int u : s) cout << u << ' ';
	cout << '\n' << flush;
	int x;
	cin >> x;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int m = 2 * n;
		vector<int> ans(m + 1), s, t;
		for (int i = 1; i <= m; ++i) {
			s.push_back(i);
			int r = query(s);
			if (r > 0) ans[i] = r, s.pop_back(), t.push_back(i);
		}
		for (int i = 1; i <= m; ++i)
			if (ans[i] == 0) t.push_back(i), ans[i] = query(t), t.pop_back();
		cout << "! ";
		for (int i = 1; i <= m; ++i)
			cout << ans[i] << " \n"[i == m];
		cout << flush;
	}
}