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
		if (gcd(a, b) == 1) cout << "1\n" << a << ' ' << b << '\n';
		else cout << "2\n" << 1 << ' ' << b - 1 << '\n' << a << ' ' << b << '\n';
	}
}