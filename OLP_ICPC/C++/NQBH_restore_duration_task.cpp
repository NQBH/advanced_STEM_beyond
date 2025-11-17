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
		vector<int> s(n), f(n);
		for (int &x : s) cin >> x;
		for (int &x : f) cin >> x;
		cout << f[0] - s[0] << ' ';
		int time = f[0];
		for (int i = 1; i < n; ++i) {
			if (time <= s[i]) {
				cout << f[i] - s[i] << ' ';
				time = f[i];
			} else if (time < f[i]) {
				cout << f[i] - time << ' ';
				time = f[i];
			} else cout << "0 ";
		}
		cout << '\n';
	}
}