#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ans = 0;
	cin >> n;
	vector<string> s(n);
	map<char, int> f;
	for (string &x : s) {
		cin >> x;
		++f[x[0]];
	}
	for (auto e : f)
		if (e.second > 1) {
			int half = e.second / 2, rem = e.second - half;
			ans += half * (half - 1) / 2 + rem * (rem - 1) / 2;
		}
	cout << ans << '\n';
}