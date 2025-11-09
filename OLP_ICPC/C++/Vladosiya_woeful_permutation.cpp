#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n % 2 == 0) {
			for (int i = 1; i <= n; i += 2) cout << i + 1 << ' ' << i << ' ';
			cout << nl;
		} else {
			cout << 1 << ' ';
			for (int i = 2; i <= n; i += 2) cout << i + 1 << ' ' << i << ' ';
			cout << nl;
		}
	}
}