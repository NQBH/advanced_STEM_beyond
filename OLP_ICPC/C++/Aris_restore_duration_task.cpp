#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for (int i = 0; i < int(n); ++i)

void solve() {
	int n;
	cin >> n;
	int s[n], f[n];
	for (int i = 0; i < n; ++i) cin >> s[i];
	for (int i = 0; i < n; ++i) cin >> f[i];
	int curTime = 0;
	int d[n];
	for (int i = 0; i < n; ++i) {
		curTime = max(curTime, s[i]);
		d[i] = f[i] - curTime;
		curTime = f[i];
	}
	for (auto now : d) cout << now << " ";
	cout << '\n';
}

int main() {
	int tests;
	cin >> tests;
    forn(tt, tests) solve();
}