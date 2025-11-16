#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair
mt19937 rnd(time(0));
int a[105];

void solve() {
	int q, k, n;
	cin >> k >> q;
	for (int i = 1; i <= k; ++i) cin >> a[i];
	for (int i = 1; i <= q; ++i) {
		cin >> n;
		cout << min(a[1] - 1, n) << ' ';
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	int _;
	cin >> _;
	while (_--) solve();
}