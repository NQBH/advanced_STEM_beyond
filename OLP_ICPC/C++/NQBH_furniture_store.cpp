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
			cout << "0\n\n";
			continue;
		}
		vector<int> ans;
		int mn = a[0];
		for (int i = 1; i < n; ++i)
			if (a[i] > mn) ans.push_back(i + 1);
			else mn = a[i];
		if (ans.empty()) cout << "0\n\n";
		else {
			cout << ans.size() << '\n';
			for (int &x : ans) cout << x << ' ';
			cout << '\n';
		}
	}
}