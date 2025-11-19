#include <bits/stdc++.h>
using ll = signed long long int;
using namespace std;

void solve() {
	ll n, a, b;
	cin >> n >> a >> b;
	ll ans = n * a;
	if (b < 2 * a) ans = (n / 2) * b + (n % 2) * a;
	cout << ans << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}