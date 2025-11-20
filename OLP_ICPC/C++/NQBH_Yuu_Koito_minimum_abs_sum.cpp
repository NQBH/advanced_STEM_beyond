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
		if (a[0] != -1 && a[n - 1] != -1) {
			cout << abs(a[0] - a[n - 1]) << '\n';
			for (int i = 0; i < n; ++i) {
				if (a[i] != -1) cout << a[i] << ' ';
				else cout << "0 ";
			}
			cout << '\n';
		} else if (a[0] == -1 && a[n - 1] != -1) {
			cout << "0\n";
			cout << a[n - 1] << ' ';
			for (int i = 1; i < n; ++i) {
				if (a[i] != -1) cout << a[i] << ' ';
				else cout << "0 ";
			}
			cout << '\n';
		} else if (a[0] != -1 && a[n - 1] == -1) {
			cout << "0\n";
			for (int i = 0; i < n - 1; ++i) {
				if (a[i] != -1) cout << a[i] << ' ';
				else cout << "0 ";
			}
			cout << a[0] << '\n';
		} else {
			cout << "0\n";
			for (int i = 0; i < n; ++i) {
				if (a[i] != -1) cout << a[i] << ' ';
				else cout << "0 ";
			}
			cout << '\n';
		}
	}
}