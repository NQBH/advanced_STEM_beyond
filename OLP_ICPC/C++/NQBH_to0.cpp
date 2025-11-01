#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (n & 1) --n;
		if (k & 1) cout << n / (k - 1) + (n % (k - 1) ? 1 : 0) << '\n';
		else cout << n / k + (n % k ? 1 : 0) << '\n';
	}
}