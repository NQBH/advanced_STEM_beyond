#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		if (accumulate(a.begin(), a.end(), 0) == n * x) cout << "YES\n";
		else cout << "NO\n";
	}
}