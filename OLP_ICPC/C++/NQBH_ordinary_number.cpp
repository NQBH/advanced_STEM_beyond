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
		if (n < 10) cout << n << '\n';
		else {
			string s = to_string(n);
			int ans = 9 * (s.size() - 1) + (s[0] - '0' - 1);
			if (n >= (pow(10, s.size()) - 1) / 9 * (s[0] - '0')) ++ans;
			cout << ans << '\n'; 
		}		
	}
}