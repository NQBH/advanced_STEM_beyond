#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		long long a, b;
		cin >> a >> b;
		if (a == 1) cout << b * b << '\n';
		else if (gcd(a, b) == 1) cout << a * b << '\n';
		else if (b % a == 0) cout << b * b / a << '\n';
		else cout << b * a / gcd(a, b) << '\n';
	}
}