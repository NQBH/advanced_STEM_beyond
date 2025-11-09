#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> f(n + 1);
	for (int i = 1; i <= n; ++i) cin >> f[i];
	for (int i = 1; i <= n; ++i)
		if (f[f[f[i]]] == i) {
			cout << "YES\n";
			return 0;
		}
	cout << "NO\n";
}