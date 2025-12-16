#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k, m;
	cin >> n >> k >> m;
	vector<ll> a(n + 1), c(k + 1);
	for (int i = 0; i < k; ++i) cin >> a[i]; // input initial values a_0, a_1,..., a_{k - 1}
	for (int i = 1; i <= k; ++i) cin >> c[i]; // input constant coefficients c_1, c_2,..., c_k
	for (int i = k; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) a[i] += c[j] * a[i - j];
		a[i] %= m;
	}
	cout << a[n] << '\n';
}