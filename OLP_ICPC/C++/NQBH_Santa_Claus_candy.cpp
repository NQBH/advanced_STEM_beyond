#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k = 1;
	cin >> n;
	while (k * (k + 1) < 2 * n) ++k;
	if (k * (k + 1) == 2 * n) {
		cout << k << '\n';
		for (int i = 1; i <= k; ++i) cout << i << " \n"[i == k];
	} else {
		cout << k - 1 << '\n';
		for (int i = 1; i < k - 1; ++i) cout << i << ' ';
		cout << n - (k - 2) * (k - 1) / 2 << '\n';
	}
}