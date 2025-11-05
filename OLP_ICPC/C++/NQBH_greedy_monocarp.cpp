#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		int S = accumulate(a.begin(), a.end(), 0);
		if (S == k) cout << "0\n";
		else if (S < k) cout << k - S << '\n';
		else {
			sort(a.begin(), a.end(), greater<int>());
			int M = 0; // total coins M has taken
			for (int i = 0; i < n; ++i) {
				if (M + a[i] > k) break;
				else M += a[i];
			}
			cout << k - M << '\n';
		}
	}
}