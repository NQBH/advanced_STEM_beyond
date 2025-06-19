#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n) {
		if (n == -1)
			break;
		ll f = 1, m = 0;
		for (int i = 1; i <= n; ++i) {
			ll tmp = m;
			m += f;
			f = tmp + 1;
		}
		cout << m << ' ' << m + f << '\n';
	}
	return 0;
}