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
		vector<int> a(n + 1);
		for (int i = 1; i <= n; ++i) cin >> a[i];
		if (a[1]) {
			cout << n + 1 << ' ';
			for (int i = 1; i <= n; ++i) cout << i << " \n"[i == n];
		}
		else if (!a[n])
			for (int i = 1; i <= n + 1; ++i) cout << i << " \n"[i == n + 1];
		else {
			for (int i = 1; i < n; ++i) {
				if (!a[i] && a[i + 1]) {
					for (int j = 1; j <= i; ++j) cout << j << ' ';
					cout << n + 1 << ' ';
					for (int j = i + 1; j <= n; ++j) cout << j << " \n"[j == n];
					break;
				}
			}
		}	
	}
}