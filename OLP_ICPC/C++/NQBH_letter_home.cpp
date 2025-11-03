#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, s;
		cin >> n >> s;
		vector<int> x(n);
		for (int &i : x) cin >> i;
		if (s <= x[0]) cout << x[n - 1] - s << '\n';
		else if (s >= x[n - 1]) cout << s - x[0] << '\n';
		else cout << x[n - 1] - x[0] + min(s - x[0], x[n - 1] - s) << '\n';
	}
}