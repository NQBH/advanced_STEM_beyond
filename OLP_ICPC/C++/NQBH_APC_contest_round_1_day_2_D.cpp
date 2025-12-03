#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, M;
	cin >> n >> M;
	vector<int> a(n), dpmin(M + 1, 1e9), dpmax(M + 1, -1);
	dpmin[0] = 0;
	dpmax[0] = 0;
	for (int &x : a) cin >> x;
	int g = a[0];
	for (int i = 1; i < n; ++i) g = gcd(g, a[i]);
	if (M % g != 0) cout << "-1";
	else {
		for (int i = 0; i < n; ++i)
			for (int j = a[i]; j <= M; ++j) {
				if (dpmin[j - a[i]] != 1e9) dpmin[j] = min(dpmin[j], dpmin[j - a[i]] + 1);
				if (dpmax[j - a[i]] != -1) dpmax[j] = max(dpmax[j], dpmax[j - a[i]] + 1);
			}
		if (dpmin[M] == 1e9 || dpmax[M] == -1) cout << "-1\n";
		else cout << dpmin[M] << ' ' << dpmax[M] << '\n';
	}
}