#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k, x;
		cin >> n >> k >> x;
		vector<int> a(n);
		for (int &i : a) cin >> i;
		a.push_back(-1e9);
		a.push_back(1e9);
		n += 2;
		sort(a.begin(), a.end());
        int l = 0, r = x + 1;
        while (l + 1 < r) {
        	int m = (l + r) >> 1, f = 0;
        	a[0] = -m, a[n - 1] = x + m;
        	for (int i = 1; i < n; ++i) f += max(0, (a[i] - m) - (a[i - 1] + m) + 1);
        	if (f >= k) l = m;
        	else r = m;
        }
        a[0] = -l, a[n - 1] = x + l;
        int j = 0;
        for (int i = 1; i < n; ++i)
        	for (j = max(j, a[i - 1] + l); j <= min((a[i] - l), x) &&k; ++j)
        		cout << j << ' ', k--;
        cout << '\n';
	}
}