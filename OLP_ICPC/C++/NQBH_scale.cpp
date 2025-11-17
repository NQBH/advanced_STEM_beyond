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
		vector<string> s(n);
		for (string &x : s) cin >> x;
		for (int i = 0; i < n; i += k) {
			for (int j = 0; j < n; j += k)
				cout << s[i][j];
			cout << '\n';
		}
	}
}