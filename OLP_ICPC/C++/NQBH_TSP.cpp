#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> x(n + 1, 0), y(n + 1, 0);
		for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
		cout << 2 * (*max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end()) + *max_element(y.begin(), y.end()) - *min_element(y.begin(), y.end())) << '\n';
	}
}