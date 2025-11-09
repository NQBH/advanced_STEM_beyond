#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b, ans = 1;
	cin >> a >> b;
	int m = min(a, b);
	for (int i = 2; i <= m; ++i) ans *= i;
	cout << ans;
}