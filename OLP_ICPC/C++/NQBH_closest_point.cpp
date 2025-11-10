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
		vector<int> x(n);
		for (int &i : x) cin >> i;
		if (n > 2 || x[1] == x[0] + 1) cout << "NO\n";
		else cout << "YES\n";
	}
}