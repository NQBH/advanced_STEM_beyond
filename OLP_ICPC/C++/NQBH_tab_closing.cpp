#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		long long a, b, n;
		cin >> a >> b >> n;
		if (b * n <= a || b == a) cout << "1\n";
		else cout << "2\n";
	}
}