#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		vector<int> a(n);
		map<int, int> f;
		for (int &x : a) {
			cin >> x;
			++f[x];
		}
		for (int i = 1; i <= n; ++i) 
			ans += f[i] / 2;
		cout << ans << '\n';
	}
}