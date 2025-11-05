#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		int ans = 0;
		string p = s;
		sort(p.begin(), p.end());
		for (int i = 0; i < n; ++i) if (s[i]!= p[i]) ++ans;
		cout << ans / 2 << '\n';
	}
}