#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, x, y;
		string s;
		cin >> n >> x >> y >> s;
		ll n4 = 0, n8 = 0;
		for (char c : s)
			if (c == '4') ++n4;
			else ++n8;
		ll dx = max(llabs(x) - n8, 0ll), dy = max(llabs(y) - n8, 0ll);
		if (dx + dy <= n4) cout << "YES\n";
		else cout << "NO\n";
	}
}