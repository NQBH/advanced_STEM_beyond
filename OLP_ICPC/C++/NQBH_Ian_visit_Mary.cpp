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
		else if (gcd(a, b - 1) == 1) cout << "2\n" << a << ' ' << b - 1 << '\n' << a << ' ' << b << '\n';
		else cout << "2\n" << a - 1 << ' ' << b << '\n' << a << ' ' << b << '\n';
	}
}
// WA CF