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
		int pos_min = min_element(a.begin(), a.end()) - a.begin();
		int mn = *min_element(a.begin(), a.end());
		if (mn > 2 * pos_min && mn > 2 * (n - 1 - pos_min)) cout << "YES\n";
		else cout << "NO\n";
	}
}
// WA test 2