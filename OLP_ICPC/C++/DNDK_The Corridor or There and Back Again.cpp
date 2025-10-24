#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long ans = 1e18;
		for (int i = 0; i < n; i++) {
			long long d, s;
			cin >> d >> s;
			long long k = d + (s - 1) / 2;
			ans = min(ans, k);
		}
		cout << ans << endl;
	}
}
