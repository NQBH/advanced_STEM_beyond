#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long S = 0;
		cin >> n;
		vector<int> b(n);
		for (int &x : b) {
			cin >> x;
			S += x;
		}
		if (S == n) {
			cout << "1\n";
			continue;
		}
		sort(b.begin(), b.end());
		int i;
		for (i = 0; i < n; ++i)
			if (b[i]) break;
		int n_non0 = n - i;
		if (S - n + 1 >= n_non0) cout << n - i << '\n';
		else cout << S - n + 1 << '\n';		
	}
}