#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a & 1) cout << "NO\n";
		else {
			if (b & 1) {
				if (a) cout << "YES\n";
				else cout << "NO\n";
			} else cout << "YES\n";
		}
	}
}