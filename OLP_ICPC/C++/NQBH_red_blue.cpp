#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n;
		vector<int> r(n);
		for (int &x : r) cin >> x;
		cin >> m;
		vector<int> b(m);
		for (int &x : b) cin >> x;
		int max_sum_r = r[0], max_sum_b = b[0];
		vector<int> psumr(n, 0), psumb(m, 0);
		psumr[0] = r[0], psumb[0] = b[0];
		for (int i = 1; i < n; ++i) {
			psumr[i] = psumr[i - 1] + r[i];
			if (psumr[i] > max_sum_r) max_sum_r = psumr[i];
		}
		for (int i = 1; i < m; ++i) {
			psumb[i] = psumb[i - 1] + b[i];
			if (psumb[i] > max_sum_b) max_sum_b = psumb[i];
		}
		cout << max(0, max_sum_r) + max(0, max_sum_b) << '\n';
	}
}