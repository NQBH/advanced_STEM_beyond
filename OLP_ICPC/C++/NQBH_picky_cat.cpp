#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, lma = 0, ga = 0; // number of i s.t. a[i] < -|a[0]| & a[i] > |a[0]|
		cin >> n;
		if (n == 1) {
			cout << "YES\n";
			continue;
		}
		bool ok = false;
		int l = (n - 1) / 2;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		int A = abs(a[0]), B = -A;
		for (int i = 1; i < n; ++i) {
			if (a[i] > A || a[i] < B) ++lma;
			else if (a[i] < A || a[i] > B) ++la;
			if (la >= l || lma >= l) {
				ok = true;
				break;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}