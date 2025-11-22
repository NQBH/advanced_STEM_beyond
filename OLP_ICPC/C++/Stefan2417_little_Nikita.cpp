#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << (n >= m && (n % 2) == (m % 2) ? "Yes" : "No") << '\n';
	}
}