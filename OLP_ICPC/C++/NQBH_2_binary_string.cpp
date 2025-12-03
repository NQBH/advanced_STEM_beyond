#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		int n = a.size();
		if (a == b) {
			cout << "YES\n";
			continue;
		}
		bool ok = false;
		for (int i = 0; i < n - 1; ++i)
			if (a[i] == '0' && b[i] == '0' && a[i + 1] == '1' && b[i + 1] == '1') {
				ok = true;
				break;
			}
		cout << (ok ? "YES\n" : "NO\n");
	}
}