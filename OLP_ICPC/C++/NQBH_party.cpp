#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ans = 0;
	cin >> n;
	vector<int> p(n + 1);
	for (int i = 1; i <= n; ++i) cin >> p[i];
	for (int i = 1; i <= n; ++i) {
		int j = i, cnt = 1;
		while (p[j] != -1) {
			++cnt;
			j = p[j];
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
}