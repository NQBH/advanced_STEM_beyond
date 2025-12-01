#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1) cout << "1\n";
		else if (n == 2) cout << "9\n";
		else cout << max(5 * (n * n - n - 1), 4 * n * n - n - 4) << '\n';
	}
}