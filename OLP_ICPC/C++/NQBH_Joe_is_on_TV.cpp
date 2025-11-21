#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	double ans = 0;
	for (int i = 1; i <= n; ++i) ans += 1.0 / i;
	cout << ans << '\n';
}