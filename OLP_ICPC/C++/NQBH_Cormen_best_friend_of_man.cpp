#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k, add = 0;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	for (int i = 1; i < n; ++i)
		if (a[i - 1] + a[i] < k) {
			add += k - a[i - 1] - a[i];
			a[i] = k - a[i - 1];
		} 
	cout << add << '\n';
	for (int x : a) cout << x << ' ';
}