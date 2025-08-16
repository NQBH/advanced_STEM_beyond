#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	int r = -1, sum = 0, ans = 0;
	for (int l = 0; l < n; sum -= a[l++]) {
		while (r + 1 < n && sum + a[r + 1] <= t) sum += a[++r];
		ans = max(ans, r - l + 1);
	}
	cout << ans << '\n';
}