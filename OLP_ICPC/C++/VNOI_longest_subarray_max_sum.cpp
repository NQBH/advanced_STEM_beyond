#include <iostream>
using namespace std;

int main() {
	int n, s, ans = 0, sum = 0;
	cin >> n >> s;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int l = 1, r = 1; r <= n; ++r) {
		sum += a[r];
		while (sum > s) sum -= a[l++];
		ans = max(ans, r - l + 1);
	}
	cout << ans;
}