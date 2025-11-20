#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		if (a[0] == a[n - 1]) cout << "NO\n";
		else {
			cout << "YES\n";
			string s(n, 'R');
			s[1] = 'B';
			cout << s << '\n';
		}
	}
}