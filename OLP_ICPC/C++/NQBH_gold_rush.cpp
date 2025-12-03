#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, a = 0, b = 0;
		cin >> n >> m;
		int g = gcd(m, n);
		m /= g;
		n /= g;
		while (m % 2 == 0) {
			m /= 2;
			++a;
		}
		if (m != 1) {
			cout << "NO\n";
			continue;
		}
		while (n % 3 == 0) {
			n /= 3;
			++b;
		}
		if (n != 1) cout << "NO\n";
		else if (a > b) cout << "NO\n";
		else cout << "YES\n";
	}
}