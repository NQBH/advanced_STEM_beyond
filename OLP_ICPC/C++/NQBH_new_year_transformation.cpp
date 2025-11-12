#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	for (int i = 1; i < n; ++i) cin >> a[i];
	int x = 1;
	while (x < t) x += a[x];
	if (x == t) cout << "YES";
	else cout << "NO";
}