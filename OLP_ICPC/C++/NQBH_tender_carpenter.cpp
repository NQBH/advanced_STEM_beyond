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
		bool stable = false;
		for (int i = 0; i < n - 1; ++i) {
			if (a[i] == a[i + 1]) {
				stable = true;
				break;
			} else if (a[i] < a[i + 1] && 2 * a[i] > a[i + 1]) {
				stable = true;
				break;
			} else if (a[i] > a[i + 1] && a[i] < 2 * a[i + 1]) {
				stable = true;
				break;
			}
		}
		cout << (stable ? "YES\n" : "NO\n");
	}
}