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
		vector<int> b(n - 2);
		for (int &x : b) cin >> x;
		bool ans = true;
		for (int i = 1; i < n - 3; ++i)
			if (b[i - 1] && !b[i] && b[i + 1]) {
				ans = false;
				break;
			}
		cout << (ans ? "YES\n" : "NO\n");
	}
}