#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 105;
int t, n, a[MAX_N];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		int max_value = 0;
		for (int i = 1; i <= n; i += 2)
			max_value = max(max_value, a[i]);
		cout << max_value << '\n';
	}
}