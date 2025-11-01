#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 1, S = 1;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		for (int i = 1; i < n; ++i) {
			S += a[i];
			int s = sqrt(S);
			if (s * s == S && s & 1) ++ans;
		}
		cout << ans << '\n';		
	}
}