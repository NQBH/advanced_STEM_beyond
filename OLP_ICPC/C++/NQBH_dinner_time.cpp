#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, p, q;
		cin >> n >> m >> p >> q;
		if (p == 1) cout << (n * q == m ? "YES\n" : "NO\n");
		else if (n % p == 0) cout << (n / p * q == m ? "YES\n" : "NO\n");
		else cout << "YES\n";		
	}
}