#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
	double l = 0;
	for (int i = 1; i < n; ++i) {
		int X = x[i] - x[i - 1], Y = y[i] - y[i - 1];
		l += sqrt(X * X + Y * Y);
	}
	cout << fixed << setprecision(10) << k * l / 50;
}