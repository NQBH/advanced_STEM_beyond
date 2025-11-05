#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		long long l, r, k;
		cin >> l >> r >> k;
		cout << (l * k <= r ? r / k - l + 1 : 0) << '\n';
	}
}