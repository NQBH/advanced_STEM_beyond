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
		vector<int> a(n);
		for (int &x : a) cin >> x;
		if (n == 1) {
			cout << "1\n";
			continue;
		}
		vector<int> b;
		b.push_back(a[0]);
		for (int i = 1; i < n; ++i)
			if (a[i] != a[i - 1]) b.push_back(a[i]);
		int m = b.size();
		vector<int> dp0(m), dp1(m); // dp0[i] = maximum number of arrays upto i if remove a[i], dp1[i] = maximum number of arrays upto i if keep a[i]
		if (m == 1) {
			cout << "1\n";
			continue;
		}
		dp0[0] = 0, dp1[0] = 1, dp0[1] = 1;
		if (b[1] > b[0] + 1) dp1[1] = 2;
		else dp1[1] = 1;		
		for (int i = 1; i < m; ++i) {
			dp0[i] = max(dp0[i - 1], dp1[i - 1]);
			// taken b[i - 1]
			if (b[i] > b[i - 1] + 1) dp1[i] = dp1[i - 1] + 1;
			else dp1[i] = dp1[i - 1];
			// not taken b[i - 1]
			dp1[i] = max(dp1[i], dp0[i - 1] + 1); 
		}
		cout << max(dp0[m - 1], dp1[m - 1]) << '\n';
	}
}