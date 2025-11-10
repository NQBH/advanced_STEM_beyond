#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		if (k > max(m, n) - 1) cout << m * n << '\n';
		else if (k <= min(m, n)) cout << k * k << '\n';
		else cout << k * min(m, n) << '\n';
	}
}