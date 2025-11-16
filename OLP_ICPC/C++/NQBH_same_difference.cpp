#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		string s;
		cin >> n >> s;
		for (int i = n - 2; i >= 0; --i)
			if (s[i] != s[n - 1]) ++ans;
		cout << ans << '\n';
	}
}