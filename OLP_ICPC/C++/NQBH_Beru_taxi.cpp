#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b, n;
	double ans = 1e9;
	cin >> a >> b >> n;
	vector<int> x(n), y(n), v(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i] >> v[i];
		int m = x[i] - a, n = y[i] - b;
		double d = sqrt(m * m + n * n);
		ans = min(ans, d / v[i]);
	}
	cout << fixed << setprecision(20) << ans;
}