#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k, p;
		cin >> n >> k >> p;
		if (k == 0) {
			cout << "0\n";
			continue;
		}
		if (k < 0) k = -k;
		if (k > n * p) cout << "-1\n";
		else cout << k / p + (k % p == 0 ? 0 : 1) << '\n';
	}
}