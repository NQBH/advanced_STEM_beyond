#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		string s;
		cin >> s;
		s = '0' + s;
		for (int i = 0; i < n; ++i)
			if (s[i] != s[i + 1]) ++ans;
		cout << ans << '\n';		
	}
}