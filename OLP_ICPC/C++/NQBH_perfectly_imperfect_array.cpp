#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		bool ok = 0;
		for (int x : a) {
			int sq = sqrt(x);
			if (sq * sq != x) {
				ok = 1;
				break;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}