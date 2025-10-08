#include <iostream>
using namespace std;

int main() {
	int t;
	long long x, y, k;
	long long ans;
	cin >> t;
	while (t--) {
		cin >> x >> y >> k;
		ans = k + (k + k * y - 1) / (x - 1) + ((k + k * y - 1) % (x - 1) != 0);
		cout << ans << '\n';
	}
}