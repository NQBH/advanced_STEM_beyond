#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (!a || !b || a + b < 4) cout << "0\n";
		else cout << min({a, b, (a + b) / 4}) << '\n';
	}
}